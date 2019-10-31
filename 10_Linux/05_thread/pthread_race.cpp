#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#

// 定义线程运行函数
void *th_fn(void *arg)
{
    int distance = (int)arg;

    int i;
    for (i = 1; i < distance; i++)
    {
        printf("%lx run %d \n", pthread_self(), i);
        sleep(1);
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    int erro;
    pthread_t rabbit, turtle;

    // 创建rabbit线程
    if (err = pthread_create(&rabbit, NULL, th_fn, (void *)50) != 0)
    {
        perror("rabbit pthread_create error");
    }

    // 创建turtle线程
    if (err = pthread_create(&turtle, NULL, th_fn, (void *)50) != 0)
    {
        perror("turtle pthread_create error");
    }

    printf("control thread id:%lx \n", pthread_self());
    return 0;
}
