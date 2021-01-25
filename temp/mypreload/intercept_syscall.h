#ifndef INTERCEPT_SYSCALL_H
#define INTERCEPT_SYSCALL_H

#include "arithmetic.h"
#include "syscall_logger.h"
#include "config.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <limits.h>

extern int log_fd;

long intercept_openat(long syscall_number,
                    long arg0, long arg1,
                    long arg2, long arg3,
                    long arg4, long arg5);


long intercept_connect(long syscall_number,
                    long arg0, long arg1,
                    long arg2, long arg3,
                    long arg4, long arg5);

#endif