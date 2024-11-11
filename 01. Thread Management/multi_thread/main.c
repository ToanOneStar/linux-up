#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER; // khởi tạo

int counter = 2; // shared variable/shared resources/global variable

static void *handle_th1(void *args)
{
    pthread_mutex_lock(&lock1);
    // critical section
    printf("thread1 handler, counter: %d\n", ++counter);
    pthread_mutex_unlock(&lock1);
}

static void *handle_th2(void *args)
{
    sleep(5);
    pthread_mutex_lock(&lock1);
    printf("thread2 handler, counter: %d\n", ++counter);
    pthread_mutex_unlock(&lock1);
}

int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    pthread_t thread_id1, thread_id2;

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &handle_th2, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    sleep(7);
    // used to block for the end of a thread and release
    return 0;
}
