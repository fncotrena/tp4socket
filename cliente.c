#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <string.h>
#define PORT 8888
#define IP "127.0.0.1"

int main(int argc, char *argv[])
{
 
 int socketfd;
 struct sockaddr_in addr;

 socketfd = socket(AF_INET, SOCK_DGRAM,0);
 memset(&addr,0,sizeof(struct sockaddr_in));
 addr.sin_family= AF_INET;
 addr.sin_port= htons(PORT); 
 inet_aton(IP,&(addr.sin_addr));

 for (;;)

{   
    socklen_t socklend= sizeof(struct sockaddr_in);
   //fd=accept(socketfd,(struct sockaddr*)&addr,socklend); 
   
   sendto(socketfd,"hola\n",5,0,(struct sockaddr*)&addr,socklend);
   printf("mensaje enviado \n");
   sleep(1);

}

 
 close(socketfd);

 exit(EXIT_SUCCESS);
}