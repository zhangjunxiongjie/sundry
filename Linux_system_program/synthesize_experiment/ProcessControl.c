#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEST "./zhangjunxiong"

// can not judge file type.!!!
int is_dir(mode_t st_mode)
{
    if (S_ISDIR(st_mode))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void get_file_attribute(char *filePath, char *path, char *fileName)
{
    struct stat buf;

    stat(filePath, &buf);

    if (is_dir(buf.st_mode) == 1);
    {
        printf("%s\n", filePath);
        
        pid_t pid = fork();
        if (pid < 0)
        {
            printf("fork fail!\n");
            exit(-1);
        }
        else if (pid == 0)
        {
            char charBuf[255] = DEST;
            strcat(charBuf, "/");
            strcat(charBuf, fileName);
                
            // printf("%s:%s:%s\n", path, filePath, charBuf);
            execl("./MyCp.o", path, filePath, charBuf, NULL);   
        }
        else
        {
            wait(-1); //
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
        
        char buf[512] = "";
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
            // printf("%s\n", currentdp->d_name);
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
            getcwd(buf, sizeof(buf)); // get work directory              
            path = buf;
        }
        else
        {
            path = argv[1];
        }
            
        ls_l_dir(path);
    }
    else
    {
        printf("terra incognita!\n");
        exit(1);
    }

    return 0;
}


