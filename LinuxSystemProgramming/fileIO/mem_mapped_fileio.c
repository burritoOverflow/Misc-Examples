/*
  Takes the input file, "foo", in this example,
  maps it into memory (mmap) call. The address is captured
  in the src variable.

  The output file "bar" is then mmap'ed into memory.
  This block is captured in dst.

  The memcpy call copies the contents from src to dst.
  msync 'pushes' the contents of the destination buffer
  to the file.
*/

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  char *src, *dst;
  int fin, fout;
  size_t size;

  fin = open("foo", O_RDONLY);
  if (fin < 0) {
    perror("foo");
    exit(1);
  }

  // get the size of the file; we'll use this for memory mapping
  size = lseek(fin, 0, SEEK_END);

  // there's too much to mmap to describe it here--use the man page
  src = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fin, 0);
  if (src == MAP_FAILED) {
    perror("nmap");
    exit(2);
  }

  fout = open("bar", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

  // truncates a file to a specific size
  // in this case, bar is truncated to the size specified by size
  // after this call, the size of the output file matches the size
  // of the input file
  if (ftruncate(fout, size) == -1) {
    perror("ftruncate");
    exit(3);
  }

  dst = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fout, 0);
  if (dst == MAP_FAILED) {
    perror("mmap");
    exit(4);
  }

  // copy bytes between mappings
  // copies n bytes between src and dst (with destionation
  // as the first argument)
  memcpy(dst, src, size);

  // flushes changes to the file
  if (msync(dst, size, MS_SYNC) == -1) {
    perror("msync");
    exit(5);
  }

  exit(EXIT_SUCCESS);
}
