Run either file to write 'hello world' to the file.
Next, remove write permissions from the file; run the script/executable again. Note the error.

```
$ gcc -o WriteFile simpleFileWrite.c
$ ./WriteFile
$ chmod 400 foo.txt
$ ./WriteFile
Error number: 13
foo.txt: Permission denied
```

Note this same errno value is displayed when the script is run.
```
$ python3 WriteFile.py
Traceback (most recent call last):
  File "simpleFileWrite.py", line 4, in <module>
    fout = os.open('foo.txt', os.O_WRONLY | os.O_CREAT, 0o644)
PermissionError: [Errno 13] Permission denied: 'foo.txt'
```

Note how the python api for write call closely resembles the c system call. 
