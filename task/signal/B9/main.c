#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sig_handler1(int num)
{
    printf("\nIm signal handler1: %d\n", num);
    exit(EXIT_SUCCESS);
}

int main()
{
    sigset_t new_set, old_set;
    if (signal(SIGINT, sig_handler1) == SIG_ERR) // SIGINT khong bi block
    {
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }
    //  blocking
    sigemptyset(&new_set);
    sigaddset(&new_set, SIGINT);

    if (sigprocmask(SIG_SETMASK, &new_set, NULL) == 0)
    {
        if (sigismember(&new_set, SIGINT) == 1)
        {
            printf("SIGINT exist\n");
        }
        else if (sigismember(&new_set, SIGINT) == 0)
        {
            printf("SIGINT does not exist\n");
        }
    }

    kill(getpid(), SIGINT);

    printf("process ID: %d\n", getpid());
    while (1)
    {
        printf("hello\n");
        sleep(2);
    }
}
