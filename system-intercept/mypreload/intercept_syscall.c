#include "intercept_syscall.h"

extern char FileName[PATH_MAX + 1];

long intercept_openat(long syscall_number,
                      long arg0, long arg1,
                      long arg2, long arg3,
                      long arg4, long arg5)
{
    long fd = syscall_no_intercept(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);

    struct stat path_stat;
    memset(&path_stat, 0, sizeof(struct stat));
    stat(FileName, &path_stat); // get stat
    mode_t pathMode = path_stat.st_mode;
    off_t pathSize = path_stat.st_size;
    
    // ignore policy and log file.
    if (ignore_match(FileName) == 0){
        return fd;
    }
    else if (keywords_match(FileName) == 0){ // path match.
        write_intercept_log(FileName);
        return -1;
    }
    else if (fd != -1 && S_ISREG(pathMode)){ // content keyword match. only match common file. 
        char *buffer = (char *)malloc(pathSize + 1); // ??? request
        memset(buffer, '\0', (pathSize + 1));

        if (syscall_no_intercept(SYS_read, fd, (long)buffer, pathSize) == pathSize) // overflow
        {
            buffer[pathSize] = '\0';
            if (keywords_match(buffer) == 0)
            {
                syscall_no_intercept(SYS_close, fd);
                free(buffer);

                write_intercept_log(FileName);
                return -1;
            }
        }

        // move file pointer to file begin.
        syscall_no_intercept(SYS_lseek, fd, 0, SEEK_SET, arg3, arg4, arg5);
        free(buffer);

        return fd;
    }
    else {
        if (fd == -1){
            return syscall_no_intercept(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);
        }
        else {
            return fd;    
        }
    }
}


extern char RedirectObject[BUFMAXSIZE];  // ip addr.
long intercept_connect(long syscall_number,
                       long arg0, long arg1,
                       long arg2, long arg3,
                       long arg4, long arg5)

{
    long result;

    // ??? this may request
    struct sockaddr_in *sa_data = (struct sockaddr_in *)arg1;
    struct in_addr sin_addr = sa_data->sin_addr;
    // network sequence
    char *ip_addr_str = inet_ntoa(sin_addr); // integer to string;

    if (netaddr_match(ip_addr_str) == 0) {
        write_intercept_log(ip_addr_str);

        inet_aton(RedirectObject, &sin_addr);
        (*sa_data).sin_addr = sin_addr;
        (*sa_data).sin_port = 80;
        
        // redirect connect.
        result = syscall_no_intercept(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);
    }
    else {
        result = syscall_no_intercept(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);
    }
    
    return result;
}


