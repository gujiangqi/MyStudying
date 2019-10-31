#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <pthread.h>
using namespace std;

// 定义线程清理函数
void clean_fun(void *arg)
{
    const char *s = (const char *)arg;
    printf("clean_func:%s\n", s);
}

void *th_fun(void *arg)
{
    int *execute = (int *)arg;
    pthread_cleanup_push(clean_fun, (void *)"first");
    pthread_cleanup_push(clean_fun, (void *)"second");
    printf("thread running %lx\n", pthread_self());
    pthread_cleanup_pop(*execute);
    pthread_cleanup_pop(*execute);
    return NULL;
}
int main(int argc, char *argv[])
{
    int err;
    pthread_t th1, th2;
    int i = 1;
    if ((err = pthread_create(&th1, NULL, th_fun, (void *)&i)) != 0)
    {
        perror("pthread create error");
    }
    pthread_join(th1, NULL);
    printf("th1(%lx) finished \n", th1);

    if ((err = pthread_create(&th2, NULL, th_fun, (void *)&i)) != 0)
    {
        perror("pthread create error");
    }
    pthread_join(th2, NULL);
    printf("th2(%lx) finished \n", th2);

    system("pause");
    return 0;
}