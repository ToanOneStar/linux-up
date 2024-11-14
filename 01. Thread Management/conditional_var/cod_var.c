#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define THRESHOLD 3

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int counter = 0;

static void *handle_th1(void *args)
{
    pthread_mutex_lock(&lock);
    while (counter < THRESHOLD)
    {
        counter += 1;
        printf("Counter = %d\n", counter);
        sleep(1);
    }

    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    int ret;
    pthread_t thread_id1;

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    pthread_mutex_lock(&lock);
    while (1)
    {
        pthread_cond_wait(&cond, &lock);
        if (counter == THRESHOLD)
        {
            printf("Global variable counter = %d\n", counter);
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    return 0;
}