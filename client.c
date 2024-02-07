// Client side using UDP
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//default port, TODO: pick another port (must be the same in server.c)
#define PORT    8080
#define MAXLINE 1024

//make IP address of the server a global variable
char *server_ip;

//add procedure
int add (int i, int j) { 
	int sockfd;
	char buffer[MAXLINE];
	int n, len;
	
	struct sockaddr_in servaddr;

	// Creating socket file descriptor
	if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) < 0){ 
		perror ("socket creation failed"); 
		exit (EXIT_FAILURE);
	}     
         
	memset (&servaddr, 0, sizeof (servaddr));
  
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons (PORT);
	servaddr.sin_addr.s_addr = inet_addr (server_ip);
    
	//construct the message to send to the server
	char msg[MAXLINE];
	sprintf (msg, "add %d %d", i, j);
    

	//send message to the server  
	sendto (sockfd, (const char *) msg, strlen (msg), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof (servaddr));
	printf ("Sent message %s\n", msg);

	//receive a message from the server    
	n = recvfrom (sockfd, (char *) buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, (socklen_t *) & len);
	
	//terminate string buffer with NULL character
	buffer[n] = '\0';

	//convert server message to an int
	int result = atoi (buffer);

	close (sockfd);

	return result;
}

int main (int argc, char *argv[]){

	//make sure the ip of the server is given
	if (argc != 2){
		printf ("Usage: %s server ip address\n", argv[0]);
		return 1;
	}

	//set server ip address
	server_ip = argv[1];

	//keep looping
	while (1){
		//ask the user what they want to do  
		char msg[1024];
		printf ("Enter the request: ");
		fgets (msg, 1024, stdin);
		char buff[1024];

		//copy msg to buff just in case we need to use msg again
		strncpy (buff, msg, 1024);

		char *words[5];

		int i = 0;
		
		//get the first token i.e. (add, sub, ...)
		words[i] = strtok (buff, " \n");

		//get the operands
		while (words[i] != NULL){
			i++;
			words[i] = strtok (NULL, " \n");
		}
		
		//after this loop, words[0] is the operator (add, sub, ....) words[1] and words[2] are the operands

		if (strcmp (words[0], "add") == 0){
			//convert operands to integers
			int arg1 = atoi (words[1]);
			int arg2 = atoi (words[2]);

			//call add() procedure and print out the result
			printf ("Result: %d\n", add (arg1, arg2));
		}
	}
	
	return 0
}
                                                                                          134,1         Bot
