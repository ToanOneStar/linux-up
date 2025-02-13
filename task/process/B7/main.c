#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handler(int num)
{
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

int main()
{
    pid_t child_pid;

    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    // Đăng ký handler cho SIGCHLD
    if (sigaction(SIGCHLD, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();
    if (child_pid >= 0)
    {
        if (0 == child_pid)
        {
            printf("I'm the child process, my PID: %d\n", getpid());
            exit(0);
        }
        else
        {
            printf("\nI'm the parent process\n");
            sleep(5);
        }
    }
    else
    {
        printf("fork() unsuccessfully\n");
    }
    return 0;
}
