For the raw IO example:
Let's write a 1MB file 1 block at a time, and time it!
```
$ gcc -o rawIO rawIO.c
$ time ./rawIO 1 10000000
./rawIO 1 10000000  3.29s user 47.99s system 93% cpu 55.104 total
```

Note the majority of the time is spent in kernelspace.
