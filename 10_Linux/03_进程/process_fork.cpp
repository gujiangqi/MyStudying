#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
int g_v = 30;
int main(int argc, char *argv[])
{
    int a_v = 30;
    static int s_v = 30;
    printf("cunrrent pid:%d\n", getpid());
    FILE *fp = fopen("s.txt", "w");
    int fd = open("s_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG);
    const char *s = "hello gujiangqi!";
    ssize_t size = strlen(s) * sizeof(char);
    /* 父进程调用的 */
    // 标准IO函数（带缓存）
    fprintf(fp, "s:%s,pid:%d", s, getpid());

    // 内核提供的IO系统调用（不带缓存） // 直接写入文件
    write(fd, s, size);

    pid_t pid;
    pid = fork(); // 创建子进程
    // fork 会返回两个pid
    // 在fork之后会运行两个进程（父进程和子进程）
    // sleep(3);
    if (pid < 0)
    {
        perror("fork error");
    }
    else if (pid > 0) // 在父进程返回子进程的pid
    {
        g_v = 40;
        a_v = 40;
        s_v = 40;
        printf("current pid is father pid: %d, ppid is %d, fork return is %d\n", getpid(), getppid(), pid);
        printf("g_v：%p,a_v:%p,s_v:%p\n", &g_v, &a_v, &s_v);
    }
    else // 在子进程当中 返回的是0
    {
        g_v = 50;
        a_v = 50;
        s_v = 50;
        printf("current pid is child pid: %d,ppid is %d, fork return is %d \n", getpid(), getppid(), pid);
        printf("g_v：%p,a_v:%p,s_v:%p\n", &g_v, &a_v, &s_v);
    }

    // printf("pid: %d, g_v:%d, a_v:%d, s_v:%d \n", getpid(), g_v, a_v, s_v);
    // 父子进程都要运行的。写入缓存
    fprintf(fp, "pid: %d, g_v:%d, a_v:%d, s_v:%d \n", getpid(), g_v, a_v, s_v);

    sleep(1);

    return 0; // 程序结束的时候，会自动清缓存，把缓存写到文件中去
}