// #include<stdio.h>
// #include<stdlib.h>
// #include<arpa/inet.h>
// #include<netinet/in.h>
// #include<netdb.h>
// #include<string.h>
// #include<sys/types.h>
// #include<sys/socket.h>
// #include<unistd.h>

// int main(int argc, char *args[])
// {
//     int sockfd, len, port;
//     char sndbuff[100], recvbuff[100];
//     struct sockaddr_in sa, cli;

//     len = sizeof(cli);

//     bzero(&sa, sizeof(sa));
//     printf("Enter port No: ");
//     scanf("%d",&port);

//     sockfd = socket(AF_INET, SOCK_DGRAM, 0);
//     if(scokfd < 0)
//     {
//         printf("socket error!..\n");
//         exit(0);
//     }
//     else
//         printf("Socket created sucessfully!..\n");

//     sa.sin_family = AF_INET;
//     sa.sin_addr.s_addr = htonl(INADDR_ANY);
//     sa.sin_port = htnos(port);
    
//     if(bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
//     {
//         printf("Bind Failed!..\n");
//         exit(0);
//     }
//     else
//         printf("Binded Sucessfully!..\n");
// }
#include<sys/types.h>
#include<sys/socket.h>
#include<net/if_arp.h>
#include<sys/ioctl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include<complex.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/if_ether.h>
#include<net/ethernet.h>
#include<stdlib.h>

int main()
{
        struct sockaddr_in sin={0};
        struct arpreq myarp={{0}};
        unsigned char *ptr;
        int sd;

        sin.sin_family=AF_INET;

        printf("Enter IP address: ");

        char ip[20];
        scanf("%s", ip);

        if(inet_pton(AF_INET, ip, &sin.sin_addr) == 0)
        {
                printf("IP address Entered '%s' is not valid \n",ip);
                exit(0);
        }
        memcpy(&myarp.arp_pa, &sin, sizeof(myarp.arp_pa));
        strcpy(myarp.arp_dev, "echo");
        sd=socket(AF_INET, SOCK_DGRAM, 0);
        printf("\nSend ARP request\n");
        if(ioctl(sd, SIOCGARP, &myarp)==1)
        {
                printf("No Entry in ARP cache for '%s'\n",ip);
                exit(0);
        }
        ptr = &myarp.arp_pa.sa_data[0];
        printf("Received ARP Reply\n");
        printf("\nMAC Address for '%s' : ",ip);
        printf("%p:%p:%p:%p:%p:%p\n", ptr, (ptr+1), (ptr+2), (ptr+3), (ptr+4), (ptr+5));
        return 0;
}