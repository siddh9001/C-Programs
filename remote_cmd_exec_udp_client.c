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
    int sockfd, port;
    char sndbuff[100], recvbuff[100];
    struct sockaddr_in sa;
    
    socklen_t len = sizeof(sa);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd < 0)
        printf("Socket Error!..\n");
    else
        printf("Socket Created Sucessfully!..\n");
        
    
    bzero(&sa, sizeof(sa));
    printf("Enter port no: ");
    scanf("%d",&port);
    
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(port);
    
    while(1)
    {
        printf("\nEnter Command to be executed: ");
        fgets(sndbuff, sizeof(sndbuff), stdin);
        sendto(sockfd, sndbuff, sizeof(sndbuff), 0, (struct sockaddr*)&sa, len);
        printf("\nData Sent !..\n");
        recvfrom(sockfd, recvbuff, sizeof(recvbuff), 0, (struct sockaddr*)&sa, &len);
        printf("Message from server : %s", recvbuff);
    }
    
    return 0;
}