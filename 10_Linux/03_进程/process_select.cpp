#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <map>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    char buf[10] = "";
    fd_set rdfds; // fd_set是一个结构体 文件描述符的集合
    struct timeval tv;
    FD_ZERO(&rdfds);   // 情况所有的位
    FD_SET(1, &rdfds); // 将标准输入加入set集
    tv.tv_sec = 3;
    tv.tv_usec = 500;
    /* 用来监视文件描述符是否发生变化 
     * 第二个参数监视读的变化
     * 第三个参数监视写的变化
     * 第四个参数监视例外的变化
     * 第五个参数监视超时时间
     * 如果成功，则返回改变的状态的文件个数
     * 超时则返回0
     * 失败则返回负数
    */
    
    int ret = select(1 + 1, &rdfds, NULL, NULL, &tv);
    if (ret < 0)
    {
        perror("\nselect erro");
        exit(1);
    }else if (ret == 0)
    {
        printf("\ntime out ");
    }else
    {
        printf("\nret = %d", ret);
    }
    
    system("pause");
    return 0;
}