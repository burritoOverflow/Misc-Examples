#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *buffer;
  int size, count, i;
  FILE * fd;

  if (argc != 3) {
    printf("Usage: %s blocksize blockcount\n", argv[0]);
    exit(1);
  }

  fd = fopen("bufio.out", "w");

  // size of the blocks to write, the number of blocks to write
  size = atoi(argv[1]);
  count = atoi(argv[2]);

  buffer = malloc(size);

  for (i = 0; i < count; i++) {
    fwrite(buffer, size, 1, fd);
  }

  fclose(fd);

}
