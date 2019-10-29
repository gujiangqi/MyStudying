#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    printf("pid:%d\n", getpid());
    printf("uid:%d\n", getuid());
    printf("euid:%d \n", geteuid());
    printf("user gid:%d\n", getgid());
    printf("gid:%d\n", getpgrp());
    printf("pgid:%d\n", getpgid(getpid()));
    printf("ppgid:%d\n", getpgid(getppid()));
    system("pause");
    return 0;
}