#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;

struct RaceArg
{
    char name[20];
    int time;
    int start;
    int end;
};

void *th_fn(void *arg)
{
    RaceArg *r = (RaceArg *)arg;
    int i = r->start;
    for (; i < r->end; i++)
    {
        printf("%s(%lx) running %d\n", r->name, pthread_self(), i);
        usleep(r->time);
    }
    return (void *)(r->end - r->start);
}

int main(int argc, char *argv[])
{
    int err;
    RaceArg r_a = {"rabbit", (int)(drand48() * 100000000), 20, 50};
    RaceArg t_a = {"turtule", (int)(drand48() * 100000000), 10, 60};
    pthread_t rabbit, turtle;
    if ((err = pthread_create(&rabbit, NULL, th_fn, (void *)&r_a)) != 0)
    {
        perror("rabbit pthread_create error");
        exit(1);
    }
    if ((err = pthread_create(&turtle, NULL, th_fn, (void *)&t_a)) != 0)
    {
        perror("turtle pthread_create error");
        exit(1);
    }
    /* 
    pthread_join(rabbit, NULL);
    pthread_join(turtle, NULL); */

    int result;
    pthread_join(rabbit, (void *)&result);
    printf("rabbit race distance is %d\n", result);
    printf("control thread id:%lx \n", pthread_self());
    printf("finished \n");

    system("pause");
    return 0;
}