#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd_in = STDIN_FILENO;
    int fd_out = STDOUT_FILENO;

    int i;

    for (i = 1; i < argc; i++)
    {
        fd_in = open(argv[i], O_RDONLY);
        if (fd_in < 0)
        {
            perror("open erro");
            continue;
        }
        copy(fd_in, fd_out);
        close(fd_in);
    }
    if (argc == 1)
    {
        copy(fd_in, fd_out);
    }

    return 0;
}
