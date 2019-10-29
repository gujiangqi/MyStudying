#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "usage:%s linkfiles\n",
                argv[0]);
        exit(1);
    }

    // 对源文件创建符号连接
    if (symlink(argv[1], argv[2]) < 0)
    {
        perror("symlink error");
        exit(1);
    }

    char buffer[1024];
    ssize_t size;
    memset(buffer, 0, sizeof(buffer));
    int fd = open(argv[2], O_RDONLY);

    // 读取软链接文件引用的原文件内容
    if (read(fd, buffer, sizeof(buffer)) < 0)
    {
        perror("read error!");
    }
    else
    {
        write(STDOUT_FILENO, buffer, sizeof(buffer));
    }
    printf("\n");

    // 读取软链接本身的内容
    memset(buffer, 0, sizeof(buffer));
    if ((size = readlink(argv[2], buffer, sizeof(buffer))) < 0)
    {
        perror("open error");
    }
    else
    {
        write(STDOUT_FILENO, buffer, size);
    }
    printf("\n");
    close(fd);

    return 0;
}