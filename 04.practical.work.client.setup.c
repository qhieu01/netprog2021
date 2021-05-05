#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]){
    struct hostent *host_info;
    struct in_addr *address;

    char web[99];

    strcpy(web, "usth.edu.vn");
    printf("domain name: %s\n", web);

    host_info = gethostbyname(web);
    address = (struct in_addr *) (host_info->h_addr);
    printf("%s has address %s\n", web, inet_ntoa(*address));
}
    int sockfd;
    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) <0){
      printf("Error creating socket\n");
      exit(1);
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char *) &saddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    saddr.sin_port = htons(99);
    if (connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
        printf("Cannot connect\n");
        perror("Connect\n");
    }

    return 1;
    }