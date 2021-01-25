
#include "start.h"

char FileName[PATH_MAX + 1];

static int
hook(long syscall_number,
		long arg0, long arg1,
		long arg2, long arg3,
		long arg4, long arg5,
		long *result)
{

	if (syscall_number == SYS_connect){
		*result = intercept_connect(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);
		return 0;
	}
	else if (syscall_number == SYS_openat){

		long fd = syscall_no_intercept(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);
		if (fd == 0){
			return 1;
		}
		else {
			ssize_t r;
			char proclnk[BUFMAXSIZE + 1];
			memset(proclnk, '\0', BUFMAXSIZE + 1);
			// getFileName.
			sprintf(proclnk, "/proc/self/fd/%d", (int)fd);
			r = syscall_no_intercept(SYS_readlink, proclnk, FileName, PATH_MAX);
			FileName[r++] = '\0';

			syscall_no_intercept(SYS_close, fd);

			if (KMP(FileName, CONTROL_PATH) == 1){ // control.
				*result = intercept_openat(syscall_number, arg0, arg1, arg2, arg3, arg4, arg5);
				return 0;
			}
			else {
				return 1;
			}
		}
	}
	else {
		return 1;
	}
}

extern int InterceptLogPathFd;
extern int AccessControlFileFd;
extern int AccessControlNetFd;

static __attribute__((constructor)) void
start(void)
{
	// open kernel file. 
	InterceptLogPathFd = (int)syscall_no_intercept(SYS_open, INTERCEPT_LOG_PATH, (O_WRONLY | O_CREAT | O_APPEND), CREATE_FILE_FLAGS);
	AccessControlFileFd = (int)syscall_no_intercept(SYS_open, ACCESS_CONTROL_FILE, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	AccessControlNetFd = (int)syscall_no_intercept(SYS_open, ACCESS_CONTROL_NET, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);

	if ((InterceptLogPathFd == -1) || (AccessControlFileFd == -1) || (AccessControlNetFd == -1))
		syscall_no_intercept(SYS_exit_group, 4);

	intercept_hook_point = &hook;
}

