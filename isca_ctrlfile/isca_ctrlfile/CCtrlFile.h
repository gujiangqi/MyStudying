#ifndef CCTRLFILE_H
#define CCTRLFILE_H
#include "ctrl_file_include.h"

class CCtrlFile
{
public:
    CCtrlFile();
    ~CCtrlFile();

    void    ctrlFileProcess();      //�����ļ�������
    void    readDeviceTable();      //��ȡ�ϼ�����ת�����⣬����
    int     recvMessage();          //��Ϣ����
    void    readCtrlTransRecords(); //��ȡ����Ϣ
    void    createCtrlTransFile();  //���ɿ��ƽ����ļ�
    void    deleteBackupFiles();    //��ʱɾ�������ļ�

private:
    int     parseCtrlFile(char* fileName);              //�������ƽ���xml�ļ�
    void    getInfoFromFileName(QString& fileName);     //��ȡ�ļ����Ļ�����Ϣ
    void    getTimeFromDomText(char* domTest, time_t& start_time);         //����dataTime���Ի�ȡʱ��
    bool    getFieldValueByElement(QDomElement& domElement, ResInfo_STRU& stuResInfo); //��ȡ���ƽ����ļ���Դ�ӽڵ�����ֵ
    int     modifyTable();          //�޸ı�
    int     sendMessage(int messageType);
    void    deleteFilesByPath(char* filePath);          //ɾ��ָ��·���µ��ļ�

private:

    //�ļ�·��
    char m_readFilePath[100];           //��ϵͳ����ϵͳ�ļ��ݴ�·��
    char m_backupSuccessFilePath[100];  //�ļ������ɹ�����·��
    char m_backupFailFilePath[100];     //�ļ�����ʧ�ܱ���·��
    char m_sendFilePath[100];           //��ϵͳ�����ļ����·��

    //����ļ�������Ϣ������У����ƽ����ļ��Ƿ���ȷ
    time_t m_fileTime;              //�ļ�ʱ��
    QString m_strfileType;          //�ļ�����
    QString m_strfileSource;        //�ļ���Դϵͳ
    QString m_strfileDestination;   //�ļ�Ŀ��ϵͳ

    float m_devValue;           //���ڴ���ϼ�����ת����ֵ

    vector<CtrlFileInfo_STRU> m_vecCtrlFileInfo;    //��ſ��ƽ�����Ϣ�����ݣ�����д��
    vector<MsgDataRec_STRU> m_vecMsgDataRec;        //��Ž��յ���Ϣ����
    map<int, ResInfo_STRU> m_mapResInfo;            //���ʱ��-��Դ��Ϣ��������������xml�ļ�

    modify_client_base*  m_model_client;
    message_invocation   m_messageBus;
    Message              m_msg_rec;

    CTableOp*  m_devTableOp;
    CTableNet*  m_transTableNet;
};

#endif // CCTRLFILE_H
