#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pipe_fd[2];
    char write_msg[] = "Hello from the pipe!";
    char read_msg[100];

    if (pipe(pipe_fd) == -1)
    {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    if (pid > 0)
    {
        close(pipe_fd[0]);
        printf("Parent: Writing to pipe...\n");
        write(pipe_fd[1], write_msg, strlen(write_msg) + 1);
        close(pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        read(pipe_fd[0], read_msg, sizeof(read_msg));
        printf("Child: Read from pipe: %s\n", read_msg);
        close(pipe_fd[0]);
    }
    return 0;
}