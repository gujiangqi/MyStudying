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
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid > 0)
    {
        printf("%d deaded \n", getpid());
        exit(0);// 父进程终止运行
    }
    else
    {
        // child process
        sleep(4);
        printf("pid: %d, ppid: %d \n", getpid(), getppid());
    }

    return 0;
}