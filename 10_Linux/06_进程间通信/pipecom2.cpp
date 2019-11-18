/* 匿名管道通讯实例
 * pipe()函数创建匿名管道
 * 头文件#include <unistd> 
 */
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int ret = 0;
    int fd[2]; // 创建管道描述符
    ret = pipe(fd);
    char buff[1024];
    if (ret == -1)
    {
        printf("pipe erro !");
        return -1;
    }
    int read_fd = fd[0];
    int write_fd = fd[1];
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("创建子进程失败\n");
        return -1;
    }
    else if (pid == 0)
    {
        // 子进程
        close(read_fd);
        const char *str = "hello,gujiangqi!";
        if ((write(write_fd, str, strlen(str))) < 0)
        {
            printf("write erro!");
            exit(1);
        }
    }
    else
    {
        // 父进程
        close(write_fd);
        if ((read(read_fd, buff, sizeof(buff))) < 0)
        {
            printf("read erro !");
            exit(1);
        }
        fprintf(stdout, "%s", buff);
    }

    return 0;
}
