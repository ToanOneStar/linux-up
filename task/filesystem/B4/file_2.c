#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    int numb_read, numb_write;
    char buf[] = "hello world\n";

    fd = open("hello.txt", O_RDWR | O_CREAT | O_APPEND, 0667);
    if (fd == -1)
    {
        printf("open() failed\n");
    }

    numb_write = write(fd, buf, strlen(buf));
    lseek(fd, 0, SEEK_SET);
    write(fd, "toandz", 6);
    // Khi sử dụng O_APPEND, dữ liệu sẽ được ghi vào cuối file.
    // Tuy nhiên, sau khi thực hiện lseek(fd, 0, SEEK_SET) để di chuyển con trỏ file về đầu file,
    // dữ liệu sẽ được ghi tại vị trí con trỏ file đã di chuyển, tức là ở đầu file thay vì cuối file.
    printf("Write %d bytes to hello.txt\n", numb_write);
    close(fd);
    return 0;
}