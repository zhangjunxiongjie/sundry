// match arithmetic

#include "arithmetic.h"

int InterceptLogPathFd = -1;
int AccessControlFileFd = -1;
int AccessControlNetFd = -1;

// write log.
char MatchTarget[BUFMAXSIZE]; // network target or keywords.
// intercept redirect.
char RedirectObject[BUFMAXSIZE]; // ip addr.


static void Next(const char *T, int *next){
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < strlen(T)){
		if ((j == 0) || (T[i - 1] == T[j - 1])){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}

int KMP(const char *S, const char *T)
{
    int next[strlen(T)];
    Next(T, next);

    int i=1;
    int j=1;
    while (i <= strlen(S) && j <= strlen(T)) {
                
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if (j>strlen(T)) {
        return i-(int)strlen(T);
    }

    return -1;
}


// ignore config or log file.
int ignore_match(const char *S)
{
	int result = -1;
	if (KMP(S, IGNORE_PATH) == 1){
		result = 0;
	}
	else {
		result = -1;
	}

	return result;
}

// if match finish return 0 else match fail return -1.
int keywords_match(const char *S) // ssize_t == long
{
	int result = -1;

	char keywordSize = '\0';
	while (syscall_no_intercept(SYS_read, AccessControlFileFd, &keywordSize, 1) == 1) {
		char buffer[BUFMAXSIZE];
		memset(buffer, '\0', BUFMAXSIZE);
		
		syscall_no_intercept(SYS_read, AccessControlFileFd, buffer, keywordSize);
		
		result = KMP(S, buffer) > 0 ? 0 : -1;
		if (result == 0){
			memcpy(MatchTarget, buffer, sizeof(buffer)); // 
			break;
		}
	}
	
	syscall_no_intercept(SYS_lseek, AccessControlFileFd, 0, SEEK_SET);
	return result;
}

// parameter S ip_addr host_seq. if all match return 0, else return -1.   
int netaddr_match(const char *S) // into ip addr.
{
	int result = -1;
	
	char netTargetSize ='\0';
	char redirectTargetSize = '\0';
	char netObjectSize = '\0';
	char redirectObjectSize = '\0';
	while (syscall_no_intercept(SYS_read, AccessControlNetFd, &netTargetSize, 1) == 1) {
		char netTarget[BUFMAXSIZE];
		memset(netTarget, '\0', BUFMAXSIZE);
		char redirectTarget[BUFMAXSIZE];
		memset(redirectTarget, '\0', BUFMAXSIZE);
		char netObject[BUFMAXSIZE];
		memset(netObject, '\0', BUFMAXSIZE);
		char redirectObject[BUFMAXSIZE];
		memset(redirectObject, '\0', BUFMAXSIZE);

		syscall_no_intercept(SYS_read, AccessControlNetFd, netTarget, netTargetSize);

		syscall_no_intercept(SYS_read, AccessControlNetFd, &redirectTargetSize, 1);
		syscall_no_intercept(SYS_read, AccessControlNetFd, redirectTarget, redirectTargetSize);

		syscall_no_intercept(SYS_read, AccessControlNetFd, &netObjectSize, 1);
		syscall_no_intercept(SYS_read, AccessControlNetFd, netObject, netObjectSize);

		syscall_no_intercept(SYS_read, AccessControlNetFd, &redirectObjectSize, 1);
		syscall_no_intercept(SYS_read, AccessControlNetFd, redirectObject, redirectObjectSize);

		// strcmp must \0 finish.
		if (strcmp(S, netObject) == 0){
			memcpy(MatchTarget, netTarget, sizeof(netTarget)); // write log.
			memcpy(RedirectObject, redirectObject, sizeof(redirectObject)); // intercept redirect.
			result = 0;
			break;
		}
		else {
			result = -1; // 0 success. -1 fail
		}
	}

	syscall_no_intercept(SYS_lseek, AccessControlNetFd, 0, SEEK_SET);
	return result;
}
