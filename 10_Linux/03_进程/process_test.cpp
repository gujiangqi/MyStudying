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
    printf("Main pid is %d", getpid());
    for (i = 0; i < 2; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("i am child,paramer pid is %d,My Pid is %d,My father Pid is %d", pid, getpid(), getppid());
        }
        else
        {
            printf("i am father,paramer pid is %d,My Pid is %d,My father Pid is %d", pid, getpid(), getppid());
        }
    }
    return 0;
}