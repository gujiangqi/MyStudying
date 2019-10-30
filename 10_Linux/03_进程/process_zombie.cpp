#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <wait.h>

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
    else if (pid == 0)
    {
        //child process
        printf("pid :%d,ppid:%d\n", getpid(), getppid());
        exit(1);
    }
    wait(0);
    /* while (1)
    {
        // 父进程继续循环
        sleep(1);
    } */

    return 0;
}