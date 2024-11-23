#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define BUFFER_SIZE 100

struct mesg_buffer
{
    long mesg_type;
    char mesg_text[BUFFER_SIZE];
} message;

int main()
{
    key_t key = ftok("profile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Enter type message: ");
    scanf("%ld", &message.mesg_type);
    getchar();
    printf("Enter message: ");
    fgets(message.mesg_text, BUFFER_SIZE, stdin);

    msgsnd(msgid, &message, sizeof(message), 0);
    return 0;
}