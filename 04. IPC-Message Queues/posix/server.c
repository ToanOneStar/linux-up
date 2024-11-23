#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    mqd_t mqid = mq_open("/mqueue", O_RDWR | O_CREAT, 0644, NULL);

    const char *message = "Hello";
    if (mq_send(mqid, message, strlen(message) + 1, 0) == -1)
    {
        perror("mq_send failed");
        mq_close(mqid);
        return 1;
    }

    printf("Message sent: %s\n", message);
    mq_close(mqid);
    return 0;
}
