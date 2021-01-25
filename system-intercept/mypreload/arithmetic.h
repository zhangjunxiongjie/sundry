#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "config.h"
#include "syscall_logger.h"
#include <libsyscall_intercept_hook_point.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//
int KMP(const char *S, const char *T);

// ignore file match.
int ignore_match(const char *S);

// match finish return == 0 else return == -1;
// int str_match(const char *S, ssize_t nbytes);
int keywords_match(const char *S);

// parameter S ip_addr host_seq. if all match return 0, else return -1. 
int netaddr_match(const char *S);

#endif
