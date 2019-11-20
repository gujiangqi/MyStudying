#include "CCtrlFile.h"

extern short g_CtxNo;
extern int g_AppNo;
extern int g_IsDuty;
extern char g_AppName[32];
extern char g_CtxName[64];
extern char g_ProcName[64];

CCtrlFile::CCtrlFile()
{
    //�����ļ��Ķ�ȡĿ¼������Ŀ¼������Ŀ¼������ʵ������޸�
    sprintf(m_readFilePath, "%s/var/ctrlfile/recv", getenv("D5000_HOME"));
    sprintf(m_backupSuccessFilePath, "%s/var/ctrlfile/backup/success", getenv("D5000_HOME"));
    sprintf(m_backupFailFilePath, "%s/var/ctrlfile/backup/fail", getenv("D5000_HOME"));
    sprintf(m_sendFilePath, "%s/var/ctrlfile/send", getenv("D5000_HOME"));

    char cmd[200];
    DIR *pDir;  // �ṹ��ָ��

    pDir = opendir(m_readFilePath);
    if (!pDir)
    {
        sprintf(cmd, "mkdir -p %s", m_readFilePath);
        system(cmd);
    }
    closedir(pDir);

    pDir = opendir(m_backupSuccessFilePath);
    if (!pDir)
    {
        sprintf(cmd, "mkdir -p %s", m_backupSuccessFilePath);
        system(cmd);
    }
    closedir(pDir);

    pDir = opendir(m_backupFailFilePath);
    if (!pDir)
    {
        sprintf(cmd, "mkdir -p %s", m_backupFailFilePath);
        system(cmd);
    }
    closedir(pDir);

    pDir = opendir(m_sendFilePath);
    if (!pDir)
    {
        sprintf(cmd, "mkdir -p %s", m_sendFilePath);
        system(cmd);
    }
    closedir(pDir);

    m_model_client = new modify_client_base();

    int ret_code = m_messageBus.messageInit(g_CtxName, g_AppName, g_ProcName); //��Ϣ���߳�ʼ��
    if (ret_code <= 0)
    {
        TRACE("messageInit() error!\n");
    }
    else
    {
        TRACE("messageInit success!\n");
    }

    ret_code = m_messageBus.messageSubscribe(CH_IES_SCA_TRANS_CTRL); //��Ϣ����
    if (ret_code != 1)
    {
        TRACE("messageSubscribe() is error!\n");
    }

    m_devTableOp = new CTableOp();
    ret_code = m_devTableOp->Open(g_AppNo, DMS_VALUE_INFO_NO);
    if (ret_code != DB_OK)
    {
        TRACE("open table DMS_VALUE_INFO_NO error!\n");
    }

    m_transTableNet = new CTableNet();

    m_vecCtrlFileInfo.clear();
    m_vecMsgDataRec.clear();
    m_devValue = 0;
}

CCtrlFile::~CCtrlFile()
{
    if (m_model_client != NULL)
    {
        delete m_model_client;
        m_model_client = 0;
    }

    if (m_devTableOp != NULL)
    {
        delete m_devTableOp;
        m_devTableOp = 0;
    }

    if (m_transTableNet != NULL)
    {
        delete m_transTableNet;
        m_transTableNet = 0;
    }
}

