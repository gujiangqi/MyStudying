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
    if (argc < 2)
    {
        fprintf(stderr, "usage:%s files \n", argv[0]);
        exit(1);
    }

    int i;
    for (i = 1; i < argc; ++i)
    {
        if (access(argv[i], F_OK))
        {
            printf("%s is not exit read %s \n",
                   getpid(), argv[i]);
            continue;
        }
        if (access(argv[i], R_OK))
        {
            printf("%d can not read %s\n",
                   getpid(), argv[i]);
        }
        else
        {
            printf("%d can read %s \n",
                   getpid(), argv[i]);
        }
        if (access(argv[i], W_OK))
        {
            printf("%d can not write %s\n",
                   getpid(), argv[i]);
        }
        else
        {
            printf("%d can write %s \n",
                   getpid(), argv[i]);
        }
        if (access(argv[i], X_OK))
        {
            printf("%d can not excute %s\n",
                   getpid(), argv[i]);
        }
        else
        {
            printf("%d can excute %s \n",
                   getpid(), argv[i]);
        }
    }
    return 0;
}