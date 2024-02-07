// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


//default port, TODO: pick another port (must be the same in client.c)
#define PORT    8080
#define MAXLINE 1024

//make the socket global so stub can use it to send msg to client
int sockfd;



//TODO add code for sub, div, mul procedures


//add procedure
int add (int i, int j){
	return i + j;
}

void stub(int result, struct sockaddr_in cliaddr) {

		//construct the message to send back to the client
		char msg[1024];

		int len = sizeof(cliaddr);
		sprintf (msg, "%d", result);
		//send message to the client
		sendto (sockfd, (const char *) msg, strlen (msg), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
		printf ("Send %s \n", msg);
}



int main (){

	char buffer[MAXLINE];
	
	struct sockaddr_in servaddr, cliaddr;

	// Creating socket file descriptor
	if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) < 0){
      perror ("socket creation failed");
      exit (EXIT_FAILURE);
	}

	memset (&servaddr, 0, sizeof (servaddr));
	memset (&cliaddr, 0, sizeof (cliaddr));

	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons (PORT);
	// Bind the socket with the server address
	if (bind (sockfd, (const struct sockaddr *) &servaddr, sizeof (servaddr)) < 0){
		perror ("bind failed");
		exit (EXIT_FAILURE);
	}

	int len = len = sizeof (cliaddr);


	//keep waiting for request
	while (1){
		//receive a message from the client
		int n = recvfrom (sockfd, (char *) buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &cliaddr, (socklen_t *) & len);
		
		//set last byte of buffer to NULL
		buffer[n] = '\0';
		printf ("Client : %s\n", buffer);


		char buff[1024];
		//copy buffer to buff just in case we need to use buff again
		strncpy (buff, buffer, 1024);

		char *words[5];

		int i = 0;

		//get the first token i.e. (add, sub, ...)
		words[i] = strtok (buff, " \n");

		//get the operand
		while (words[i] != NULL){
			i++;
			words[i] = strtok (NULL, " \n");
		}


		//if the request is add
        if (strcmp (words[0], "add") == 0){
			//convert operands to integers
			int arg1 = atoi (words[1]);
			int arg2 = atoi (words[2]);
			
			//call add() procedure
			int result = add (arg1, arg2);

			//call stub, passing the result and client address
			stub(result, cliaddr);
      }

		//TODO add code for sub, div, mul procedures


   }

   return 0;
}
