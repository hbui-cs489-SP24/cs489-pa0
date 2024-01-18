# Programming Assignment

## Summary
In this assignment, you will implement a client/server RPC protocol. The goal is to use simple TCP to build a communication channel so a client can request services using simple RPCs.

## Description
The following [client.c](client.c) and [server.c](server.c) are a simple implementation of TCP socket connections which are described in the textbook. You can compile and run the client and the server on two different terminal windows (both connected to a Linux server). You should get the following output.
On the server side

```
hb117@uxb4:~$ gcc server.c -Wall -o server
hb117@uxb4:~$ ./server
Socket successfully created..
Socket successfully binded..
Server listening..
server acccept the client...
From client: Hello, world!
     To client : Hi there,
From client: exit
     To client : exit
Server Exit...
```

On the client side:
```
hb117@uxb4:~$ gcc client.c -Wall -o client
hb117@uxb4:~$ ./client
Socket successfully created..
connected to the server..
Enter the string : Hello, world!
From Server : Hi there,
Enter the string : exit
From Server : exit
Client Exit...
```

As you can see, the client and the server establish a socket connection and start exchanging messages using read(), and write() system calls.

The server should understand the following RPC: add, subtract, multiply, and division, and send the results back to the client.
add and multiple RPC can take more than 2 arguments. subtract and division RPC should only take 2 arguments.
If the client requests something else, "not supported" will be sent back.

To make things more interesting, the server will not send a raw number back to the client, it will send a string instead. For example:
negative one instead of -1
seven instead of 7
one nine instead of 19
three zero eight instead of 308
...
It is the job of the client to convert the message back to a number.
Your implementation should work like this:
On the client side:
```
Socket successfully created..
connected to the server..
Enter the request : add 3 4
From Server : 7
Enter the request : add 3 2 100
From Server : 105
Enter the request : sub 33 14
From Server : 19
Enter the request : sub 33 34
From Server : -1
Enter the request : mul 3 4
From Server : 12
Enter the request : div 30 10
From Server : 3
Enter the request : mod 30 10
From Server : not supported
Enter the request : exit
From Server : exit
Client Exit...
```
On the server side:
```
Socket successfully created..
Socket successfully binded..
Server listening..
server acccept the client...
From client: add 3 4
From client: add 3 2 100
From client: sub 33 14
From client: sub 33 34
From client: mul 3 4
From client: div 30 10
From client: mod 30 10
From client: exit
Server Exit...
```

The server and client will terminate when the client sends the server "exit" message.
You should use [strtok](http://linux.die.net/man/3/strtok) to tokenize the string that the server gets from the client. Take a look at [this example](input.c) to see how strtok works.
Additionally, you may want to use [strncmp](http://linux.die.net/man/3/strncmp) to compare 2 strings, use [atoi](http://linux.die.net/man/3/atoi) to convert a string to an integer and use [sprintf](http://linux.die.net/man/3/sprintf) to construct a string to send the result back to the client.
