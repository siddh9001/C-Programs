#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>


int main()
{
    int sockfd,port;
    char sndbuff[]="Command executed sucessfully!..", recvbuff[100];
    struct sockaddr_in sa, cli;
    
    socklen_t len = sizeof(cli);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
        printf("Socket Error!..\n");
    else
        printf("Socket Created Sucessfully!..\n");
        
    
    bzero(&sa, sizeof(sa));
    printf("Enter port no: ");
    scanf("%d",&port);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    sa.sin_port = htons(port);
    
    if(bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
        printf("Bind Failed!..\n");
    else
        printf("Binded Sucessfully!..\n");
    
    printf("Waiting for Connections!..\n");
    
    while(1)
    {
        bzero(&recvbuff, sizeof(recvbuff));
        recvfrom(sockfd, recvbuff, sizeof(recvbuff), 0, (struct sockaddr*)&cli, &len);
        system(recvbuff);
        sendto(sockfd, sndbuff, sizeof(sndbuff), 0, (struct sockaddr*)&cli, len);
    }
    
    close(sockfd);
    
    return 0;
}