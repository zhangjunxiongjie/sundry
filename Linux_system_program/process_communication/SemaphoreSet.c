#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define DELAY_TIME 3  // delay 3 second 

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};

// init semaphore
int init_sem(int sem_id, int init_value)
{
    union semun sem_union;
    sem_union.val = init_value;
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
    {
        perror("Initialize semaphore");
        return -1;
    }
    return 0;
}

// destroy semaphore
int del_sem(int sem_id)
{
    union semun sem_union;
    if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
    {
        perror("Delete semaphore");
        return -1;
    }
}

// P operation function
int sem_P(int sem_id)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;
    
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        perror("P operation");
        return -1;
    }
    return 0;
}

// V operation function
int sem_V(int sem_id)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;

    if (semop(sem_id, &sem_b, 1) == -1)
    {
        perror("V operation");
        return -1;
    }
    return 0;
}


int main(void)
{
    pid_t result;
    int sem_id;
    
    sem_id = semget(ftok(".", 'a'), 1, 0666|IPC_CREAT);
    init_sem(sem_id, 0);
    
    result = fork();
    
    if (result == -1)
    {
        perror("Fork\n");
    }
    else if (result == 0)
    {
        printf("Child progress will wait for some seconds...\n");
        sleep(DELAY_TIME);
        printf("The returned value is %d in the child progress(PID=%d)\n", result, getpid()); 
        sem_V(sem_id);
    }
    else
    {
        sem_P(sem_id); // two value semaphore, wait child proccess V operation.
        
        printf("The returned value is %d in the father progress(PID=%d)\n", result, getpid());
        sem_V(sem_id);
        del_sem(sem_id);
    }
    exit(0);
}


