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


void analysis_file_edittime(time_t lastEditTime)
{
    char *timeFormat = ctime(&lastEditTime);
    timeFormat[strlen(timeFormat) - 1] = '\0';
    printf(" %s", timeFormat);
}
void analysis_file_groupname(gid_t gid)
{
    struct group *groupAttribute = getgrgid(gid);
    printf(" %s", groupAttribute->gr_name);
}
void analysis_file_username(uid_t uid)
{
    struct passwd *userAttribute = getpwuid(uid);
    printf(" %s", userAttribute->pw_name);
}
void analysis_file_authority(mode_t st_mode)
{
    if ((S_IRUSR & st_mode) == S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if ((S_IWUSR & st_mode) == S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if ((S_IXUSR & st_mode) == S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    if ((S_IRGRP & st_mode) == S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if ((S_IWGRP & st_mode) == S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if ((S_IXGRP & st_mode) == S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    if ((S_IROTH & st_mode) == S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if ((S_IWOTH & st_mode) == S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if ((S_IXOTH & st_mode) == S_IXOTH)
    {
        printf("x.");
    }
    else
    {
        printf("-.");
    }
}
void analysis_file_type(mode_t st_mode)
{
    if (S_ISREG(st_mode))
    {
        printf("-");
    }
    else if (S_ISDIR(st_mode))
    {
        printf("d");
    }
    else if (S_ISCHR(st_mode))
    {
        printf("c");
    }
    else if (S_ISBLK(st_mode))
    {
        printf("b");
    }
    else if (S_ISFIFO(st_mode))
    {
        printf("p");
    }
    else if (S_ISSOCK(st_mode))
    {
        printf("s");
    }
    /*
    else if (S_ISLINK(st_mode))
    {
        printf("l");
    }*/
    else
    {
        printf("?");
    }
}
void get_file_attribute(char *filePath)
{
    struct stat buf;
    if (stat(filePath, &buf) < 0)
    {
        printf("get %s attribute fail!\n", filePath);
    }
    analysis_file_type(buf.st_mode);
    analysis_file_authority(buf.st_mode);
    printf(" %d", buf.st_nlink);
    analysis_file_username(buf.st_uid);
    analysis_file_groupname(buf.st_gid);
    printf(" %d", buf.st_size);
    analysis_file_edittime(buf.st_mtime);

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
            // printf("%s\n", buf);
            get_file_attribute(buf);
            printf(" %s\n", currentdp->d_name);
        }           
        closedir(dirStruct);
    }

    return ;
}

int main(int argc, char *argv[])
{
    if (argc == 2 || argc == 3) // hava directory or have not directory
    {
        if (strcmp(argv[1], "-l") == 0) // 
        {
            char *path;
            char buf[255];
            if (argc == 2)
            {
                getcwd(buf, sizeof(buf));               
                path = buf;
            }
            else
            {
                path = argv[2];
            }
            
            ls_l_dir(path);
        }
        else // 
        {
            printf("parameter not match!\n");
            exit(1);
        }
    }
    else
    {
        printf("terra incognita!\n");
        exit(1);
    }

    return 0;
}


