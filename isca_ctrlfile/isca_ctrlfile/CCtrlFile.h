#ifndef CCTRLFILE_H
#define CCTRLFILE_H
#include "ctrl_file_include.h"

class CCtrlFile
{
public:
    CCtrlFile();
    ~CCtrlFile();

    void    ctrlFileProcess();      //控制文件处理函数
    void    readDeviceTable();      //读取上级电网转发量测，暂用
    int     recvMessage();          //消息接收
    void    readCtrlTransRecords(); //获取表信息
    void    createCtrlTransFile();  //生成控制交互文件
    void    deleteBackupFiles();    //定时删除备份文件

private:
    int     parseCtrlFile(char* fileName);              //解析控制交互xml文件
    void    getInfoFromFileName(QString& fileName);     //获取文件名的基础信息
    void    getTimeFromDomText(char* domTest, time_t& start_time);         //根据dataTime属性获取时间
    bool    getFieldValueByElement(QDomElement& domElement, ResInfo_STRU& stuResInfo); //获取控制交互文件资源子节点属性值
    int     modifyTable();          //修改表
    int     sendMessage(int messageType);
    void    deleteFilesByPath(char* filePath);          //删除指令路径下的文件

private:

    //文件路径
    char m_readFilePath[100];           //外系统至本系统文件暂存路径
    char m_backupSuccessFilePath[100];  //文件解析成功备份路径
    char m_backupFailFilePath[100];     //文件解析失败备份路径
    char m_sendFilePath[100];           //本系统生成文件存放路径

    //存放文件基础信息，用于校验控制交互文件是否正确
    time_t m_fileTime;              //文件时间
    QString m_strfileType;          //文件类型
    QString m_strfileSource;        //文件来源系统
    QString m_strfileDestination;   //文件目的系统

    float m_devValue;           //用于存放上级电网转发数值

    vector<CtrlFileInfo_STRU> m_vecCtrlFileInfo;    //存放控制交互信息表内容，用于写库
    vector<MsgDataRec_STRU> m_vecMsgDataRec;        //存放接收的消息内容
    map<int, ResInfo_STRU> m_mapResInfo;            //间隔时间-资源信息容器，用于生成xml文件

    modify_client_base*  m_model_client;
    message_invocation   m_messageBus;
    Message              m_msg_rec;

    CTableOp*  m_devTableOp;
    CTableNet*  m_transTableNet;
};

#endif // CCTRLFILE_H