//�����ļ�������
void CCtrlFile::ctrlFileProcess()
{
    TRACE("ctrlFileProcess start----------------\n");

    m_vecCtrlFileInfo.clear();

    /* m_readfilepath�������ȡ�� */
    QDir dir(m_readFilePath);

    //��ȡĿ¼�������ļ�
    /*  QFileInfoList ��һ��vector Ԫ�����ļ���Ϣ�� */
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files);
    QFileInfoList::Iterator fileIter = fileInfoList.begin();

    cout << "QFileInfoList size is: " << fileInfoList.size() << endl;

    while (fileIter != fileInfoList.end())
    {
        char command[200];
        QString strFileName = fileIter->fileName();
        string strTempName = strFileName.toStdString();

        //��ȡ�ļ����е���Ϣ
        getInfoFromFileName(strFileName);

        /*
        //�ж��ļ�ʱ���Ƿ�Ϊ����
        cur_time = time(NULL);
        if( (cur_time-cur_time%86400) != (m_fileTime-m_fileTime%86400) )
        {
            TRACE("file time is not today!\n");

            sprintf(char_cmd, "mv %s/%s %s", m_readFilePath, file_name, m_backupFailFilePath);
            cout<<char_cmd<<endl;
            system(char_cmd);

            return;
        }
        */

        //�������ƽ����ļ�
        if (parseCtrlFile(strTempName.c_str()) >= 0)
        {
            sprintf(command, "mv %s/%s %s", m_readFilePath, strTempName.c_str(), m_backupSuccessFilePath);
            cout << command << endl;
            system(command);
        }
        else
        {
            sprintf(command, "mv %s/%s %s", m_readFilePath, strTempName.c_str(), m_backupFailFilePath);
            cout << command << endl;
            system(command);

            return;
        }

        if (m_vecCtrlFileInfo.size())
        {
            int ret_code = modifyTable(); //�޸ı�
            if (ret_code == 0)
            {
                TRACE("modify table IES_SCA_CTRLTRANSINFO  success!\n");

                //������Ϣ
                ret_code = sendMessage(MT_IES_SCA_TRANS_CTRL_REQUEST);
            }
        }

        ++fileIter;
    }

    TRACE("ctrlFileProcess end----------------\n");

    return;
}

//��Ϣ����
int CCtrlFile::recvMessage()
{
    if (g_IsDuty != 1)
    {
        return 0;
    }

    Message msg_rec;
    int ret_code;


    /* 
     * messageRecv:��Ϣ���ճ�Ա����
     * msgrec:�����Ϣ�ı���

     */
    ret_code = m_messageBus.messageReceive(&msg_rec, NULL, false);
    if (ret_code > 0 && msg_rec.header.event == MT_IES_SCA_TRANS_CTRL_SEND)
    {
        TRACE("recvMessage()!!!!!!!!!!!!!\n");

        char *send_buf;
        int buf_size;
        CtrlTransPkg struCtrlTransPkg;
        MsgDataRec_STRU struMsgDataRec;

        m_vecMsgDataRec.clear();

        buf_size = msg_rec.header.len;

        cout << "msg_rec.header.len = " << msg_rec.header.len << endl;

        send_buf = (char *)malloc(buf_size);
        memcpy(send_buf, msg_rec.Msg_buf, buf_size);
        M_DECODE(struCtrlTransPkg, send_buf, buf_size);

        free(send_buf);
        send_buf = NULL;

        cout << "data_num = " << struCtrlTransPkg.data_num << endl;
        cout << "data_info_seq size = " << struCtrlTransPkg.data_info_seq.size();

        if (struCtrlTransPkg.data_num != struCtrlTransPkg.data_info_seq.size())
        {
            return -1;
        }

        for (int i = 0; i < struCtrlTransPkg.data_num; i++)
        {

            struMsgDataRec.create_time = struCtrlTransPkg.data_info_seq[i].create_time;
            struMsgDataRec.file_type = struCtrlTransPkg.data_info_seq[i].file_type;
            struMsgDataRec.interval_type = struCtrlTransPkg.data_info_seq[i].interval_type;

            m_vecMsgDataRec.push_back(struMsgDataRec);

            cout << "struCtrlTransPkg.data_info_seq[i].create_time = " << struCtrlTransPkg.data_info_seq[i].create_time << endl;
            cout << "struCtrlTransPkg.data_info_seq[i].file_type = " << struCtrlTransPkg.data_info_seq[i].file_type << endl;
            cout << "struCtrlTransPkg.data_info_seq[i].interval_type = " << struCtrlTransPkg.data_info_seq[i].interval_type << endl;
        }

        return ret_code;
    }

    return 0;
}

