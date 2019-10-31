#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
void sig_handler(int signo)
{
    printf("child process deaded,signo:%d \n", signo);
    wait(NULL);
};
void out(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d out %d\n", getpid(), i);
        sleep(1);
    }
};
int main(int argc, const char **argv)
{
    if (signal(SIGCHLD, sig_handler) == SIG_ERR)
    {
        perror("signal sigchild error");
    }

    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid > 0)
    {
        // parent process

        out(20);
    }
    else
    {
        // child process
        out(10);
    }

    return 0;
}