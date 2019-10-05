#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFSIZE 4096
#define NUMLINES 10

void rcTail(int fd)
{

  long size;
  char buffer[BUFFSIZE];

  if ((size = lseek(fd, 0, SEEK_END)) == -1)
  {
    perror("Seek failed\n");
    exit(EXIT_FAILURE);
  }

  // if smaller than our buffersize, we start at the beginning
  if (size >= BUFFSIZE)
  {
    lseek(fd, size - BUFFSIZE, SEEK_SET);
  }
  else
  {
    // seek to beginning of file
    lseek(fd, 0, SEEK_SET);
  }

  int nBytes = read(fd, buffer, BUFFSIZE);
  if (nBytes == -1)
  {
    perror("Read");
    exit(EXIT_FAILURE);
  }

  // for keeping track of the locationto stop,
  // and to count the number of newlines
  int location = nBytes;

  // we'll need one extra to account for 10 lines,
  // it seems
  int count = -1;

  for (int i = nBytes - 1; i > 0; i--)
  {
    if (buffer[i] == '\n')
    {
      location = i;
      count++;
    }

    // count all new lines, end at 10
    if (count == NUMLINES)
    {
      break;
    }
  }

  write(STDOUT_FILENO, &buffer[location], nBytes - location);
}

int main(int argc, const char *argv[])
{

  int fd;

  if (argc != 2)
  {
    printf("Usage %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((fd = open(argv[1], O_RDONLY)) == -1)
  {
    perror("Open");
    exit(EXIT_FAILURE);
  }

  rcTail(fd);

}
