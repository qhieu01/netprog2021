  
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]){
    struct hostent *hinfo;
     if (argc < 2) {
      char hostname[200];
      printf("hostname: ");
      fgets(hostname, sizeof(hostname), stdin);
      hinfo = gethostbyname(hostname);
    }
    else {
      hinfo = gethostbyname(argv[1]);
    }

    if (hinfo == NULL) {
       printf("gethostbyname() failed\n");
    } else {
       printf("%s = ", hinfo->host_name);
       unsigned int i=0;
       while ( hinfo -> host_addr_list[i] != NULL) {
          printf( "%s ", inet_ntoa( *( struct in_addr*)( hinfo -> host_addr_list[i])));
          i++;
       }
       printf("\n");
    }
    int sockfd;
    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) <0){
      printf("Error creating socket\n");
      exit(1);
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char *) &saddr.sin_addr.s_addr, hinfo->h_addr_list[0], host->h_length);
    saddr.sin_port = htons(99);
    if (connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
        printf("Cannot connect\n");
        perror("Connect\n");
    }
    printf("connect to server\n")
    printf("\t \t wait \n");
    
    while (1) {
        char j
        j[999];
        memset(j, 0, 999);
        printf("Client> ");
        fgets(j, 200, stdin);
        write(sockfd, j, strlen(j));

        read(sockfd, j, 999);
        s[strlen(j) - 1] = 0;
        printf("Server says: %s\n", j);
    }
while (1) {
    printf("Enter: ");
    memset(buffer, 0, sizeof(buffer));
    scanf("%s", buffer);
    send(sockfd, buffer, strlen(buffer)+1, 0);
    memset(buffer, sizeof(buffer), 0);
    if (recv(sockfd, buffer, sizeof(buffer), 0) == 0) {
        printf("Error!!!\n");
        exit(0);
    } else {
            printf("Mesage from server: %s\n", buffer);
            exit(0);
    }
    return 1;

    if(strncmp("/quit", msg, 5) == 0){ 
        printf("Disconnecting...\n"); 
        shutdown(sockfd, SHUT_RDWR);
        close(sockfd);
        break; 
    }
}