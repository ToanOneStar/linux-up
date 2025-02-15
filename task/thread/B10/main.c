#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10
#define TASK_SIZE 1000000

long long simple_task(int n)
{
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        total += i;
    }
    return total;
}

void *thread_task(void *arg)
{
    for (int i = 0; i < NUM_THREADS; i++)
    {
        simple_task(TASK_SIZE);
    }
    return NULL;
}

int main()
{
    clock_t start, end;
    double single_thread_time, multi_thread_time;

    // single-thread
    start = clock();
    simple_task(TASK_SIZE);
    end = clock();
    single_thread_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // multi-thread
    pthread_t threads[NUM_THREADS];
    start = clock();
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_task, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    end = clock();
    multi_thread_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Single-thread time: %f seconds\n", single_thread_time);
    printf("Multi-thread time: %f seconds\n", multi_thread_time);

    return 0;
}
