#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2, thread_id3;

typedef struct
{
    char name[30];
    char msg[30];
} thr_data_t;

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

static void *thr_handle3(void *args)
{
    pthread_detach(pthread_self());
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

    // while (1)
    // {
    //     if (ret = pthread_create(&thread_id3, NULL, &thr_handle3, NULL))
    //     {
    //         printf("pthread_create() error number = %d\n", ret);
    //         break;
    //     }
    //     counter++;
    //     if (counter % 1000 == 0)
    //     {
    //         printf("Thread created: %d\n", counter);
    //     }
    // }
    while (1)
        ;
    return 0;
}
