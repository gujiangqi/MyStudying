#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <wait.h>
using namespace std;

const char *cmd1 = "date > s1.txt";
const char *cmd2 = "date > s2.txt";

void mysystem(const char *cmd)
{
    pid_t pid;
    if ((pid = getpid()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        if (execlp("/bin/bash", "/bin/bash", "-c", cmd, NULL) < 0)
        {
            perror("execlp error");
            exit(1);
        }
    }
    else
    {
        wait(0);
    }
}

int main(int argc, char *argv[])
{
    system("clear");
    system(cmd1);
    mysystem(cmd2);
    return 0;
}