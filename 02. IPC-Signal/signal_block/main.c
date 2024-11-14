#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void signal_1(int num)
{
    printf("hello world\n");
}

int main()
{
    sigset_t new_set, old_set;
    if (signal(SIGINT, signal_1) == SIG_ERR)
    {
        fprintf(stderr, "failed\n");
        exit(1);
    }

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
    while (1)
        ;
    return 0;
}
