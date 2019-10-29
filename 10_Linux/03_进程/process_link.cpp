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
    int counter = 0;
    if (argc < 2)
    {
        counter = 2;
    }
    else
    {
        counter = atoi(argv[1]);
    }

    int i = 1;
    pid_t pid;
    for (; i < counter; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork error!");
            exit(1);
        }
        else if (pid > 0)
        {
            break; //父进程退出循环，子进程继续循环
        }
        else
        {
            /* code */
        }

        // 父子都要进行循环
        // 保证父进程退出循环，子进程继续循环
    }
    printf("pid:%d,ppid:%d\n", getpid(), getppid());
    while (1)
    {
        sleep(1);
    }
    return 0;
}