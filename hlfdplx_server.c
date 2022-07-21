#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

int main()
{
    int sockfd, len, connfd, port;
    struct sockaddr_in sa, cli;
    char s_buff[100], c_buff[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        prinf("Socket failed");
        exit(1);
    }

    printf("Enter the port: ");
    scanf("%d",&port);

    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    sa.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr*)&sa, szieof(sa)) < 0)
    {
        printf("bind Failed\n");
        exit(1);
    }

    listen(sockfd, 5);

    len = sizeof(cli);
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if(connfd < 0)
    {
        printf("Accept Failed\n");
        exit(1);
    }

    while(1)
    {
        //message to client
        bzero(c_buff, sizeof(c_buff));
        printf("\nEnter the message for client: ");
        scanf("%s", c_buff);
        send(connfd, c_buff, sizeof(c_buff), 0);

        //message from client
        bzero(s_buff, sizeof(s_buff));
        recv(connfd, s_buff, sizeof(s_buff), 0);
        printf("\nMessage Recieved from client: %s",s_buff);

    }

    close(sockfd);

    return 0;
}