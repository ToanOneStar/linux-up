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
        fd = open(FIFO_FILE, O_RDONLY);
        read(fd, buff, BUFF_SIZE);
        printf("producer message: %s", buff);
        close(fd);
        return 0;
    }
}