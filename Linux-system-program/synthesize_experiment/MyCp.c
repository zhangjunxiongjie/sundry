#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// standard error dispose
#include <errno.h>
extern errorno;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
OTHER = -1,
FILE = 0,
DIRE = 1,
NONEXISTENT = 2
*/
int path_type(const char* path)
{
    struct stat info;
    int r = stat(path, &info);
    if (r == 0)
    {
        if (S_ISDIR(info.st_mode))
            return 1;
        else
            return 0;
    }
    else
    {
        if (errno == ENOENT) // ???
            return 2;
        else
            return -1;
    }
}
// 不能一下子将一个文件多次追加写入另一个文件，
// 要实现的话必须要在关闭文件前将数据刷新到文件系统。
// 通常来说只有程序关闭后才会将所有操作过的文件写入（刷新）文件系统。
int main(int argc, char *argv[])
{
    if (argc >= 3) // 
    {
        int onePathType = path_type(argv[1]);
        if (onePathType == 1) // directory error feature dispose
        {
            printf("%s: path a is directory!\n", argv[1]);
            return -1;
        }
        
        int fd_src = open(argv[1], O_RDONLY);
        if (fd_src < 0)
        {
            perror(argv[1]); // print standard error info.
            return -1;
        }
        
        int destPath = 2;
        for (; destPath < argc; destPath++)
        {
            // 
            if (strcmp(argv[1], argv[destPath]) == 0)
            {
                printf("%s: the destination path and source path same!\n");
                continue;
            }

            int fd_dest;
            int otherPathType = path_type(argv[destPath]);    
            if (otherPathType == 0) // file
            {
                printf("file existed, whether add to the file? please input y/n: ");
                
                char ch = getchar();           
                
                // default add to
                if (ch == 'y')
                {
                    // printf("add to \n");
                    fd_dest = open(argv[destPath], O_WRONLY|O_APPEND); 
                }
                else
                {
                    // printf("cover \n");
                    fd_dest = open(argv[destPath], O_WRONLY|O_TRUNC);
                }
                
                // flush stdin cache area.
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
            else
            {
                if (otherPathType == 2)
                {
                    printf("create %s!\n", argv[destPath]);
                }

                fd_dest = open(argv[destPath], O_WRONLY|O_CREAT, 0744);
                if (fd_dest < 0)
                {
                    perror(argv[destPath]);
                    continue;
                }
            }

            int ret = 0;
            do
            {
                char buf[1024] = "\0";
                ret = read(fd_src, buf, sizeof(buf));
                write(fd_dest, buf, ret);
            }while(ret > 0);
            
            // printf("close %s\n", argv[destPath]);
            close(fd_dest);
        }

        close(fd_src);
    }
    else
    {
        perror("000");
        return -1;
    }

    return 0;
}




