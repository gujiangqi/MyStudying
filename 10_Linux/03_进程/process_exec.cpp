#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <wait.h>
using namespace std;

const char *cmd1 = "cat";
const char *cmd2 = "/bin/cat";
const char *argv1 = "/etc/passwd";
const char *argv2 = "/etc/group";

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
        // 子程序调用exec函数执行新的程序
        // cmd1 必须为绝对路径
        // if (execl(cmd1, cmd1, argv1, argv2, NULL) < 0)
        if (execl(cmd2, cmd1, argv1, argv2, NULL) < 0)
        {
            perror("execl error");
            exit(1);
        }
        else
        {
            printf("execl %s success \n", cmd1);
        }
        printf("after exec!");
    }
    wait(NULL); // 这是回收不返回
    printf("-------------\n");

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        const char *const argv[4] = {cmd1, argv1, argv2, NULL};
        if (execvp(cmd1, argv) < 0)
        {
            perror("execvp error");
            exit(1);
        }
        else
        {
            printf("execvp %s success \n", cmd1);
        }
    }
    wait(NULL);

    system("pause");
    return 0;
}