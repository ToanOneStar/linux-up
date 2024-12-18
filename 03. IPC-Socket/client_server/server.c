#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <time.h>

#define PORT 2000

void main()
{
    int listenfd = -1;
    int confd = -1;
    struct sockaddr_in server_addr;
    char send_buffer[1024];
    time_t ticks;

    memset(send_buffer, 0, sizeof(send_buffer));
    memset(&server_addr, 0, sizeof(server_addr));

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(listenfd, 10);

    while (1)
    {
        confd = accept(listenfd, (struct sockaddr *)NULL, NULL);
        ticks = time(NULL);
        sprintf(send_buffer, "Server reply %s", ctime(&ticks));
        write(confd, send_buffer, strlen(send_buffer));
        close(confd);
    }
    close(listenfd);
}