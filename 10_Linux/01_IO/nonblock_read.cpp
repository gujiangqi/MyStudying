#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include "io.h"
using namespace std;

int main(int argc, char *argv[])
{
    stat sta;
    sta.st_mode
    char buffer[4096] = {'\0'};
    ssize_t size = 0;
    // 设置非阻塞方式
    set_fl(STDIN_FILENO, O_NONBLOCK);
    sleep(5);
    size = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (size < 0)
    {
        perror("read error!");
        exit(1);
    }
    else if (size == 0)
    {
        printf("read finished！\n");
        // exit(1);
    }
    else
    {
        if (write(STDOUT_FILENO, buffer, size) != size)
        {
            perror("write error");
            exit(1);
        }
    }
    return 0;
}