#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define PORT 3232 // default port number
#define MAXDATALEN 256

int sockfd;
int n;                        /*variables for socket*/
struct sockaddr_in serv_addr; /* structure to hold server's address */
char buffer[MAXDATALEN];
char buf[10];

void *quit();
void *chat_write(int);
void *chat_read(int);

int main(int argc, char *argv[])
{

    pthread_t thr1, thr2; /* variable to hold thread ID */

    if (argc != 4)
    {
        printf("Please enter server ip, port and your username.\n");
        exit(1);
    }

    // socket creating
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        printf("client socket error\n");
    else
        printf("socket created\n");

    // set info
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // username
    bzero(buf, 10);
    strcpy(buf, argv[3]);
    buf[strlen(buf)] = ':';

    // client connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("client connect error\n");
        exit(0);
    }
    else
        printf("\rYOU JOINED AS %s\n", buf);

    send(sockfd, buf, strlen(buf), 0);

    pthread_create(&thr2, NULL, (void *)chat_write, (void *)(intptr_t)sockfd); //thread for writing
    pthread_create(&thr1, NULL, (void *)chat_read, (void *)(intptr_t)sockfd);  //thread for reading

    pthread_join(thr2, NULL);
    pthread_join(thr1, NULL);

    return 0;
}

void *chat_read(int sockfd)
{
    signal(SIGINT, (void *)quit);
    while (1)
    {
        n = recv(sockfd, buffer, MAXDATALEN - 1, 0);
        if (n == 0)
        {
            printf("\n==== SERVER HAS BEEN SHUTDOWN ====\n");
            exit(0);
        }

        if (n > 0)
        {
            printf("-> %s", buffer);
            bzero(buffer, MAXDATALEN);
        }
    }
}

void *chat_write(int sockfd)
{
    while (1)
    {
        // printf("%s", buf);
        fgets(buffer, MAXDATALEN - 1, stdin);

        if (strlen(buffer) - 1 > sizeof(buffer))
        {
            printf("buffer size full\t enter within %ld characters\n", sizeof(buffer));
            bzero(buffer, MAXDATALEN);
            __fpurge(stdin);
        }

        n = send(sockfd, buffer, strlen(buffer), 0);

        if (strncmp(buffer, "/quit", 5) == 0)
            exit(0);

        bzero(buffer, MAXDATALEN);
    }
}

// handling SIGINT
void *quit()
{
    printf("\nType '/quit' TO EXIT\n");
}