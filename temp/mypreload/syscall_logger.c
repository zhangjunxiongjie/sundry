// 
#include "syscall_logger.h"

extern int InterceptLogPathFd;
extern char MatchTarget[BUFMAXSIZE];

void write_intercept_log(const char *target)
{
	// time
	struct tm *nowTime;
	char timeStr[40];
	memset(timeStr, '\0', sizeof(timeStr));
	time_t t;

	syscall_no_intercept(SYS_time, &t); // get timestamp
	nowTime = localtime(&t); // to local time
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", nowTime); // to string
	
	// usr id
	unsigned int processUid = getuid();

	// process id
	pid_t processPid = getpid();

	// target // ip or filename
	// target.

	// domain or ipaddr or match keywords.
	// MatchTarget

	char buffer[BUFMAXSIZE];
	memset(buffer, '\0', BUFMAXSIZE);
	if ((strlen(timeStr) + strlen(target) + strlen(MatchTarget)) > 200){
		// sprintf(buffer, "%clog iter may overflow!", (char)strlen("log iter may overflow!"));
		// syscall_no_intercept(SYS_write, InterceptLogPathFd, buffer, strlen(buffer));
		return ;	
	}
	// time:uid:pid:target:keywords
	sprintf(buffer, "%s:%d:%d:%s:%s", timeStr, processUid, processPid, target, MatchTarget);
	
	char formatBuffer[BUFMAXSIZE];
	memset(formatBuffer, '\0', BUFMAXSIZE);
	sprintf(formatBuffer, "%c%s", (char)strlen(buffer), buffer);
	syscall_no_intercept(SYS_write, InterceptLogPathFd, formatBuffer, strlen(formatBuffer));
}

