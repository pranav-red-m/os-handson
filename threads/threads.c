#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g = 0;

void *myThreadFunction(void *vargp)
{
    int *myid = (int*)vargp;
    static int s = 0;
    int l = 0;
    ++l;
    ++s;
    ++g;
    printf("Thread ID: %d, Local: %d, Static: %d, Global: %d\n",*myid, l, s, g);
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[3];
    int ids[3];
    for(int i = 0; i < 3; i++)
    {
        ids[i] = i + 1;
        pthread_create(&tid[i], NULL, myThreadFunction, &ids[i]);
        pthread_join(tid[i], NULL);
    }

    printf("In Main()\n");
    return 0;
}
