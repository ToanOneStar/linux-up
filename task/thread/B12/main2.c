#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define FILENAME "thongtinsinhvien.txt"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

typedef struct
{
    char name[30];
    int year;
    char from[30];
} thread_infor_t;

void *handle_th1(void *args)
{
    thread_infor_t *thr = (thread_infor_t *)args;

    while (1)
    {
        pthread_mutex_lock(&lock);

        printf("Nhập tên: ");
        fgets(thr->name, sizeof(thr->name), stdin);
        thr->name[strcspn(thr->name, "\n")] = 0; // Loại bỏ newline

        printf("Nhập năm sinh: ");
        scanf("%d", &thr->year);
        getchar(); // Đọc newline thừa từ scanf

        printf("Nhập quê quán: ");
        fgets(thr->from, sizeof(thr->from), stdin);
        thr->from[strcspn(thr->from, "\n")] = 0; // Loại bỏ newline

        pthread_cond_signal(&cond1);

        pthread_cond_wait(&cond2, &lock);

        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void *handle_th2(void *args)
{
    thread_infor_t *thr = (thread_infor_t *)args;

    while (1)
    {
        pthread_mutex_lock(&lock);
        pthread_cond_wait(&cond1, &lock);

        int fd = open(FILENAME, O_RDWR | O_CREAT | O_APPEND, 0666);
        if (fd == -1)
        {
            perror("open() failed");
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }

        dprintf(fd, "Name: %s\n", thr->name);
        dprintf(fd, "Year: %d\n", thr->year);
        dprintf(fd, "From: %s\n", thr->from);
        dprintf(fd, "-------------------------\n");

        close(fd);
        pthread_cond_signal(&cond2);

        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void *handle_th3(void *args)
{
    pthread_mutex_lock(&lock);

    while (1)
    {
        pthread_cond_wait(&cond2, &lock);

        FILE *file = fopen(FILENAME, "r");
        if (!file)
        {
            perror("Error opening file for reading");
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }

        char line[100];
        printf("Dữ liệu đã được ghi vào file:\n");
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }

        fclose(file);
        pthread_cond_signal(&cond1);
    }

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    int ret;
    pthread_t thread_id1, thread_id2, thread_id3;
    thread_infor_t thr_info;

    if ((ret = pthread_create(&thread_id1, NULL, handle_th1, &thr_info)) != 0)
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if ((ret = pthread_create(&thread_id2, NULL, handle_th2, &thr_info)) != 0)
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if ((ret = pthread_create(&thread_id3, NULL, handle_th3, NULL)) != 0)
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
}
