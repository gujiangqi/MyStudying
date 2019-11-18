#ifndef CTRL_FILE_DEFINE_H
#define CTRL_FILE_DEFINE_H

#define  CTRL_TRANS_RES_INFO_SQL  "data_interval_type,start_time,res_up_value,res_up_time,res_up_price,res_down_value,res_down_time,res_down_price"

const int PARSE_FILES_INTERVAL  = 1;            //���ʿ����ļ�·�����
const int DELETE_FILES_INTERVAL = 86400;        //ɾ�������ļ����
const int FILES_REMAIN_TIME     = 15*86400;     //�����ļ���������

//��Ӧ���ݼ������
const int INTERVAL_TYEP_1S_15MIN    = 1;
const int INTERVAL_TYEP_15MIN_30MIN = 2;
const int INTERVAL_TYEP_30MIN_2H    = 3;
const int INTERVAL_TYEP_2H_MORE     = 4;
const int INTERVAL_TYEP_1S_LESS    = 5;

const int CTRL_TYPE_SEND    = 1;    //���Ʒ���
const int CTRL_TYPE_REQUEST = 2;    //��������
const int CTRL_TYPE_CONFIRM = 3;    //����ȷ��
const int CTRL_TYPE_EXEC    = 4;    //����ִ��

#endif // ISCA_CTRL_DEFINE_H
