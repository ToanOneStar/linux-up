#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok("./shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char *)shmat(shmid, NULL, 0);
    printf("Message to shared memory: ");
    fgets(str, 1024, stdin);

    return 0;
}