void CCtrlFile::readCtrlTransRecords()
{
    if (m_vecMsgDataRec.empty())
    {
        return;
    }

    m_mapResInfo.clear();

    int ret_code;
    int fileType;
    int intervalType;
    ResInfo_STRU struResInfo;

    ret_code = m_transTableNet->Open(g_AppNo, IES_SCA_CTRLTRANSINFO_NO);
    if (ret_code != DB_OK)
    {
        TRACE("open table IES_SCA_CTRLTRANSINFO_NO error!\n");
        return;
    }

    for (int i = 0; i < m_vecMsgDataRec.size(); i++)
    {
        fileType = m_vecMsgDataRec[i].file_type;
        

        /* 
         * ʵʱ�����ݰ�������ѯ
         */
        ret_code = m_transTableNet->TableGetByKey((char *)&m_vecMsgDataRec[i], CTRL_TRANS_RES_INFO_SQL, (char *)&struResInfo, sizeof(ResInfo_STRU));
        if (ret_code < 0)
        {
            TRACE("TableGetByKey() error!\n");
            continue;
        }

        intervalType = m_vecMsgDataRec[i].interval_type;
        m_mapResInfo[intervalType] = struResInfo;

        cout << "intervalType = " << intervalType << endl;
        cout << "m_mapResInfo size() is " << m_mapResInfo.size() << endl;
    }

    return;
}

void CCtrlFile::createCtrlTransFile()
{
    if (m_mapResInfo.empty())
    {
        return;
    }

    char fileName[100];
    char fileNameWithDir[200];
    char fileTime[20];
    char fileType[20];
    char command[200];
    int intervalType;
    struct tm *cur_time_tm;

    QString strFileNameWithDir;
    QString strFileTime;
    QString strIntervalType;
    QString strFileType;
    QDomDocument domDoc;

    ResInfo_STRU struResInfo;

    //ɾ��Ŀ¼�������ļ�
    sprintf(command, "rm %s/*.xml \n", m_sendFilePath);
    cout << command << endl;
    system(command);

    //��ȡ�ļ�ʱ��
    cur_time_tm = localtime(&m_vecMsgDataRec[0].create_time);
    //��ȡ�ļ�����
    if (m_vecMsgDataRec[0].file_type == 1)
    {
        strcpy(fileType, "ANSWER");
    }

    //����ȫ·���ļ���
    sprintf(fileName, "%s_%s_to_%s_%04d%02d%02d%02d%02d%02d.xml",
            fileType, "IES", "EMS", cur_time_tm->tm_year + 1900, cur_time_tm->tm_mon + 1, cur_time_tm->tm_mday, cur_time_tm->tm_hour, cur_time_tm->tm_min, cur_time_tm->tm_sec);
    sprintf(fileNameWithDir, "%s/%s", m_sendFilePath, fileName);
    TRACE("fime name is %s\n", fileNameWithDir);

    strFileNameWithDir = QString(QLatin1String(fileNameWithDir));

    QFile file(strFileNameWithDir);
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
    {
        TRACE("open file error!\n");
        return;
    }

    //���xml�ļ�����
    QDomProcessingInstruction domInstruction;
    domInstruction = domDoc.createProcessingInstruction("xml", "version='1.0' encoding='UTF-8'");
    domDoc.appendChild(domInstruction);

    //��Ӹ��ڵ�
    QDomElement domRoot = domDoc.createElement("system");
    domDoc.appendChild(domRoot);

    //��Ӹ��ڵ�����
    sprintf(fileTime, "%04d-%02d-%02d %02d:%02d:%02d", cur_time_tm->tm_year + 1900, cur_time_tm->tm_mon + 1, cur_time_tm->tm_mday, cur_time_tm->tm_hour, cur_time_tm->tm_min, cur_time_tm->tm_sec);
    strFileTime = QString(QLatin1String(fileTime));
    strFileType = QString(QLatin1String(fileType));
    domRoot.setAttribute("type", strFileType);
    domRoot.setAttribute("name", "IES");
    domRoot.setAttribute("dateTime", strFileTime);

    //����ӽڵ�check
    QDomElement domCheck = domDoc.createElement("check");
    domRoot.appendChild(domCheck);

    //���check�ڵ�����MD5��ֵ

    //ȷ��ʱ����
    map<int, ResInfo_STRU>::iterator iter;
    for (iter = m_mapResInfo.begin(); iter != m_mapResInfo.end(); iter++)
    {
        intervalType = iter->first;
        struResInfo = iter->second;

        cout << "create file intervalType = " << intervalType << endl;

        switch (intervalType)
        {
        case INTERVAL_TYEP_1S_15MIN:
            strIntervalType = "_1s_15min";
            break;
        case INTERVAL_TYEP_15MIN_30MIN:
            strIntervalType = "_15min_30min";
            break;
        case INTERVAL_TYEP_30MIN_2H:
            strIntervalType = "_30min_2h";
            break;
        case INTERVAL_TYEP_2H_MORE:
            strIntervalType = "_2h_more";
            break;
        case INTERVAL_TYEP_1S_LESS:
            strIntervalType = "_1s_less";
            break;
        default:
            break;
        }

        //���ʱ�����ӽڵ�
        QDomElement domChild = domDoc.createElement(strIntervalType);
        domRoot.appendChild(domChild);

        //��ӵ��ڿ�ʼʱ������
        struct tm *startTime_tm;
        char startTime[20];
        QString strStartTime;

        startTime_tm = localtime(&struResInfo.start_time);
        sprintf(startTime, "%04d-%02d-%02d %02d-%02d-%02d", startTime_tm->tm_year + 1900, startTime_tm->tm_mon + 1, startTime_tm->tm_mday, startTime_tm->tm_hour, startTime_tm->tm_min, startTime_tm->tm_sec);
        strStartTime = QString(QLatin1String(startTime));

        domChild.setAttribute("startTime", strStartTime);

        //���ԣ����Ϣ�ӽڵ�
        //�ϵ�
        QDomElement domResUp = domDoc.createElement("res_up");
        domChild.appendChild(domResUp);
        //�������
        domResUp.setAttribute("res_up_value", struResInfo.res_up_value);
        domResUp.setAttribute("res_up_time", (int)struResInfo.res_up_time);
        domResUp.setAttribute("res_up_price", (int)struResInfo.res_up_price);

        //�ϵ�
        QDomElement domResDown = domDoc.createElement("res_down");
        domChild.appendChild(domResDown);
        //�������
        domResDown.setAttribute("res_down_value", struResInfo.res_down_value);
        domResDown.setAttribute("res_down_time", (int)struResInfo.res_down_time);
        domResDown.setAttribute("res_down_price", (int)struResInfo.res_down_price);
    }

    //������ļ�
    QTextStream textStream(&file);
    domDoc.save(textStream, 4);
    file.close();

    return;
}

