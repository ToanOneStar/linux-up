#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>

#define SIZE 50
#define FILE_NAME "toanonestar"

int main()
{
    int fd = shm_open(FILE_NAME, O_RDWR, 0);
    if (fd == -1)
    {
        perror("shm_open failed");
        return 1;
    }
    ftruncate(fd, SIZE);

    char *data = (char *)mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED)
    {
        perror("mmap failed");
        return 1;
    }
    printf("%s: Read data: %s\n", __FILE__, data);

    munmap(data, SIZE);

    shm_unlink(FILE_NAME);
}