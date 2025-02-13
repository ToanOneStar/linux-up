#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "./myfifo"
#define BUFF_SIZE 1024

int main()
{
    char buff[BUFF_SIZE];
    int fd;
    mkfifo(FIFO_FILE, 0666);
    while (1)
    {
        printf("Message to comsumer : ");
        fflush(stdin);
        fgets(buff, BUFF_SIZE, stdin);

        fd = open(FIFO_FILE, O_WRONLY);
        write(fd, buff, strlen(buff) + 1);
        return 0;
    }
}