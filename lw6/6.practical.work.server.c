#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main (int argc,char const *argv[]){
   int sockfd, clen, clientfd;
   struct sockaddr_in saddr, caddr;
   unsigned short port =8080;


    if((sockfd=socket(AF_INET, SOCK_STREAM,0)) <0){
        printf(“Error creating socket\n”);
        return -1;
    
    }
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);

    if((bind(sockfd, (structsockaddr *) &saddr,sizeof(saddr)) <0){
       printf(“Error binding\n”)
       return -1;
    }
    if(listen(sockfd,5)<0){
        printf(“Error listening\n”);
        return -1;
    }
    clen=sizeof(caddr);
    if((clientfd=accept(sockfd, (structsockaddr *) &caddr, &clen)) <0){
        printf(“Error accepting connection\n”);

        printf("Start");

    while (1) {
        char j[999];
		memset(j, 0, 999);
		read(clientfd, j, 999);
		[strlen(s) - 1] = 0;
		printf("Client says: %s\n", j);

		printf("Server> ");
      	fgets\(j, 999, stdin);
      	write(clientfd, j, strlen(j));
    }



while (1) {
            int n = recv(clientfd, buffer, sizeof(buffer), 0);
            if (n == 0)
                printf("Error!!!\n");
                exit(0);
            else
                int firstChar = 0;
                for (int i = 0; i < n; i++) {
                    if (buffer[i] == '\0') 
                        printf("From client: %s\n", &buffer[firstChar]);
                        firstChar = i+1;   
                }
                
                memset(buffer, 0, sizeof(buffer));
                printf("Enter: ");
                scanf("%s", buffer);
                send(clientfd, buffer, strlen(buffer)+1, 0);
            }
       return -1;
{
