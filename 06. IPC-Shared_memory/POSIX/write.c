#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>

#define SIZE 50
#define FILE_NAME "toanonestar"

int main()
{
    int fd = shm_open(FILE_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);

    char *data = (char *)mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    strcpy(data, "Hello world1\n");
    printf("%s: Write data: %s\n", __FILE__, data);

    munmap(data, SIZE);
}