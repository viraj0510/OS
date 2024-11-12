#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


sem_t readLock, writeLock;
int readerCount = 0;

void* reader(void* arg)
{
    sem_wait(&readLock);
    
    readerCount++;
    if (readerCount == 1)
    {
        sem_wait(&writeLock);
    }
    sem_post(&readLock);
    printf("Reader is reading\n");
    
    sem_wait(&readLock);
    readerCount--;
    if (readerCount == 0)
    {
        sem_wait(&writeLock);
    }
    sem_post(&readLock);
    return NULL;
}

void* writer(void* arg)
{
    sem_wait(&writeLock);

    printf("Writer is writing\n");

    sem_post(&writeLock);
    return NULL;
}

int main()
{
    pthread_t readers[5],writers[5];
    sem_init(&readLock, 0, 1);
    sem_init(&writeLock, 0, 1);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&readers[i],NULL, reader, NULL);
        pthread_create(&writers[i],NULL,writer,NULL);
    }
    
    for (int i = 0; i < 5; i++)
    {
        pthread_join(readers[i],NULL);
        pthread_join(writers[i],NULL);
    }

    sem_destroy(&readLock);
    sem_destroy(&writeLock);

    return 0;
}