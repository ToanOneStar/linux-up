#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define THRESHOLD 3

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int counter = 0; // critical section <=> global resource

static void *handle_th1(void *args)
{
    pthread_mutex_lock(&lock);

    while (counter < THRESHOLD)
    {
        counter += 1;
        printf("Counter: %d\n", counter);
        sleep(1);
    }

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL); // exit
}

int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    pthread_t thread_id1;

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    while (1)
    {
        if (counter == THRESHOLD)
        {
            printf("Global variable counter = %d\n", counter);
            break;
        }
        usleep(500);
    }
    // used to block for the end of a thread and release
    pthread_join(thread_id1, NULL);
    return 0;
}