void CCtrlFile::deleteBackupFiles()
{
    TRACE("removeBackupFiles start------------\n");

    deleteFilesByPath(m_backupSuccessFilePath);
    deleteFilesByPath(m_backupFailFilePath);
    //deleteFilesByPath(m_sendFilePath);

    return;
}

int CCtrlFile::parseCtrlFile(char *fileName)
{
    TRACE("parseCtrlFile start-------------\n");
    bool bRetFlag = false;
    int nFileType = 0;
    char fileNameWithDir[100];

    time_t date_time;
    QString strFileName;
    QString strError;
    QString strText;
    QDomDocument document;

    m_vecCtrlFileInfo.clear();

    sprintf(fileNameWithDir, "%s/%s", m_readFilePath, fileName);
    strFileName = QString(QLatin1String(fileNameWithDir));

    TRACE("parseCtrlFile start !!!!!!!!!!!!!!!!\n");

    //���ļ�
    QFile file(strFileName);
    bRetFlag = document.setContent(&file, true, &strError);
    if (bRetFlag == false)
    {
#ifndef WIN32
        TRACE("��ȡ�ļ���%sʧ��! \n", fileName);
        TRACE("strError is %s \n", strError.toLocal8Bit().data());
#endif
        return -1;
    }

    //�ر��ļ�
    file.close();

    //���ظ��ڵ�
    QDomElement domRoot = document.documentElement();
    cout << "���ڵ㣺 " << domRoot.nodeName().toLocal8Bit().data() << endl;

    //��ȡ���ڵ�����
    strText = domRoot.attribute("name");
    cout << "����name�� " << strText.toLocal8Bit().data() << endl;
    if (abs(strText.compare(m_strfileSource)))
    {
        TRACE("file source error!\n");
        return -1;
    }

    if (abs(m_strfileDestination.compare("IES")))
    {
        TRACE("file destination is not IES!\n");
        return -1;
    }

    //��ȡtype����
    strText = domRoot.attribute("type");
    cout << "����type�� " << strText.toLocal8Bit().data() << endl;
    if (abs(strText.compare(m_strfileType)))
    {
        TRACE("file type error!\n");
        return -1;
    }

    if (!strText.compare("REQUEST")) //��������
    {
        nFileType = CTRL_TYPE_REQUEST;
    }
    else if (!strText.compare("CONFIRM"))
    {
        nFileType = CTRL_TYPE_CONFIRM;
    }
    else
    {
        return -1;
    }

    //��ȡdateTime����
    strText = domRoot.attribute("dateTime");
    cout << "����dateTime�� " << strText.toLocal8Bit().data() << endl;
    getTimeFromDomText(strText.toLocal8Bit().data(), date_time);

    /*
    if(date_time != m_fileTime)
    {
        TRACE("date_time is not equal file time\n");
        return -1;
    }
    */

    //��ȡ���ڵ��һ���ֽڵ�
    QDomElement domChild = domRoot.firstChildElement("check");
    cout << "���ڵ���ӽڵ㣺 " << domChild.nodeName().toLocal8Bit().data() << endl;
    if (!domChild.isNull())
    {
        strText = domChild.attribute("value");
        cout << "�ӽڵ�check���ԣ� " << strText.toLocal8Bit().data() << endl;
    }
    else
    {
        return -1;
    }

    //��ȡ��һ���ֵܽڵ�
    domChild = domChild.nextSiblingElement();

    while (!domChild.isNull())
    {
        cout << "nextSiblingElement ------------" << endl;
        ResInfo_STRU struResInfo;
        memset(&struResInfo, 0, sizeof(ResInfo_STRU));
        bRetFlag = getFieldValueByElement(domChild, struResInfo);
        if (bRetFlag == true)
        {
            CtrlFileInfo_STRU struCtrlTransInfo;
            memset(&struCtrlTransInfo, 0, sizeof(CtrlFileInfo_STRU));
            struCtrlTransInfo.create_time = time(NULL);
            struCtrlTransInfo.file_type = nFileType;
            strcpy(struCtrlTransInfo.file_source, m_strfileSource.toStdString().c_str());
            strcpy(struCtrlTransInfo.file_destination, m_strfileDestination.toStdString().c_str());
            struCtrlTransInfo.data_interval_type = struResInfo.data_interval_type;
            struCtrlTransInfo.start_time = struResInfo.start_time;
            struCtrlTransInfo.res_up_value = struResInfo.res_up_value;
            struCtrlTransInfo.res_up_time = struResInfo.res_up_time;
            struCtrlTransInfo.res_up_price = struResInfo.res_up_price;
            struCtrlTransInfo.res_down_value = struResInfo.res_down_value;
            struCtrlTransInfo.res_down_time = struResInfo.res_down_time;
            struCtrlTransInfo.res_down_price = struResInfo.res_down_price;
            struCtrlTransInfo.record_app = 32767;
            struCtrlTransInfo.record_app3 = 32767;

            m_vecCtrlFileInfo.push_back(struCtrlTransInfo);
        }

        //��ȡdomChild���ֵܽڵ�
        domChild = domChild.nextSiblingElement();
    }

    return 1;
}

