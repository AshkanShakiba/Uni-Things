#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define BACKLOG 100    // connections in the queue
#define MAXDATALEN 256 // max size of messages to be sent
#define MAXUSER 20     // max number of users
#define MAXGROUP 10    // max number of groups
#define PORT 3232      // default port number

typedef struct
{
    int port;
    char username[10];
} User;

void *server(void *arg);                                           /*server instance for every connected client*/
void insert_list(int port, char *username, User *list, int *tail); /*inserting new client */
int search_list(int port, User *list, int tail);
void delete_list(int port, User *list, int *tail);
void delete_all(User *list, int *tail);
void display_list(const User *list, int tail); /*list all clients connected*/
void notify_shutdown();                        /*send msg to all if server shuts down*/
void *quit_signal();                           /*signal handler*/
int next_space(char *str);

char username[10];
User users[MAXUSER] = {0};
int user_tail = 0;
User groups[MAXGROUP][MAXUSER] = {0};
int group_tail[MAXUSER] = {0};
char buffer[MAXDATALEN];

int main(int argc, char *argv[])
{

    int sockfd, new_fd;
    int portnum;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int cli_size, z;
    pthread_t thr;
    int yes = 1;

    printf("==== Starting Server ====\n");
    if (argc == 2)
        portnum = atoi(argv[1]);
    else
        portnum = PORT; //if port number not given as argument then using default port
    printf("PORT NO.:\t%d\n", portnum);

    /*=set info of server =*/
    server_addr.sin_family = AF_INET;                /* set family to Internet     */
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* set IP address */
    server_addr.sin_port = htons(portnum);
    printf("IP ADDRESS:\t%s\n", inet_ntoa(server_addr.sin_addr));

    /*=creating socket=*/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("server- socket() error"); // debugging
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        printf("setsockopt error"); // debugging
        exit(1);
    }

    /*=binding socket=*/
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("binding failed\n"); // debugging
        exit(1);
    }

    /*=socket on listening mode=*/
    listen(sockfd, BACKLOG);
    printf("waiting for clients......\n");

    signal(SIGINT, (void *)quit_signal); //signal handler

    // Accepting new clients
    while (1)
    {
        cli_size = sizeof(struct sockaddr_in);                               //cli_size necessary as an argument for pthread_create
        new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &cli_size); //accepting connection from client

        /* getting username */
        bzero(username, 10);
        if (recv(new_fd, username, sizeof(username), 0) > 0)
            ;
        username[strlen(username) - 1] = ':';

        printf("** %d: %s JOINED CHAT **\n\n", new_fd, username);
        insert_list(new_fd, username, users, &user_tail); //inserting newly accepted client socked fd in list

        User args; //struct to pass multiple arguments to server function
        args.port = new_fd;
        strcpy(args.username, username);

        pthread_create(&thr, NULL, server, (void *)&args); //creating thread for every client connected
        pthread_detach(thr);
    }

    delete_all(users, &user_tail);
    close(sockfd);
}

/* Each client thread */
void *server(void *arguments)
{
    User *args = arguments;

    char buffer[MAXDATALEN], uname[10]; /* buffer for string the server sends */
    char *strp;
    char *msg = (char *)malloc(MAXDATALEN);
    int my_port, x, y;
    int msglen;

    my_port = args->port; /*socket variable passed as arg*/
    strcpy(uname, args->username);

    // Handling messages
    while (1)
    {
        bzero(buffer, 256);
        y = recv(my_port, buffer, MAXDATALEN, 0);

        /* Client quits */
        if (!y || strncmp(buffer, "/quit", 5) == 0)
        {
            printf("** %d: %s left chat. Deleting from lists. **\n\n", my_port, uname);

            delete_list(my_port, users, &user_tail);
            for (int i = 0; i < MAXGROUP; i++)
            {
                delete_list(my_port, groups[i], &group_tail[i]);
            }

            display_list(users, user_tail);

            close(my_port);
            free(msg);

            break;
        }
        else if (strncmp(buffer, "/join", 5) == 0)
        {
            char *group_id_str = malloc(sizeof(MAXDATALEN));
            strcpy(group_id_str, buffer + 6);
            int group_id = atoi(group_id_str);
            printf("** %d: %s joined group number %d. **\n\n", my_port, uname, group_id);

            insert_list(my_port, uname, groups[group_id], &group_tail[group_id]);
        }
        else if (strncmp(buffer, "/leave", 6) == 0)
        {
            char *group_id_str = malloc(sizeof(MAXDATALEN));
            strcpy(group_id_str, buffer + 7);
            int group_id = atoi(group_id_str);
            printf("** %d: %s left group number %d. **\n\n", my_port, uname, group_id);

            delete_list(my_port, groups[group_id], &group_tail[group_id]);
        }
        else if (strncmp(buffer, "/send", 5) == 0)
        {
            int space_pos = next_space(buffer + 6);
            char *group_id_str = malloc(sizeof(MAXDATALEN));
            strncpy(group_id_str, buffer + 6, space_pos);
            int group_id = atoi(group_id_str);

            if (search_list(my_port, groups[group_id], group_tail[group_id]) == -1)
            {
                continue;
            }

            printf("%s %s\n", uname, buffer);
            strcpy(msg, uname);
            x = strlen(msg);
            strp = msg;
            strp += x;
            strcat(strp, buffer + 7 + space_pos);
            msglen = strlen(msg);

            for (int i = 0; i < group_tail[group_id]; i++)
            {
                if (groups[group_id][i].port != my_port)
                    send(groups[group_id][i].port, msg, msglen, 0);
            }

            bzero(msg, MAXDATALEN);
        }
        display_list(users, user_tail);
    }
    return 0;
}

void *quit_signal()
{
    printf("\n==== SHUTTING DOWN SERVER ====\n");
    notify_shutdown();
    exit(0);
}

void notify_shutdown()
{
    if (user_tail == 0)
    {
        printf("No clients\n");
        exit(0);
    }
    else
    {
        for (int i = 0; i < user_tail; i++)
        {
            send(users[i].port, "/server_down", 14, 0);
        }

        printf("%d clients closed\n", user_tail + 1);
    }
}

void insert_list(int port, char *username, User *list, int *tail)
{
    if (search_list(port, list, *tail) != -1)
    {
        return;
    }
    User *temp;
    temp = malloc(sizeof(User));
    if (temp == NULL)
        printf("Out of space!");
    temp->port = port;
    strcpy(temp->username, username);
    list[(*tail)++] = *temp;
}

int search_list(int port, User *list, int tail)
{
    for (int i = 0; i < tail; i++)
    {
        if (list[i].port == port)
            return i;
    }
    return -1;
}

void delete_list(int port, User *list, int *tail)
{
    int ptr = search_list(port, list, *tail);
    if (ptr == -1)
    {
        return;
    }

    for (int i = ptr; i < *tail - 1; i++)
    {
        list[i] = list[i + 1];
    }
    (*tail)--;
}

void display_list(const User *list, int tail)
{
    printf("Current online users:\n");
    if (tail == 0)
    {
        printf("No one is online\n");
        return;
    }

    for (int i = 0; i < tail; i++)
    {
        printf("%d: %s\t", list[i].port, list[i].username);
    }
    printf("\n\n");
}

void delete_all(User *list, int *tail)
{
    *tail = 0;
}

int next_space(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            return i;
        }
        i++;
    }
    return -1;
}