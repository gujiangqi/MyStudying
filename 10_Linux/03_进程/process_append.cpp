#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(1);
    }
    int fd = open(argv[1], O_WRONLY);
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid > 0)
    {
        //parent process
        // 父进程将文件偏移量调整到文件尾部
        if (lseek(fd, 0L, SEEK_END) < 0)
        {
            perror("lseek error!");
            exit(1);
        }
    }
    else
    {
        // child process,子进程会复制一个文件描述符
        // 子进程从文件尾部追加内容
        const char *str = "hello gujiangqi!";
        ssize_t size = strlen(str) * sizeof(char);

        sleep(3);

        // 此处的fd是复制过来的fd，不是父进程原始的fd
        // 但是和父进程中的fd都是指向同一个文件
        if (write(fd, str, size) < 0)
        {
            perror("write error:");
            exit(1);
        }
    }
    printf("pid: %d finish\n", getpid());
    sleep(1);

    // 父子进程都需要关闭文件描述符
    close(fd);
    return 0;
}