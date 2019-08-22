#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int fd;

  if ((fd = open("foo.txt", O_WRONLY | O_CREAT, 0644)) < 0)
  {
    printf("Error number: %d\n", errno);
    perror("foo.txt");
    exit(1);
  }

  write(fd, "hello world", 11);
  close(fd);

}
