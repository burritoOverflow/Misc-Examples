#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFSIZE 400

int main(int argc, char const *argv[])
{

	int fd, numLinesDesired, numLinesRead, numBytesRead, totalBytesRead;
	// extra character for the null terminator
	char buf[BUFFSIZE + 1];

	if (argc != 3)
	{
		printf("Usage %s <filename> <num-lines>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// parse the command line args for numlines
	sscanf(argv[2], "%d", &numLinesDesired);

	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Open failed");
		exit(EXIT_FAILURE);
	}

	// seek to EOF, traverse the file backwards * the number of
	// lines desired.
	if((lseek(fd, -BUFFSIZE * numLinesDesired, SEEK_END)) == -1) 
	{
		perror("Seek");
		exit(EXIT_FAILURE);
	}

	numLinesRead = 0;
	totalBytesRead = 0;
	// if the buffer is no longer able to be 'filled', we've 
	// probably run out of 'lines'
	while((numBytesRead = read(fd, &buf, BUFFSIZE)) == BUFFSIZE)
	{
		// keep track of both the number of 'lines'
		// read (where each time the buffer is populated, the line 
		// counter is incremented), and track the total number of
		// bytes read. 
		numLinesRead++;
		totalBytesRead += numBytesRead;
		// null terminator added for readability
		buf[BUFFSIZE] = 0;
		printf("%s\n", buf);
	}

	printf("Total Lines Read %d, Total Bytes Read: %d\n", numLinesRead, totalBytesRead);

}
