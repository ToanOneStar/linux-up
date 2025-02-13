#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void signal_1(int num)
{
    printf("\nhello world %d\n", num);
}

int main()
{
    if (signal(2, signal_1) == SIG_ERR) // 2 == SIGINT
    {
        fprintf(stderr, "failed\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        printf("I'm main()\n");
        sleep(1);
    }
}