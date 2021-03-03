#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// message struct
struct msg_st
{
    long int msg_type; // 
    char text[1024]; // 
};

int main()
{
    int running = 1;
    
    struct msg_st data; // message 
    long int msgtype = 0; // message type
    
    int msgid = -1; // 
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT); // create message queue
    if (msgid == -1)   // create failed
    {
        fprintf(stderr, "msgget failed with error:");
        exit(EXIT_FAILURE);
    }
    
    while (running) // loop get message
    {
        if (msgrcv(msgid, (void*)&data, 1024, msgtype, 0) == -1) // get message
        {
            fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        printf("You wrote: %s\n", data.text); // print message
        if (strncmp(data.text, "end", 3) == 0) // exit signal
            running = 0;
    }
    
    if (msgctl(msgid, IPC_RMID, 0) == -1) // destroy ???
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);

}








