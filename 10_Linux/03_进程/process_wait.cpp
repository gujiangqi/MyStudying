#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
void out_status(int status)
{
    if (WIFEXITED(status))
    {
        printf("normal exit:%d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        printf("abnormal term %d\n", WTERMSIG(status));
    }
    else if (WIFSTOPPED(status))
    {
        printf("stopped sig:%d\n", WSTOPSIG(status));
    }
    else
    {
        printf("unknown exit\n");
    }
}
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        printf("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        // child process
        printf("pid:%d, ppid:%d\n", getpid(), getppid());
        exit(3); // 子进程终止运行，异常终止
    }
    // 父进程阻塞，等待子进程结束并回收
    wait(&status);
    out_status(status);
    printf("------------------------\n");

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        // child process
        printf("pid:%d, ppid:%d\n", getpid(), getppid());
        int i = 3, j = 0;
        int k = i / j;
        printf("k: %d\n", k);
    }

    // 父进程阻塞，等待子进程结束并回收
    wait(&status);
    out_status(status);
    printf("------------------------\n");

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        // child process
        printf("pid:%d, ppid:%d\n", getpid(), getppid());
        pause();
    }

    do
    {
        pid = waitpid(pid, &status, WNOHANG | WUNTRACED);
        if (pid == 0)
        {
            sleep(1);
        }

    } while (pid == 0);
    out_status(status);

    printf("------------------------\n");
    return 0;
}