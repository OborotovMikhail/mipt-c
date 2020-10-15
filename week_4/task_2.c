#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// Task 2 from the presentation 4
// Compute the size of the pipe

// Needed on github

// DONE

int main() {
	// Creating a pipe
	int fd[2];
	if (pipe(fd) == -1) {
		printf("Failed to create a pipe\n");
		exit(-1);
	}

	// Writing to pipe and printing the lengh of a pipe
	int len = 1, dummy = 0;
	do {
		write(fd[1], &dummy, sizeof(int));
		printf("%d\n", len);
		len++;
	} while (1);
	
	close(fd[0]);
	close(fd[1]);

	return 0;
}