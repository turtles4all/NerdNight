#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
    if (argc < 2) {
        printf("Usage: %s hostname", argv[0]);
        exit(-1);
    }
    
    int sockfD, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    server = gethostbyname(argv[1]);

    if (server == NULL) {
       printf("gethostbyname() failed\n");
    } else {
       printf("%s = ", hp->h_name);
   
       for(int i = 0; hp -> h_addr_list[i] != NULL; server = server->next) {
          printf( "%s ", inet_ntoa( *( struct in_addr*)( hp -> h_addr_list[i])));
          i++;
       }
       printf("\n");
    }
}
