#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t ct; 
	/* 
	arg should always be NULL. 
	call also can never fail when NULL arg
	is specified, so no error checking. 
	details in man page.
	*/
	ct = time(NULL);

	printf("Current date and time: %s", ctime(&ct));

	// california knows how to party
	putenv("TZ=America/Los_Angeles");

	ct = time(NULL);
	printf("Date and time in California: %s", ctime(&ct));

	exit(0);

}
