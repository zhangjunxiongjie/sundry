#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
    printf("entering main process---\n");
    if(fork() == 0)
    {
        execl("/bin/ls", "ls", "-l", NULL);
        printf("exiting main process----\n"); // unexecuted 
    }
    
    pid_t childProcess = wait(NULL); // wait child process;
    printf("I am farent process, my child process id is: %d\n", childProcess);
    return 0;
}
