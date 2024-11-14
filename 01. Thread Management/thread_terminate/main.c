#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2;

static void *thr_handle1(void *args)
{
    sleep(1);
    printf("thread1 handler\n");
    pthread_exit(NULL); // exit
}

static void *thr_handle2(void *args)
{
    sleep(5);
    while (1)
    {
        printf("thread2 handler\n");
        sleep(1);
    };
}

int main(int args, char const *argv[])
{
    int ret, counter = 0;
    int retval;

    if (ret = pthread_create(&thread_id1, NULL, &thr_handle1, NULL))
    {
        printf("pthread_create() error number = %d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &thr_handle2, NULL))
    {
        printf("pthread_create() error number = %d\n", ret);
        return -1;
    }

    while (1)
        ;
    return 0;
}