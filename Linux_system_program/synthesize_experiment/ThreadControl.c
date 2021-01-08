#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int ThreadCounter = 0;

/*
NONEXISTENT = -1,
FILE = 0,
DIRE = 1,
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
        return -1;
    }
}

typedef struct Arguments{
    char src[255];
    char dest[255];
}Arg;
int mini_cp(Arg *arg)
{
    char *src = arg->src;
    char *dest = arg->dest;

    int srcType = path_type(src);
    if (srcType == 1) // directory error feature dispose
    {
        printf("%s a is directory!\n", src);
        free(arg);
        ThreadCounter--;
        return -1;
    }
        
    int fd_src = open(src, O_RDONLY);
    if (fd_src < 0) 
    {
        printf("open source %s fail!\n", src); // print standard error info.
        free(arg);
        ThreadCounter--;
        return -1;
    }
        
    if (strcmp(src, dest) == 0)
    {
        printf("%s the destination path and source path same!\n", dest);
        free(arg);
        ThreadCounter--;
        return -1;
    }
    
    int fd_dest;
    int destType = path_type(dest);    
    if (destType == 0)  // file
    {
        fd_dest = open(dest, O_WRONLY|O_APPEND);
    }
    else if(destType == -1) // nonexistent
    {
        printf("create %s!\n", dest);   
        fd_dest = open(dest, O_WRONLY|O_CREAT, 0744);
    }
    else
    {
        printf("%s is directory!\n", dest);
        free(arg);
        ThreadCounter--;
        return -1;
    }

    if (fd_dest < 0)
    {
        printf("open destination %s fail!\n", dest);
        free(arg);
        ThreadCounter--;
        return -1;
    }
    
    int ret = 0;
    do
    {
        char buf[1024] = "\0";
        ret = read(fd_src, buf, sizeof(buf));
        write(fd_dest, buf, ret);
    }while(ret > 0);
            
    close(fd_dest);
    close(fd_src);
    free(arg);
    ThreadCounter--;
    return 0;
}


void get_file_attribute(char *filePath, char *Path, char* fileName)
{
    if (path_type(filePath) == 0)
    {
        pthread_t tid;
        char dest[255] = "./zhangjunxiong/";
        strcat(dest, fileName);
        
        Arg *arg = (Arg*)malloc(sizeof(Arg)); // 
        strcpy(arg->src, filePath); // 
        strcpy(arg->dest, dest); //
        
        ThreadCounter++;
        pthread_create(&tid, NULL, (void*)mini_cp, arg);
    }
    else // filePath only my is file or directory.
    {
        // 
        if ((strcmp(fileName, ".") == 0) || (strcmp(fileName, "..") == 0))
        {
            printf("%s is a special directory!\n", fileName); 
        }
        else // 
        {
            /*
            pid_t pid = fork();
            if (pid < 0)
            {
                printf("%s directory dispose fail!\n", filePath);
            }
            else if(pid == 0)
            {
                execl("./ThreadControl.o", "", filePath, NULL);   
            }
            else
            {
                printf("create process dispose %s!\n", filePath);
            }
            */
        }
    }
}

void ls_l_dir(char *path)
{
    DIR *dirStruct = opendir(path);
    if (dirStruct == NULL)
    {
        printf("open directory fail!\n");
        exit(-1);
    }
    else
    {
        struct dirent *currentdp;
        
        // dispose each file
        char buf[255] = "";
        strcat(buf, path);
        if (buf[strlen(buf) - 1] != '/')
        {
            strcat(buf, "/");
        }
        int pathLen = strlen(buf);
        while ((currentdp = readdir(dirStruct)) != NULL)
        {
            buf[pathLen] = '\0'; 
            strcat(buf, currentdp->d_name);
            
            get_file_attribute(buf, path, currentdp->d_name);
        }           
        closedir(dirStruct);
    }

    return ;
}

int main(int argc, char *argv[])
{
    if (argc == 1 || argc == 2) // hava directory or have not directory
    {
        char *path;
        char buf[255];
        if (argc == 1)
        {
            getcwd(buf, sizeof(buf));               
            path = buf;
        }
        else
        {
            path = argv[1];
        }
        
        pthread_t tid;
        pthread_create(&tid, NULL, (void*)ls_l_dir, path);
        
        pthread_join(tid, NULL);
        while (ThreadCounter != 0) // wait other cp thread.
        {
            sleep(1);
        }

    }
    else
    {
        printf("terra incognita!\n");
        exit(1);
    }

    return 0;
}



