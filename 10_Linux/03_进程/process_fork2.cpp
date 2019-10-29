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
    printf("current pid is %d \n", getpid());

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
    }
    else if (pid > 0)
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            printf("this is parent process pid is %d \n", getpid());
            sleep(1);
        }
    }
    else
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            printf("this is child process pid is :%d \n", getpid());
            sleep(1);
        }
    }

    return 0;
}