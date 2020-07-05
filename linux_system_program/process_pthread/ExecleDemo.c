#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ??? environment unchange
    char *envp[] = {"PATH=/home/murongyuyue/", "USER=murongyuyue", NULL}; // environment
    if(fork() == 0)
    {
        if(execle("/bin/ls", "ls", "-l", NULL, envp) < 0)
            perror("execle error!");
    }
    pid_t childProcess = wait(NULL);
    printf("I am parent process, my child process id is: %d\n", childProcess);

    return 0;
}
