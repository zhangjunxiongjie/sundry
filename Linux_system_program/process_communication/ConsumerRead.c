#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct BufferPool
{
    char Buffer[5][100];
    int Index[5];
};

int main()
{
    int running = 1;
    void *shm = NULL;
    struct BufferPool *shared;
    int shmid;
    int index;
    shmid = shmget((key_t)1234, sizeof(struct BufferPool), 0666|IPC_CREAT);
    if (shmid == -1)
    {
        exit(EXIT_FAILURE);
    }
    
    shm = shmat(shmid, 0, 0);
    if (shm == (void*)-1)
    {
        exit(EXIT_FAILURE);
    }
    shared = (struct BufferPool*)shm;
    
    while (running)
    {
        index = 0;
        if (shared->Index[index] == 1)
        {
            printf("consume buffer: %s", shared->Buffer[index]);
            shared->Index[index] = 0;
            sleep(rand() % 3);
            if (strncmp(shared->Buffer[index], "end", 3) == 0)
                running = 0;
        }
        else
        {
            sleep(1);
            index++;
        }
    }
    
    if (shmdt(shm) == -1)
    {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}


