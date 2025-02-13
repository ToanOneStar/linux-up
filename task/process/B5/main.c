#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;
    child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0)
        {
            printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
        }
        else
        {
            printf("My PID is: %d\n", getpid());
            while (1)
                ;
        }
    }
    else
    {
        printf("fork() unsuccessfully\n");
    }
    return 0;
}
