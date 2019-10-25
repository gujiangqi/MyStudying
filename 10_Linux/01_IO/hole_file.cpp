#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
/* ���ɿն��ļ� */
char buffer[] = "0123456";

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "-usage:%s [file]\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY | O_CREAT | O_TRUNC | O_WRONLY, 0777);

    if (fd < 0)
    {
        perror("open error");
        exit(1);
    }

    size_t size = strlen(buffer) * sizeof(char);
    // ���ַ���д�뵽�ն��ļ���
    if (write(fd, buffer, size) != size)
    {
        perror("write error");
        exit(1);
    }

    // ��λ���ļ�β����10���ֽ�

    if (lseek(fd, 10L, SEEK_END) < 0)
    {
        perror("lseek error");
        exit(1);
    }

    // ���ļ�β����10���ֽڴ���д����ͬ���ַ���
    if (write(fd, buffer, size) != size)
    {
        perror("write error");
        exit(1);
    }

    return 0;
}
