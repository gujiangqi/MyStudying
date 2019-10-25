#include "io.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_LEN 1024

void copy(int fdin, int fdout)
{
    char buffer[BUFFER_LEN];
    ssize_t size;
    lseek(fdin, 0L, SEEK_END);
    // 定位到文件开始
    lseek(fdin, 0L, SEEK_SET);
    while ((size = read(fdin, buffer, BUFFER_LEN)) > 0)
    {
        printf("current: %ld\n", lseek(fdin, 0L, SEEK_CUR));
        ssize_t wSize;
        wSize = write(fdout, buffer, size);
        if (wSize != size)
        {
            fprintf(stderr, "write erro:%s\n", strerror(errno));

            exit(1);
        }
    }

    if (size < 0)
    {
        fprintf(stderr, "read error:%s\n", strerror(errno));
        exit(1);
    }
}

void set_fl(int fd, int flag)
{
    // 获得原来的文件状态标志
    int val = fcntl(fd, F_GETFL);

    // 增加新的文件状态标志
    val |= flag; //val = val|falg;

    // 重新设置文件状态标志(val为新的文件状态标志)
    if (fcntl(fd, F_SETFL, val) < 0)
    {
        perror("fcntl error");
    }
}
void clr_fl(int fd, int flag)
{
    int val = fcntl(fd, F_GETFL);
    //清除指定的文件状态标志
    val &= ~flag; // val = val &(~flag);
    if (fcntl(fd, F_SETFL, val) < 0)
    {
        perror("fcntl error");
    }
}