#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    mqd_t mqid = mq_open("/mqueue", O_RDONLY);

    char messrv[256];
    ssize_t bytes_read = mq_receive(mqid, messrv, sizeof(messrv), NULL);

    messrv[bytes_read] = '\0';
    printf("Data received: %s\n", messrv);

    mq_close(mqid);
    return 0;
}
