#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

// Task 1 from presentation 10
// (example task)
// Ignore a signal

// Needed on github

// DONE

int main(int argc, char *argv[]) {
	printf("Started the program\n");

	(void) signal (SIGINT, SIG_IGN);

	printf("Must be ignoring ^C from now on\n");

	while (1);

	return 0;
}