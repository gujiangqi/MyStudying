#include <iostream>
//#include <RTDB_Connection.h>
#include "odb_tableop.h" 
using namespace std;

int main()
{   
    char*  buf_ptr = NULL;
    int ret_code;
    CTableOp table_op;//定义实时数据库接口，面向对象的接口，定义在db_define
    
    ret_code =  table_op.open(100000,405);
    // TB_DESCR tb_des;
    // int ret_code = OpenTableByName(NULL , "realtime" , AF_SCADA_NAME, "measpoint" , & tb_des);
}
