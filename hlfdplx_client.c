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
    struct sockaddr_in sa;
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
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(port);

    connfd = connect(sockfd, (struct sockaddr*)&sa, sizeof(sa));
    if(connfd < 0)
    {
        printf("\nConnect Failed!..\n");
        exit(1);
    }
    else
    {
        printf("\nConnection Sucessful..\n");
    }
    while(1)
    {
        //message from server
        bzero(s_buff, sizeof(s_buff));
        recv(sockfd, s_buff, sizeof(s_buff), 0);
        printf("\nMessage Recieved from server: %s\n",s_buff);

        //message to server
        bzero(c_buff, sizeof(c_buff));
        printf("\nEnter the message for server: ");
        scanf("%s", c_buff);
        send(sockfd, c_buff, sizeof(c_buff), 0);

    }

    close(sockfd);

    return 0;
}