#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        fprintf(stderr, "usage: %s file \n", argv[0]);
        exit(1);
    }

    int i = 1;
    struct stat buff;
    for (int i = 1; i < argc; i++)
    {
        size_t b = sizeof(buff);
        memset(&buff, 0, b);
        if (lstat(argv[i], &buff) < 0)
        {
            perror("lstata erro");
            continue;
        }
        printf("%-20s", argv[i]); // 左对齐20输出

        // 判断文件类型：
        if (S_ISREG(buff.st_mode))
        {
            printf("normal file\n");
        }
        else if (S_ISDIR(buff.st_mode))
        {
            printf("directory\n");
        }
        else if (S_ISBLK(buff.st_mode))
        {
            printf("block device\n");
        }
        else if (S_ISCHR(buff.st_mode))
        {
            printf("character device\n");
        }
        else if (S_ISSOCK(buff.st_mode))
        {
            printf("sock device\n");
        }
        else if (S_ISFIFO(buff.st_mode))
        {
            printf("named pipe \n");
        }
        else if (S_ISLNK(buff.st_mode))
        {
            printf("link file\n");
        }
        else
        {
            printf("unknown type!\n");
        }
    }

    return 0;
}