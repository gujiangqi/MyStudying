#ifndef CTRL_FILE_DEFINE_H
#define CTRL_FILE_DEFINE_H

#define  CTRL_TRANS_RES_INFO_SQL  "data_interval_type,start_time,res_up_value,res_up_time,res_up_price,res_down_value,res_down_time,res_down_price"

const int PARSE_FILES_INTERVAL  = 1;            //访问控制文件路径间隔
const int DELETE_FILES_INTERVAL = 86400;        //删除备份文件间隔
const int FILES_REMAIN_TIME     = 15*86400;     //备份文件保存周期

//对应数据间隔类型
const int INTERVAL_TYEP_1S_15MIN    = 1;
const int INTERVAL_TYEP_15MIN_30MIN = 2;
const int INTERVAL_TYEP_30MIN_2H    = 3;
const int INTERVAL_TYEP_2H_MORE     = 4;
const int INTERVAL_TYEP_1S_LESS    = 5;

const int CTRL_TYPE_SEND    = 1;    //控制发送
const int CTRL_TYPE_REQUEST = 2;    //控制请求
const int CTRL_TYPE_CONFIRM = 3;    //控制确认
const int CTRL_TYPE_EXEC    = 4;    //控制执行

#endif // ISCA_CTRL_DEFINE_H
