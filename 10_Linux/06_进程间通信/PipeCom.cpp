#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <string>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int pipe_fd[2];
    pid_t pid;
    char r_buf[100];

    int r_num;
    memset(r_buf, 0, sizeof(r_buf));
    if ((pipe(pipe_fd) < 0))
    {
        printf("pipe create error \n");
        return -1;
    }
    pid = fork();
    if (pid < 0)
    {
        printf("fork error!");
        exit(1);
    }
    else if (pid == 0)
    {
        // child process
        printf("child process start...\n");
        close(pipe_fd[1]);
        sleep(1);
        if (r_num = read(pipe_fd[0], r_buf, 100) > 100)
            printf("1. %d numbers read from the pipe is %s \n", r_num, r_buf);

        close(pipe_fd[0]);
        exit(0);
    }
    else
    {
        // father process
        char buff[1024];
        cin >> buff;
        close(pipe_fd[0]);
        if ((write(pipe_fd[1], buff, strlen(buff)) != -1))
            printf("parent write1 hello \n");
        // if (write(pipe_fd[1], "pipe", 5) != -1)
        //     printf("parent write2 pipe \n");

        close(pipe_fd[1]);
        sleep(1);
        waitpid(pid, NULL, 0);
        exit(0);
    }

    return 0;
}