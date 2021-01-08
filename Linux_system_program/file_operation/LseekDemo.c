#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// #include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    int ret;
    fd = open("hole.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(fd == -1)
    {
        // ERR_EXIT("open error.\n");
        exit(-1);
    }
    write(fd, "hello", 5);
    // file pointer move out edge, result null dot.
    ret = lseek(fd, 1024*1024*1024, SEEK_CUR);
    if(ret == -1)
    {
        // ERR_EXIT("lseek error");
        exit(-1);
    }
    write(fd, "world\n", 5);
    close(fd);

    return 0;
}
