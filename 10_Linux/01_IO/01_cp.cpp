#include "unistd.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "sys/types.h"
#include "string.h"
#include "stdio.h"
#include "errno.h"
#include "io.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage:%s srcfilename destfilename\n", argv[0]);
    }

    int fdin = open(argv[1], O_RDONLY);

    // printf("file length:%ld\n", lseek(fdin, 0L, SEEK_END)); //尾部偏移0个字节
    if (fdin < 0)
    {
        fprintf(stderr, "open erro:%s\n", strerror(errno));
    }
    else
    {
        printf("open success: %d\n", fdin);
    }

    // 打开一个待写入的文件
    int fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdout < 0)
    {
        fprintf(stderr, "open erro:%s\n", strerror(errno));
    }
    else
    {
        printf("open success: %d\n", fdout);
    }

    // 文件复制
    copy(fdin, fdout);
    close(fdin);
    close(fdout);

    return 0;
}
