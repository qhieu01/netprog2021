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