void CCtrlFile::getInfoFromFileName(QString &fileName)
{
    int index;
    QString fileNameTemp;
    QString strTime;
    QStringList strList;
    struct tm tm_time;

    index = fileName.indexOf(".");
    fileNameTemp = fileName.left(index);

    strList = fileNameTemp.split("_");

    m_strfileType = strList.at(0);
    m_strfileSource = strList.at(1);
    m_strfileDestination = strList.at(3);

    strTime = strList.at(4);

    sscanf(strTime.toStdString().c_str(), "%4d%02d%02d%02d%02d%02d", &tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
           &tm_time.tm_hour, &tm_time.tm_min, &tm_time.tm_sec);

    tm_time.tm_year = tm_time.tm_year - 1900;
    tm_time.tm_mon = tm_time.tm_mon - 1;

    m_fileTime = mktime(&tm_time);

    cout << "fileType is: " << m_strfileType.toStdString().c_str() << endl;
    cout << "fileSource is: " << m_strfileSource.toStdString().c_str() << endl;
    cout << "fileDestination is: " << m_strfileDestination.toStdString().c_str() << endl;
    cout << "fileTime is: " << m_fileTime << endl;

    return;
}


void CCtrlFile::getTimeFromDomText(char *domText, time_t &start_time)
{

    struct tm tm_time;

    sscanf(domText, "%4d-%02d-%02d %02d:%02d:%02d", &tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
           &tm_time.tm_hour, &tm_time.tm_min, &tm_time.tm_sec);

    cout << "domText time is: " << tm_time.tm_year << " " << tm_time.tm_mon << " " << tm_time.tm_mday << " " << tm_time.tm_hour << " " << tm_time.tm_min << " " << tm_time.tm_sec << endl;

    tm_time.tm_year = tm_time.tm_year - 1900;
    tm_time.tm_mon = tm_time.tm_mon - 1;

    start_time = mktime(&tm_time);
    cout << "start_time is: " << start_time << endl;

    return;
}

