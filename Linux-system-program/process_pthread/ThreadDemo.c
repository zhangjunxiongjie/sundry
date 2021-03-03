#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *child_thread(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        // thread id is unsigned long int. 
        printf("my thread id: %lu ", pthread_self());
        printf("child thread message %d\n", i);
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    printf("create child thread\n");
    pthread_create(&tid, NULL, (void*)child_thread, NULL);
    pthread_join(tid, NULL);
    printf("child thread '%lu' exit\n", tid);
    
    return 0;
}
