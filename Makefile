C=gcc
FLAG=-Wall


all: server client

server: server.o
	$(CC) $(FLAG) server.o -o server

server.o: server.c
	$(CC) $(FLAG) -c server.c 

client: client.o
	$(CC) $(FLAG) client.o -o client

client.o: client.c 
	$(CC) $(FLAG) -c client.c 

clean:
	rm -f *.o client server
