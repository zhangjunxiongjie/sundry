#include "apue.h"
#include <sys/wait.h>

static void sig_int(int); /**/

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int exitProcessStatus;
	
	// signal catch
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error.");

	printf("%% "); // 
	while (fgets(buf, MAXLINE, stdin) != NULL){
		if (buf[strlen(buf) - 1] == '\n'){	
			buf[strlen(buf) - 1] = 0; // '\0'
		}

		if (strcmp(buf, "exit") == 0){
			exit(0);
		}
		else if (strcmp(buf, "quit") == 0){
			exit(0);
		}

		if ((pid = fork()) < 0){ // fork error
			err_sys("fork error.");
		}
		else if(pid == 0){ // child process
			execlp(buf, buf, (char *)0);
			err_ret("clouldn't execute: %s.", buf);
			exit(127);
		}
		else{ // parent process
			if ((pid = waitpid(pid, &exitProcessStatus, 0)) < 0) // wait child process.
				err_sys("waitpid error.");
		
			printf("%% ");
		}
	}

	printf("\n"); // EOF

	exit(0);
}

// signal throw. processing.
void sig_int(int signo)
{
	printf("interrupt\n%% ");
}