bool CCtrlFile::getFieldValueByElement(QDomElement &domElement, ResInfo_STRU &struResInfo)
{
    cout << "getFieldValueByElement---------------" << endl;

    if (!domElement.nodeName().compare("_1s_15min"))
    {
        struResInfo.data_interval_type = INTERVAL_TYEP_1S_15MIN;
    }
    else if (!domElement.nodeName().compare("_15min_30min"))
    {
        struResInfo.data_interval_type = INTERVAL_TYEP_15MIN_30MIN;
    }
    else if (!domElement.nodeName().compare("_30min_2h"))
    {
        struResInfo.data_interval_type = INTERVAL_TYEP_30MIN_2H;
    }
    else if (!domElement.nodeName().compare("_2h_more"))
    {
        struResInfo.data_interval_type = INTERVAL_TYEP_2H_MORE;
    }
    else if (!domElement.nodeName().compare("_1s_less"))
    {
        struResInfo.data_interval_type = INTERVAL_TYEP_1S_LESS;
    }
    else
    {
        return false;
    }

    cout << "data_interval_type is:" << struResInfo.data_interval_type << endl;

    QString strText;
    time_t start_time;

    strText = domElement.attribute("startTime");
    getTimeFromDomText(strText.toLocal8Bit().data(), start_time);

    struResInfo.start_time = time(NULL) + 10;

    //��ȡdomElement�ڵ�������ӽڵ�
    QDomNodeList domNodeList = domElement.childNodes();

    for (int i = 0; i < domNodeList.count(); i++)
    {
        QDomNode domNode = domNodeList.at(i);

        if (domNode.isElement())
        {
            QDomElement domChild = domNode.toElement();

            if (!domChild.nodeName().compare("res_up"))
            {
                strText = domChild.attribute("value");
                struResInfo.res_up_value = strText.toFloat();

                strText = domChild.attribute("holdTime");
                struResInfo.res_up_time = strText.toInt();

                strText = domChild.attribute("price");
                struResInfo.res_up_price = strText.toFloat();
            }
            else if (!domChild.nodeName().compare("res_down"))
            {
                strText = domChild.attribute("value");
                struResInfo.res_down_value = strText.toFloat();

                strText = domChild.attribute("holdTime");
                struResInfo.res_down_time = strText.toInt();

                strText = domChild.attribute("price");
                struResInfo.res_down_price = strText.toFloat();
            }
        }
    }

    return true;
}

