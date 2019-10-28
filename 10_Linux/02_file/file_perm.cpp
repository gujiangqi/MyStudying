#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage:%s files \n", argv[0]);
    }

    struct stat buff;
    int i;
    for (int i = 1; i < argc; i++)
    {
        memset(&buff, 0, sizeof(buff));
        if (lstat(argv[i], &buff) < 0)
        {
            perror("lstat error");
            continue;
        }
        // 获得文件的权限信息

        mode_t mode = buff.st_mode;
        printf("%-20s", argv[i]);

        // user permission
        if (S_IRUSR & mode)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if (S_IWUSR & mode)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if (S_IXUSR & mode)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }

        // user permission
        if (S_IRGRP & mode)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if (S_IRGRP & mode)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if (S_IRGRP & mode)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }

        // user permission
        if (S_IROTH & mode)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if (S_IROTH & mode)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if (S_IROTH & mode)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }
        printf("\n");
    }

    return 0;
}