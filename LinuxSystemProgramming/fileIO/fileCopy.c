/* trivial file copy program to demonstrate low-level IO */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#define BUFSIZE 16384


int main()
{
	// input and output handles
	int fin, fout;
	int count;
	char buf[BUFSIZE];

	if((fin = open("foo.txt", O_RDONLY)) < 0) {
		perror("foo.txt");
		exit(1);
	}

	if ((fout = open("bar.txt", O_WRONLY | O_CREAT, 0644)) < 0) {
		perror("bar.txt");
		exit(2);
	}

	while ((count = read(fin, buf, BUFSIZE)) > 0)
		write(fout, buf, count);

	close(fin);
	close(fout);

}
