#ifndef CTRL_FILE_STRUCT_H
#define CTRL_FILE_STRUCT_H

struct MsgDataRec_STRU
{
    long create_time;
    int file_type;
    int	interval_type;
};

struct ResInfo_STRU
{
    int data_interval_type;
    long  start_time;
    float res_up_value;
    float  res_up_time;
    float res_up_price;
    float res_down_value;
    float  res_down_time;
    float res_down_price;
};

//存放IES控制文件交互信息表信息
struct CtrlFileInfo_STRU
{
    long  create_time;
    int   file_type;
    char  file_source[32];
    char  file_destination[32];
    int   data_interval_type;
    long  start_time;
    float res_up_value;
    float  res_up_time;
    float res_up_price;
    float res_down_value;
    float  res_down_time;
    float res_down_price;
    int   record_app;
    int   record_app2;
    int   record_app3;
    int   record_app4;
};

#endif // ISCA_CTRL_STRUCT_H