//�޸ı�
int CCtrlFile::modifyTable()
{
    int ret_sql_code;
    int result_code;
    char sql_sen[2000];

    cout << "g_AppNo is: " << g_AppNo << endl;

    TSqlModifyRequest sql_request_vec;
    SEQSqlModifyAnswer sql_answer_vec;
    sql_request_vec.seq_sql_request.length(m_vecCtrlFileInfo.size());
    sql_request_vec.app_no = g_AppNo;

    for (int i = 0; i < m_vecCtrlFileInfo.size(); i++)
    {
        //���ɲ������
        sprintf(sql_sen, "INSERT ies_sca_ctrltransinfo (create_time, file_type, file_source, file_destination, data_interval_type, start_time, res_up_value, res_up_time, res_up_price, res_down_value, res_down_time, res_down_price, record_app, record_app2, record_app3, record_app4) VALUES (%ld, %d, '%s','%s', %d, %ld, %f, %f, %f, %f, %f, %f, %d, %d, %d, %d)",
                m_vecCtrlFileInfo[i].create_time, m_vecCtrlFileInfo[i].file_type, m_vecCtrlFileInfo[i].file_source, m_vecCtrlFileInfo[i].file_destination,
                m_vecCtrlFileInfo[i].data_interval_type, m_vecCtrlFileInfo[i].start_time, m_vecCtrlFileInfo[i].res_up_value, m_vecCtrlFileInfo[i].res_up_time,
                m_vecCtrlFileInfo[i].res_up_price, m_vecCtrlFileInfo[i].res_down_value, m_vecCtrlFileInfo[i].res_down_time, m_vecCtrlFileInfo[i].res_down_price,
                m_vecCtrlFileInfo[i].record_app, m_vecCtrlFileInfo[i].record_app2, m_vecCtrlFileInfo[i].record_app3, m_vecCtrlFileInfo[i].record_app4);

        cout << "sql_sen is: " << sql_sen << endl;

        sql_request_vec.seq_sql_request[i] = sql_sen;
    }

    ret_sql_code = m_model_client->ModifyTableBySqls(sql_request_vec, sql_answer_vec);
    if (ret_sql_code < 0)
    {
        TRACE("ModifyTableBySqls() fail!\n");
    }
    if (ret_sql_code != 0)
    {
        result_code = -1; //����ʧ��
        TRACE("ModifyTableBySqlsSmart() fail!\n");
    }
    else if (sql_answer_vec[0].success_flag != 0)
    {
        result_code = -2; //sqlִ��ʧ��
        TRACE("sql_err_msg: %s\n", sql_answer_vec[0].syntax_err_msg.c_str());
    }
    else
    {
        result_code = 0;
    }

    return result_code;
}

int CCtrlFile::sendMessage(int messageType)
{
    int buf_size;
    int ret_code;
    char *send_buf;

    /* ��Ϣ�������������Ϣͷ������Ϣ���� */
    Message msg;

    /* vector�������洢TransData */
    TransData_SEQ transData_SEQ;

    /* ���ݰ��ṹ�� */
    CtrlTransPkg ctrlTransPkg;

    /* ��������ͨ�� m_vecCtrlFileInfo ���ݹ��� */
    ctrlTransPkg.data_num = m_vecCtrlFileInfo.size();
    for (int i = 0; i < m_vecCtrlFileInfo.size(); i++)
    {
        TransData struTransData;
        struTransData.create_time = m_vecCtrlFileInfo[i].create_time;
        struTransData.file_type = m_vecCtrlFileInfo[i].file_type;
        struTransData.interval_type = m_vecCtrlFileInfo[i].data_interval_type;
        transData_SEQ.push_back(struTransData);
    }

    ctrlTransPkg.data_info_seq = transData_SEQ;

    for (int i = 0; i < m_vecCtrlFileInfo.size(); i++)
    {
        cout << "ctrlTransPkg.data_num is: " << ctrlTransPkg.data_num << endl;
        cout << "ctrlTransPkg.data_info_seq.create_time is: " << ctrlTransPkg.data_info_seq[i].create_time << endl;
        cout << "ctrlTransPkg.data_info_seq.file_type is: " << ctrlTransPkg.data_info_seq[i].file_type << endl;
        cout << "ctrlTransPkg.data_info_seq.interval_type is: " << ctrlTransPkg.data_info_seq[i].interval_type << endl;
    }

    if (messageType == MT_IES_SCA_TRANS_CTRL_REQUEST)
    {
        /* ���ݰ��Ĵ�С */
        buf_size = sizeof(ctrlTransPkg);
        cout << "ctrlTransPkg size is: " << buf_size << endl;

        /*  */
        M_CODE(ctrlTransPkg, send_buf, buf_size);

        cout << "M_CODE buf_size is: " << buf_size << endl;

        /* memcpy�ڴ濽������
         * memcpy(void* destin, void * source, unsigned int n)
         * ��msg.Msg_buf�����ڴ�ռ�
         */
        memcpy(msg.Msg_buf, send_buf, buf_size);

        msg.header.event = MT_IES_SCA_TRANS_CTRL_REQUEST;
        msg.header.serv = CH_IES_SCA_TRANS_CTRL;
        msg.header.len = buf_size;

        /* 
         * ��Ϣ���ͣ� messageSend 
         * message_inv: ��Ϣ����ͷ�ļ�
         * messageSend(Message* msg, int msgLength, char *proc_name=NULL)
        */
        ret_code = m_messageBus.messageSend((Message *)&msg, buf_size, NULL);
        delete[] send_buf;
        send_buf = 0;
        if (ret_code <= 0)
        {
            TRACE("messageSend MT_IES_SCA_TRANS_CTRL_REQUEST error!\n");
        }
        else
        {
            TRACE("messageSend() MT_IES_SCA_TRANS_CTRL_REQUEST success!\n");
        }
    }

    return ret_code;
}

