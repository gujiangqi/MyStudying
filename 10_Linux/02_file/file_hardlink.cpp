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
        fprintf(stderr, "suage:%s srcfile file \n",
                argv[0]);
    }
    int i;
    for (i = 2; i < argc; i++)
    {
        if (link(argv[1], argv[i]) < 0)
        {
            perror("create error");
            exit(1);
        }
    }

    return 0;
}