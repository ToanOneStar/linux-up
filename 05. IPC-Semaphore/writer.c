#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>

pthread_t thread1, thread2;
sem_t unnamedSem;

void *threadHandle(void *argv)
{
    pthread_t pthread_id = pthread_self();
    int val;
    if (pthread_equal(pthread_id, thread1))
    {
        sem_wait(&unnamedSem);
        printf("This is Thread 1... \n");
        sem_getvalue(&unnamedSem, &val);
        printf("Gia tri semaphore hien tai: %d\n", val);
        sleep(5);
        printf("Thread 1 da hoan thanh xong cong viec\n");
        sem_post(&unnamedSem);
        sem_getvalue(&unnamedSem, &val);
        printf("Gia tri semaphore hien tai: %d\n", val);
        pthread_exit(&pthread_id);
    }
    else if (pthread_equal(pthread_id, thread2))
    {
        sem_wait(&unnamedSem);
        printf("This is Thread 2... \n");
        sem_getvalue(&unnamedSem, &val);
        printf("Gia tri semaphore hien tai: %d\n", val);
        sleep(5);
        printf("Thread 2 da hoan thanh xong cong viec\n");
        sem_post(&unnamedSem);
        sem_getvalue(&unnamedSem, &val);
        printf("Gia tri semaphore hien tai: %d\n", val);
        pthread_exit(&pthread_id);
    }
}

int main(int argc, char const *argv[])
{
    int fd = sem_init(&unnamedSem, 0, 1);
    int status = pthread_create(&thread1, NULL, threadHandle, NULL);
    if (status != 0)
    {
        perror("Failed to create thread");
        return 1;
    }
    status = pthread_create(&thread2, NULL, threadHandle, NULL);
    if (status != 0)
    {
        perror("Failed to create thread");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&unnamedSem);
    return 0;
}