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

// Task 2 from presentation 10
// Ignore all signals

// Needed on github

// DONE

void my_handler (int nsig) {
	printf(" Signal number is %d\n", nsig);
}

int main(int argc, char *argv[]) {
	printf("Started the program\n");

	for (int i = 1; i < 32; i++) {
		(void) signal (i, my_handler);
	}

	printf("Must be ignoring everything from now on\n");

	while (1);
	return 0;
}