void CCtrlFile::readDeviceTable()
{
    if (g_IsDuty != 1)
    {
        return;
    }

    if (m_vecCtrlFileInfo.size())
    {
        return;
    }

    int ret_code;
    long dev_id = 3809482334802023559;
    float dev_value;

    /* 
     *
     * TableGetByKey ���չؼ���ȡĳ�ű��ĳ����¼
     * TableGetBykey(const char * key_ptr, const char * field_name, char * field_ptr, size)
     * 1���ؼ���ָ��
     * 2������
     * 3��������ݵ�ָ��
     * 4��������ݵı�����С
    */
    ret_code = m_devTableOp->TableGetByKey((char *)&dev_id, "value", (char *)&dev_value, sizeof(float));
    if (ret_code < 0)
    {
        TRACE("TableGetByKey() DMS_VALUE_INFO_NO error !\n");

        return;
    }

    cout << "TableGetByKey dev_value = " << dev_value << endl;

    /* 
     * �ж���������ѯ�����ݲ�Ϊ0
     * ��һ�δ洢��ֵ�����
     */
    if (dev_value != 0 && m_devValue != dev_value)
    {
        m_vecCtrlFileInfo.clear();

        CtrlFileInfo_STRU struCtrlTransInfo;
        memset(&struCtrlTransInfo, 0, sizeof(CtrlFileInfo_STRU));
        struCtrlTransInfo.create_time = time(NULL);
        struCtrlTransInfo.file_type = 2;
        strcpy(struCtrlTransInfo.file_source, "EMS");
        strcpy(struCtrlTransInfo.file_destination, "IES");
        struCtrlTransInfo.data_interval_type = 1;
        struCtrlTransInfo.start_time = struCtrlTransInfo.create_time + 10;

        if (dev_value < 0)
        {
            struCtrlTransInfo.res_up_value = -dev_value;
            struCtrlTransInfo.res_up_time = 900;
            struCtrlTransInfo.res_up_price = 0;
        }
        else
        {
            struCtrlTransInfo.res_down_value = dev_value;
            struCtrlTransInfo.res_down_time = 900;
            struCtrlTransInfo.res_down_price = 0;
        }

        struCtrlTransInfo.record_app = 32767;
        struCtrlTransInfo.record_app3 = 32767;

        m_vecCtrlFileInfo.push_back(struCtrlTransInfo);

        m_devValue = dev_value;
    }

    if (m_vecCtrlFileInfo.size())
    {
        ret_code = modifyTable();
        if (ret_code == 0)
        {
            TRACE("modify table IES_SCA_CTRLTRANSINFO  success!\n");

            //������Ϣ
            ret_code = sendMessage(MT_IES_SCA_TRANS_CTRL_REQUEST);
        }
    }

    return;
}

void CCtrlFile::deleteFilesByPath(char *filePath)
{
    QDir dir(filePath);

    char command[100];
    time_t cur_time;
    string strTempName;
    QString strFileName;

    QFileInfoList fileInfoList;
    QFileInfoList::Iterator fileIter;

    time(&cur_time);

    fileInfoList = dir.entryInfoList(QDir::Files);
    fileIter = fileInfoList.begin();
    TRACE("%s file num is: %d \n", filePath, fileInfoList.size());

    while (fileIter != fileInfoList.end())
    {
        strFileName = fileIter->fileName();

        //��ȡ�ļ����е���Ϣ
        getInfoFromFileName(strFileName);

        if ((cur_time - m_fileTime) >= FILES_REMAIN_TIME)
        {
            strTempName = strFileName.toStdString();

            sprintf(command, "rm %s/%s", filePath, strTempName.c_str());
            cout << command << endl;
            system(command);
        }

        fileIter++;
    }
}
