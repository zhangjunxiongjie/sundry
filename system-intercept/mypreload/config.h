#ifndef CONFIG_H
#define CONFIG_H

// log file path
#ifndef INTERCEPT_LOG_PATH
    #define INTERCEPT_LOG_PATH  "/home/murongyuyue/bin/trace.log.bin"
#endif // INTERCEPT_LOG_PATH

// file match string file
#ifndef ACCESS_CONTROL_FILE
    #define ACCESS_CONTROL_FILE "/home/murongyuyue/bin/access_control_file.config.bin"
#endif // ACCESS_CONTROL_FILE

// network  match string file
#ifndef ACCESS_CONTROL_NET
    #define ACCESS_CONTROL_NET  "/home/murongyuyue/bin/access_control_net.config.bin"
#endif // ACCESS_CONTROL_NET

#ifndef CONTROL_PATH
    #define CONTROL_PATH "/home/murongyuyue"
#endif // CONTROL_PATH

#ifndef IGNORE_PATH
    #define IGNORE_PATH "/home/murongyuyue/bin"
#endif // IGNORE_PATH

// create file flag.
#ifndef CREATE_FILE_FLAGS
    #define CREATE_FILE_FLAGS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)   
#endif // CREATE_FILE_FLAGS

// buffer max size.
#ifndef BUFMAXSIZE
    #define BUFMAXSIZE 256
#endif

// path max size.
#ifndef PATH_MAX
    #define PATH_MAX 4096
#endif

#endif // CONFIG_H

