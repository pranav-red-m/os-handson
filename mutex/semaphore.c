#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t s1;

void* mythread(void* arg)
{
    sem_wait(&s1);

    printf("\nEntered...\n");
    sleep(4);
    printf("Exiting\n");

    sem_post(&s1);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&s1, 0, 1);

    pthread_create(&t1, NULL, mythread, NULL);
    sleep(2);
    pthread_create(&t2, NULL, mythread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&s1);
    return 0;
}
