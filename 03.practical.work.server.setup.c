#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main (int argc,char const *argv[]){
   intsockfd, clen, clientfd;
   structsockaddr_in saddr, caddr;
   unsignedshortport =8080;


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
        return -1;
}