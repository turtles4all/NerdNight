/*
 * pdc.c
 *
 * Will connect to a remote host and return an active FD
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <poll.h>
#include <signal.h>


int main(int argc, char **argv){
	

	int startPort, endPort;
    int retryConnectAttempts = 4;

    int dstSockfd, n;
    struct addrinfo hints;
    struct addrinfo *dst_addr, *p;
	memset(&hints, 0, sizeof hints);
    char rhost[INET6_ADDRSTRLEN];


	if(sizeof(argv[1]) <= INET6_ADDRSTRLEN){
        memcpy(&rhost, argv[1], 50);
   } else {
	   exit(1);
	   }
   startPort = atoi(argv[2]);
   endPort = atoi(argv[3]);

   printf("HOST: %s\n",rhost);
   printf("START PORT: %i\n",startPort);
   printf("END PORT: %i\n",endPort);

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;




	memset((char *) &dst_addr, 0, sizeof(dst_addr));

    if ((n = getaddrinfo(rHost, NULL, &hints, &dst_addr)) != 0) {
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
			return 1;
		}


	for(p = dst_addr; p != NULL; p = p->ai_next) {

		set_in_port((struct sockaddr *)dst_addr->ai_addr, *rPort);

		if ((dstSockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("client: socket\n");
			continue;
		} 
		else {

			for(int i = 0; i < retryConnectAttempts; i++){
				//Attempt to connect
				n = connect(dstSockfd, dst_addr->ai_addr, dst_addr->ai_addrlen);

				if(n >= 0){ // break loop on succesfull connection
					printf("OPEN\n");
					close(dstSockfd);
					dstSockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
				}
				if (n < 0){ // continue loop if connection failed
					perror("PORT CLOSED: \n");
				}
	
			}
				
		} 
		} //End else
		
    freeaddrinfo(dst_addr);
    close(dstSockfd);
  return 0;
}
