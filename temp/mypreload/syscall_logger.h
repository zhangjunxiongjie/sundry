// 
#ifndef SYSCALL_LOGGER_H
#define SYSCALL_LOGGER_H

#include "config.h"
#include <libsyscall_intercept_hook_point.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void write_intercept_log(const char *target);

#endif