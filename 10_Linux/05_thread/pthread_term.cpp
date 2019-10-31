#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <pthread.h>
using namespace std;
struct Arg
{
    int d1;
    int d2;
};
void *th_fn(void *arg)
{
    Arg *r = (Arg *)arg;
    return (void *)(r->d1 + r->d2);
}
int main(int argc, char *argv[])
{
    int err;
    pthread_t th;
    Arg r = {20, 50};
    if ((err = pthread_create(&th, NULL, th_fn, (void *)&r)) != 0)
    {
        perror("pthread error");
        exit(1);
    }
    int result;
    pthread_join(th, (void *)&result);
    printf("result is %d \n", (int)result);
    return 0;
}