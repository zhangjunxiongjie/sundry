// access control.

#include "access_control.h"

int InterceptLogPathFd = -1;
int AccessControlFileFd = -1;
int AccessControlNetFd = -1;

void print_help()
{
	printf("    -p   print policy.\n");
	printf("    -log print intercept log.\n");
	printf("    -h   print help.\n");
	printf("    -ca  clean all policy.\n");
	printf("    -cn  clean network policy.\n");
	printf("    -ck  clean keywords policy.\n");
	printf("    -clog clean intercept log.\n");
	printf("    -k   intercept keywords.\n");
	printf("    -n   intercept domain or ip.\n");
	printf("    -r   redirect domain or ip. default ip 127.0.0.1.\n");  
}

void print_log()
{
	char logIter[BUFMAXSIZE];
	memset(logIter, '\0', BUFMAXSIZE);
	InterceptLogPathFd = open(INTERCEPT_LOG_PATH, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	
	char iterBytesNumber = '\0';
	while (read(InterceptLogPathFd, &iterBytesNumber, 1) == 1){
		if (read(InterceptLogPathFd, logIter, iterBytesNumber) == iterBytesNumber){
			write(STDOUT_FILENO, logIter, iterBytesNumber);
			write(STDOUT_FILENO, "\n", 1);
		}
		else // format error
		{
			break;
		}
	}

	close(InterceptLogPathFd);
}
void print_policy()
{
	char keyPolicy[BUFMAXSIZE];
	memset(keyPolicy, '\0', BUFMAXSIZE);
	AccessControlFileFd = open(ACCESS_CONTROL_FILE, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	AccessControlNetFd = open(ACCESS_CONTROL_NET, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	
	printf("file control policy:\n");
	printf("--------------------\n");
	char iterBytesNumber = '\0';
	while (read(AccessControlFileFd, &iterBytesNumber, 1) == 1){
		if (read(AccessControlFileFd, keyPolicy, iterBytesNumber) == iterBytesNumber){
			write(STDOUT_FILENO, keyPolicy, iterBytesNumber);
			write(STDOUT_FILENO, "\n", 1);
		}
		else // format error
		{
			break;
		}
	}

	printf("\n");
	printf("network control policy:\n");
	printf("-----------------------\n");
	char netTargetSize ='\0';
	char redirectTargetSize = '\0';
	char netObjectSize = '\0';
	char redirectObjectSize = '\0';
	while (read(AccessControlNetFd, &netTargetSize, 1) == 1){
		char netTarget[BUFMAXSIZE] = {'\0'};
		char redirectTarget[BUFMAXSIZE] = {'\0'};
		char netObject[BUFMAXSIZE] = {'\0'};
		char redirectObject[BUFMAXSIZE] = {'\0'};
		read(AccessControlNetFd, netTarget, netTargetSize);

		read(AccessControlNetFd, &redirectTargetSize, 1);
		read(AccessControlNetFd, redirectTarget, redirectTargetSize);

		read(AccessControlNetFd, &netObjectSize, 1);
		read(AccessControlNetFd, netObject, netObjectSize);

		read(AccessControlNetFd, &redirectObjectSize, 1);
		read(AccessControlNetFd, redirectObject, redirectObjectSize);
		
		write(STDOUT_FILENO, netTarget, netTargetSize);
		write(STDOUT_FILENO, "--->", 4);
		write(STDOUT_FILENO, redirectTarget, redirectTargetSize);
		write(STDOUT_FILENO, "   ", 3);
		write(STDOUT_FILENO, netObject, netObjectSize);
		write(STDOUT_FILENO, "--->", 4);
		write(STDOUT_FILENO, redirectObject, redirectObjectSize);
		write(STDOUT_FILENO, "\n", 1);
	}

	close(AccessControlFileFd);
	close(AccessControlNetFd);
}

void clean_key_policy()
{
	remove(ACCESS_CONTROL_FILE);
	AccessControlFileFd = open(ACCESS_CONTROL_FILE, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	if (AccessControlFileFd < 0){
		// error handle.
	}
	else {
		close(AccessControlFileFd);
		printf("clean keywords policy success!\n");
	}
}
void clean_net_policy()
{
	remove(ACCESS_CONTROL_NET);
	AccessControlNetFd = open(ACCESS_CONTROL_NET, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	if (AccessControlNetFd < 0){
		// error handle.
	}
	else {
		close(AccessControlNetFd);
		printf("clean internet policy success!\n");
	}
}
void clean_all_policy()
{
	clean_key_policy();
	clean_net_policy();
}

void clean_all_log()
{
	remove(INTERCEPT_LOG_PATH);
	InterceptLogPathFd = open(INTERCEPT_LOG_PATH, (O_RDONLY | O_CREAT), CREATE_FILE_FLAGS);
	if (InterceptLogPathFd < 0){
		// error handle.
	}
	else {
		close(InterceptLogPathFd);
		printf("clean intercept log file success!\n");
	}
}

void set_keywords_policy(char *keywords)
{
	// 5 ~ (BUFMAXSIZE - 1) char
	if (strlen(keywords) < 5){ // end \0
		printf("error %s: The number of characters in the keyword is insufficient!\n", keywords);
	}
	else if (strlen(keywords) >= (BUFMAXSIZE - 1)){ // end \0
		printf("error : There are too many characters in the keywords!\n");
	}
	else {
		char keyPolicy[BUFMAXSIZE];
		memset(keyPolicy, '\0', BUFMAXSIZE);
		AccessControlFileFd = open(ACCESS_CONTROL_FILE, (O_WRONLY | O_APPEND | O_CREAT), CREATE_FILE_FLAGS);
		sprintf(keyPolicy, "%c%s", (char)strlen(keywords), keywords);
		
		write(AccessControlFileFd, keyPolicy, strlen(keyPolicy)); // buffer 

		close(AccessControlFileFd);
	}
}

// is return 0 else return -1
int is_ipaddr(const char *str)
{
	const char *tp = str;
	while (*tp == '.' || ('0' <= *tp && *tp <= '9')){
		tp++;
	}
	
	if (*tp == '\0'){ // ip addr
		return 0;
	}
	else{ // domain.
		return -1;
	}
	
}

void format_output_netpolicy_file(const char *netTarget, const char *redirectTarget, 
								const char *netObject, const char * redirectObject)
{
	char internetPolicy[BUFMAXSIZE];
	memset(internetPolicy, '\0', BUFMAXSIZE);
	AccessControlNetFd = open(ACCESS_CONTROL_NET, (O_WRONLY | O_APPEND | O_CREAT), CREATE_FILE_FLAGS);

	sprintf(internetPolicy, "%c%s%c%s%c%s%c%s", 
			(char)strlen(netTarget), netTarget,                                     // intercept target.
			(char)strlen(redirectTarget), redirectTarget,							// redirect target.
			(char)strlen(netObject), netObject,										// intercept object.
			(char)strlen(redirectObject), redirectObject);							// redirect object.
	
	write(AccessControlNetFd, internetPolicy, strlen(internetPolicy));

	close(AccessControlNetFd);
}

void set_internet_policy(const char *netTarget,const char *redirectTarget) // net may is ip or domain. redirect may is ip or domain.
{
	if ((strlen(netTarget) < 3) || (strlen(redirectTarget) < 3)){ // domain or ipaddr.
		printf("error %s: The number of characters in the netpolicy is insufficient!\n", netTarget);
	}
	else if ((strlen(netTarget) >= (BUFMAXSIZE - 1)) || (strlen(redirectTarget) >= (BUFMAXSIZE - 1))){
		printf("error : There are too many characters in the netpolicy!\n");
	}
	else {

		if ((is_ipaddr(netTarget) == 0) && (is_ipaddr(redirectTarget) == 0)){ // all ip
			format_output_netpolicy_file(netTarget, redirectTarget, netTarget, redirectTarget);
		}
		else if (is_ipaddr(redirectTarget) == 0){
			struct hostent *hptr = gethostbyname(netTarget);
			if (hptr == NULL){
				// intercept target error.
			}
			else {
				char **pptr = hptr->h_addr_list;
				char internetBuffer[INET_ADDRSTRLEN];
				while (*pptr != NULL){
					const char *netIpAddr = inet_ntop(hptr->h_addrtype, *pptr, internetBuffer, sizeof(internetBuffer));
					format_output_netpolicy_file(netTarget, redirectTarget, netIpAddr, redirectTarget);
					pptr++;
				}
			}
		}
		else if (is_ipaddr(netTarget) == 0){
			struct hostent *hptr = gethostbyname(redirectTarget);
			if (hptr == NULL){
				// redirect error.
			}
			else {
				char **pptr = hptr->h_addr_list;
				char redirectBuffer[INET_ADDRSTRLEN];
				if (*pptr != NULL){
					const char *redirectIpAddr = inet_ntop(hptr->h_addrtype, *pptr, redirectBuffer, sizeof(redirectBuffer));
					format_output_netpolicy_file(netTarget, redirectTarget, netTarget, redirectIpAddr);
				}
				else {
					format_output_netpolicy_file(netTarget, redirectTarget, netTarget, DEFAULT_REDIRECT_TARGET);
				}
			}
		}
		else { // all domain.
			struct hostent *hptr = gethostbyname(redirectTarget);
			if (hptr == NULL){
				hptr = gethostbyname(netTarget);
				if (hptr == NULL){
					// intercept target error.
				}
				else {
					char **pptr = hptr->h_addr_list;
					char internetBuffer[INET_ADDRSTRLEN];
					while (*pptr != NULL){
						const char *netIpAddr = inet_ntop(hptr->h_addrtype, *pptr, internetBuffer, sizeof(internetBuffer));
						format_output_netpolicy_file(netTarget, redirectTarget, netIpAddr, DEFAULT_REDIRECT_TARGET);
						pptr++;
					}
				}
			}
			else {
				char **pptr = hptr->h_addr_list;
				char internetBuffer[INET_ADDRSTRLEN];
				char redirectBuffer[INET_ADDRSTRLEN];
				if (*pptr != NULL){
					const char *redirectIpAddr = inet_ntop(hptr->h_addrtype, *pptr, redirectBuffer, sizeof(redirectBuffer));

					hptr = gethostbyname(netTarget);
					if (hptr == NULL){
						// intercept target error.
					}
					else {
						pptr = hptr->h_addr_list;
						while (*pptr != NULL){
							const char *netIpAddr = inet_ntop(hptr->h_addrtype, *pptr, internetBuffer, sizeof(internetBuffer));
							format_output_netpolicy_file(netTarget, redirectTarget, netIpAddr, redirectIpAddr);
							pptr++;
						}
					}
				}
			}
		}
	}

}

void two_argc_handle(char *argv[])
{
	
	if (strcmp(argv[1], PRINT_HELP) == 0){
		print_help();
	}
	else if (strcmp(argv[1], PRINT_LOG) == 0){
		print_log();
	}
	else if (strcmp(argv[1], PRINT_POLICY) == 0){
		print_policy();
	}
	else if (strcmp(argv[1], CLEAN_ALL_POLICY) == 0){
		clean_all_policy();
	}
	else if (strcmp(argv[1], CLEAN_KEY_POLICY) == 0){
		clean_key_policy();
	}
	else if (strcmp(argv[1], CLEAN_NET_POLICY) == 0){
		clean_net_policy();
	}
	else if (strcmp(argv[1], CLENA_ALL_LOG) == 0){
		clean_all_log();
	}
	else {
		print_help();
	}

}

void three_argc_handle(char *argv[])
{
	
	if (strcmp(argv[1], KEYWORDS_POLICY) == 0){
		set_keywords_policy(argv[2]);
	}
	else if (strcmp(argv[1], INTERNET_POLICY) == 0){
		set_internet_policy(argv[2], DEFAULT_REDIRECT_TARGET);
	}
	else {
		print_help();
	}
	
}

void five_argc_handle(char *argv[])
{
	if ((strcmp(argv[1], INTERNET_POLICY) == 0) && (strcmp(argv[3], REDIRECT_POLICY) == 0)){
		set_internet_policy(argv[2], argv[4]); // 
	}
	else{
		print_help();
	}
}

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
int main(int argc, char *argv[])
{

	switch (argc){
	
	case 2: // -p / -log / -h / -c
		two_argc_handle(argv);
		break;
	case 3: // -n ip / -k keyword. 
		three_argc_handle(argv);
		break;
	case 5: // -n ip -r ip.
		five_argc_handle(argv);
		break;
	default: // -h
		print_help();
		break;
	}

	return 0;
}