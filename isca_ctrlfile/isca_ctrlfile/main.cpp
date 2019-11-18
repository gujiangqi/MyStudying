#include "CCtrlFile.h"
#include "ctrl_file_include.h"

char g_AppName[32];
char g_CtxName[64];
char g_ProcName[64];
int g_AppNo;
int g_IsDuty;
short g_CtxNo;
time_t g_CurTime;

void DoNothing(int nn = 0)
{
    cout << "DoNothing!" << endl;
}

void ExitProcess(int aa = 0)
{
    cout << "ies_ctrlfile Exit!!!" << endl;
    exit(0);
}

void isca_ctrlfile_fun()
{
    /* �������ݽṹ���� */
    CServicesManage ser_manage;
    time_t cur_Time, last_cal_Time;
    time_t last_remove_time;
    /* ��������� */
    CCtrlFile ctrlFile;

    last_cal_Time = 0;
    last_remove_time = 0;

    while (1)
    {
        /* ���epoch�𾭹���ʱ�� */
        time(&cur_Time); // ��ȡ��ǰʱ�䲢��ֵ��cur_time

        g_IsDuty = ser_manage.IsOnDuty(AP_SCADA);

        //�����ļ�����
        if ((cur_Time - last_cal_Time) >= PARSE_FILES_INTERVAL)
        {
            ctrlFile.ctrlFileProcess(); //�����ļ�������

            /* ��ȡ�ϼ�����ת��������������һ���������������Ƿ���˭�ģ����ϼ���ʲô���� */
            ctrlFile.readDeviceTable(); //��ȡ�ϼ�����ת�����⣬����
            last_cal_Time = cur_Time;
        }

        //��Ϣ���մ���
        if (ctrlFile.recvMessage() > 0)
        {
            //��ȡ����Ϣ
            ctrlFile.readCtrlTransRecords();

            //д�ļ�
            ctrlFile.createCtrlTransFile();
        }

        //��ʱɾ�������ļ�
        if ((cur_Time - last_remove_time) >= DELETE_FILES_INTERVAL)
        {
            ctrlFile.deleteBackupFiles();

            last_remove_time = cur_Time;
        }

        usleep(1000);
    }

    return;
}

int main(int argc, char **argv)
{
    /* 
     * SIGHUB��  1
     * SIGALRM�� 14
     * SIGPIPE�� 13
     * SIGINT��  2
     * SIGTERM�� 15
     * ����ָ��ԭ�� void (* handle)(int);
     */
    sigset(SIGHUP, DoNothing);
    sigset(SIGALRM, DoNothing);
    sigset(SIGPIPE, DoNothing);
    signal(SIGINT, ExitProcess);
    signal(SIGTERM, ExitProcess);

    bool set_ctx_flag = false;
    int ret_code = 0;
    CTableNet tableNet;
    /* ���AppName */
    int i = 0;
    for (i = 1; i < argc; i++)
    {
        /* �����һ��������app */
        if (!strcmp(argv[i], "-app"))
        {
            if (i + 1 < argc)
            {
                sprintf(g_AppName, "%s", argv[i + 1]);
            }

            break;
        }
    }

    if (i == argc)
    {
        cout << "Usage: isca_ctrlfile -app appName " << endl;
        exit(0);
    }

    /* ��������ֵ */
    sprintf(g_ProcName, "isca_crtlfile_%s", g_AppName);

    ret_code = tableNet.GetAppNoByName(g_AppNo, g_AppName);
    if (ret_code < 0)
    {
        cout << "getAppNoByName error! " << endl;
        exit(0);
    }

    for (int j = 3; j < argc; j++)
    {
        if (!strcmp(argv[j], "-ctx"))
        {
            set_ctx_flag = true;
        }
    }
    /* ���ýӿ� */
    if (set_ctx_flag)
    {
        CContext::SetContextNo(argc, argv);
    }
    else
    {
        CContext::SetContextNo(argc, argv, AC_REALTIME_NO);
    }

    /* ��ýӿ� */
    CContext::GetContextNo(g_CtxNo);
    CContext::GetCtxNameByCtxNo(g_CtxNo, g_CtxName);
    /* ����ע��ɹ� */
    proc_invocation prcm;
    ret_code = prcm.proc_init(g_CtxName, g_AppName, g_ProcName);
    if (ret_code < 0)
    {
        TRACE("proc_init() error!\n");
        exit(0);
    }

    isca_ctrlfile_fun();

    return 0;
}
