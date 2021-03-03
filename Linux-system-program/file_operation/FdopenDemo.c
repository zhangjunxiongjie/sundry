#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    FILE *fp;
    int fd;
    // no file just create
    if ((fp = fopen("hello.txt", "w+")) == NULL)
    {
        printf("fopen file error\n");
        return 0;
    }
    fprintf(fp, "hello word.\n");
    fclose(fp);
    // 
    if((fd = open("hello.txt", O_RDWR)) == -1)
    {
        printf("open file fail\n");
        return 0;
    }
    if((fp = fdopen(fd, "a+")) == NULL)
    {
        printf("fdopen open\n");
        return 0;
    }
    fprintf(fp, "linux c program.\n");

    return 0;
}





