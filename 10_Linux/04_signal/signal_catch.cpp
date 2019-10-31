#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <signal.h>
using namespace std;

// 定义信号处理函数
// signo：进程捕获到的信号
void sig_handler(int signo)
{
    printf("%d,%d occureed\n", getpid(), signo);
}

int main(int argc, char *argv[])
{
    // 向内核登记信号处理函数以及信号值
    // SIGTSTP：由硬件驱动发出的信号，ctrl+Z
    if (signal(SIGTSTP, sig_handler) == SIG_ERR)
    {
        perror("signal error");
        exit(1);
    }
    if (signal(SIGKILL, SIG_IGN) == SIG_ERR)
    {
        perror("singal sigint error");
    }
    if (signal(SIGSTOP, SIG_IGN) == SIG_ERR)
    {
        perror("singal sigint error");
    }
    int i = 0;
    while (i < 50)
    {
        printf("%d out %d\n", getpid(), i++);
        sleep(1);
    }

    return 0;
}