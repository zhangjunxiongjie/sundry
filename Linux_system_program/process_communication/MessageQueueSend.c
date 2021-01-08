#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char buffer[1024];
    int msgid = -1;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT); // create message queue
    if (msgid == -1)   // create failed
    {
        fprintf(stderr, "msgget failed with error:");
        exit(EXIT_FAILURE);
    }
    while (running) // 
    {
        printf("Enter some text: ");  // output tips message
        fgets(buffer, 1024, stdin); // input text
        data.msg_type = 1; // message type
        strcpy(data.text, buffer); // 
        if (msgsnd(msgid, (void*)&data, 1024, 0) == -1) // send message
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if (strncmp(buffer, "end", 3) == 0)
            running = 0;
        sleep(1);
    }
    exit(EXIT_SUCCESS);

}








