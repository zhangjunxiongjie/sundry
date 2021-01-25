#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define INTERCEPT_LOG_PATH  "/home/murongyuyue/bin/trace.log.bin"
#define ACCESS_CONTROL_FILE "/home/murongyuyue/bin/access_control_file.config.bin"
#define ACCESS_CONTROL_NET  "/home/murongyuyue/bin/access_control_net.config.bin"

/*
// one
-p print policy
-log print intercept log
-h print help.
-ca clean all policy.
-cn clean network policy.
-ck clean keywords policy.
-clog clean intercept log.
// three.
-k intercept keywords.
// five.
-n intercept domain or ip
-r redirect domain or ip. default ip 127.0.0.1  
*/
#define PRINT_POLICY "-p"
#define PRINT_LOG "-log"
#define PRINT_HELP "-h"

#define CLEAN_ALL_POLICY "-ca"
#define CLEAN_NET_POLICY "-cn"
#define CLEAN_KEY_POLICY "-ck"
#define CLENA_ALL_LOG "-clog"

#define KEYWORDS_POLICY "-k"
#define INTERNET_POLICY "-n"
#define REDIRECT_POLICY "-r"

#define DEFAULT_REDIRECT_TARGET "147.75.47.199"

#define BUFMAXSIZE 256

#define CREATE_FILE_FLAGS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)   

#endif
