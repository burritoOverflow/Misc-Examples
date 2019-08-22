For the raw IO example:
Let's write a 10MB file 1 block at a time, and time it!
```
$ gcc -o rawIO rawIO.c
$ time ./rawIO 1 10000000
./rawIO 1 10000000  3.29s user 47.99s system 93% cpu 55.104 total
```

Note the majority of the time is spent in kernel space.

Now, let's try the same with the bufferedIO provided by the standard library 
```
$ gcc -o bufIO bufIO.c
$ time ./bufIO 1 1000000
$ ./bufIO 1 1000000  0.08s user 0.01s system 90% cpu 0.102 total
```

Granted, this is a contrived example, but demonstrates the overhead involved in system calls.
