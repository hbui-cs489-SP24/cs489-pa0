# Programming Assignment 0

## Summary
In this assignment, you will implement a client/server RPC protocol. The goal is to use simple UDP to build a communication channel so a client can request services using simple RPCs.

## Description
The following [client.c](client.c) and [server.c](server.c) are a simple implementation of UCP socket connections which are discussed in class. You can compile and run the client and the server on two different terminal windows (both connected to a Linux server). You should get the following output.

On the server side (running on lupin)

```
$ make
cc -Wall -c server.c 
cc -Wall server.o -o server
cc -Wall -c client.c 
cc -Wall client.o -o client
$ ./server
Client: add 10 200
Send 210 
Client: add 300 400
Send 700 

```

On the client side:
```
$ ./client 144.126.12.243
Enter the request: add 10 200
Sent message add 10 200
Result: 210
Enter the request: add 300 400
Sent message add 300 400
Result: 700
Enter the request: sub 20 5
Enter the request: mul 6 8
Enter the request: div 12 5
Enter the request: 
```

As you can see, the client and the server establish a socket connection and start exchanging messages using read(), and write() system calls.

The system should support the following RPCs: add, sub, mul, and div, and send the results back to the client. All procedures should only take 2 arguments. If the client requests something else, "not supported" should be printed out.

After completion, your implementation should work like this:
On the client side:
```

Enter the request: add 3 4
Result: 7
Enter the request: add 5 100
Result: 105
Enter the request: sub 33 14
Result: 19
Enter the request: sub 33 34
Result: -1
Enter the request: mul 3 4
Result: 12
Enter the request: div 30 10
Result: 3
Enter the request: mod 30 10
not supported
...
```
On the server side:
```
From client: add 3 4
Send 7
From client: add  5 100
Send 105
From client: sub 33 14
Send 19
From client: sub 33 34
Send -1
From client: mul 3 4
Send 12
From client: div 30 10
Send 3
```

The client and the server will run until you use Ctrl+C to temrinate them.

You may want to look into the following functions to see how they work: [strncmp](http://linux.die.net/man/3/strncmp) to compare 2 strings, use [atoi](http://linux.die.net/man/3/atoi) to convert a string to an integer, and use [sprintf](http://linux.die.net/man/3/sprintf) to construct a string to send the result back to the client.
