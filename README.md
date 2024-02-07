# CS 489 - Programming Assignment 0 - Let's RPCs (50 points)

## Summary
In this assignment, you will implement a client/server RPC protocol. The goal is to use simple UDP to build a communication channel so a client can request services using simple RPCs.

## Description
The following [client.c](client.c) and [server.c](server.c) are a simple implementation of UDP socket connections which are discussed in class. You can compile and run the client and the server on two different terminal windows (both connected to a Linux server). You should get the following output.

On the server side (running on lupin). 

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

You can always on run the server on another machine. You need to use the **ifconfig** command to get the server IP address to use on the client side.

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

As you can see, the client and the server use a UDP socket and start exchanging messages using sendto() and recvfrom(). Right now the system only works with **add**.

Your job is to implement a more completed system that supports the following RPCs: **add**, **sub**, **mul**, and **div**, and send the results back to the client. All procedures should only take 2 arguments. If the user requests something else, "**not supported**" should be printed out.

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

The client and the server will run until you use Ctrl+C to terminate them.

You may want to look into the following functions to see how they work: [strncmp](http://linux.die.net/man/3/strncmp) to compare 2 strings, use [atoi](http://linux.die.net/man/3/atoi) to convert a string to an integer, and use [sprintf](http://linux.die.net/man/3/sprintf) to construct a string to send the result back to the client.

## Extra Credit
If you choose to implement **mod** RPC, you can earn up to **5 additional bonus points**.


## Reflection
Write a short reflection about the programming assignment in reflection.txt: what did you learn, what would you do differently next time, and what was difficult?

## Style
You are expected to follow a consistent style. Pay particular attention to:

1. File headers: You should have a file header at the top of every file explaining the purpose and author of the file, describing input/output if any.
2. Variable names: use meaningful names in all lowercase with underscore separations between words
3. Constant names: use all uppercase
4. Your code should have appropriate whitespace and avoid overly long line lengths.
5. You should have no warnings when compiled
6. Each function needs a header, describing the function purpose, parameters, and the return value.
7. Use of git: use meaningful commit messages and commit after reasonable milestones (i.e., a function has been completed)
    * A single commit for the whole project is not a good use of git


## Final Submission 
* To GitHub:
  * Your .c files
  * Your reflection of the programming assignment in reflection.txt

***Remember to double check on github.com that your files pushed. If they don't, you need to push them. I can only see what is on github.com, not what is only on your computer.***
