#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    char name[50];
    int year;
    char phone[20];
    char address[100];
} human_t;

void *thread_handler(void *arg)
{
    int thread_id = *(int *)arg;
    if (thread_id == 1)
    {
        printf("This is thread1.\n");
    }
    else
    {
        human_t *human = (human_t *)arg;
        printf("Name: %s\n", human->name);
        printf("Year of birth: %d\n", human->year);
        printf("Phone: %s\n", human->phone);
        printf("Address: %s\n", human->address);
    }
}

int main()
{
    pthread_t thread1, thread2;
    int thread1_id = 1;
    human_t human = {
        .name = "toan",
        .year = 2004,
        .phone = "0385266989",
        .address = "VietNam"};

    pthread_create(&thread1, NULL, thread_handler, &thread1_id);
    pthread_create(&thread2, NULL, thread_handler, &human);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
