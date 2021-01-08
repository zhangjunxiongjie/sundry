#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int ret;
    char *argv[] = {"ls", "-l", NULL}; // argument list

    printf("entering main process---\n");
    if(fork() == 0)
    {
        ret = execv("/bin/ls", argv);
        if(ret == -1)
        {
            perror("execl error"); // error output
        }
        printf("exiting main process----\n");
    }

    pid_t childProcess = wait(NULL);
    printf("I am parent process, my child process id is: %d\n", childProcess);
    return 0;
}
