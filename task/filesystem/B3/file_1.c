#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/sysmacros.h>

#define filename "test.txt"

int main()
{
    int fd;
    int numWrite;
    char buf[] = "hello world\n";
    struct stat sb;

    fd = open(filename, O_RDWR | O_CREAT, 0667);
    if (fd == -1)
    {
        printf("open() failed\n");
    }

    numWrite = write(fd, buf, strlen(buf));
    // lay thong tin file
    if (stat(filename, &sb) == -1)
    {
        perror("Error getting file stats");
        return 1;
    }
    // loai file
    printf("File Type: ");
    switch (sb.st_mode & S_IFMT)
    {
    case S_IFBLK:
        printf("block device\n");
        break;
    case S_IFCHR:
        printf("character device\n");
        break;
    case S_IFDIR:
        printf("directory\n");
        break;
    case S_IFIFO:
        printf("FIFO/pipe\n");
        break;
    case S_IFLNK:
        printf("symlink\n");
        break;
    case S_IFREG:
        printf("regular file\n");
        break;
    case S_IFSOCK:
        printf("socket\n");
        break;
    default:
        printf("unknown?\n");
    }
    // ten file
    printf("File Name: %s\n", filename);
    // thoi gian chinh sua cuoi
    printf("Last file modification: %s\n", ctime(&sb.st_mtime));
    // kich thuoc
    printf("File size: %jd bytes\n", (intmax_t)sb.st_size);
    close(fd);
}