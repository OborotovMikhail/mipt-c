#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

// Task 3 from the presentation 4
// a,b -> a*b

// One process reads a,b and sends to the pipe
// The other process reads a,b from the pipe and prints a*b

// Needed on github

// NOT DONE

int main() {
	// Creating a pipe
	int fd[2];
	if (pipe(fd) == -1) {
		printf("Failed to create a pipe\n");
	}

	// Creating 2 processes
	int pid = fork();
	if (pid == 0) {
		// Child process reads 2 numbers and passes
		// them into a pipe
		int a, b;
		close(fd[0]);

		// Reads numbers
		printf("Print two numbers: ");
		scanf("%d %d", &a, &b);

		// Writes to pipe
		write(fd[1], &a, sizeof(int));
		write(fd[1], &b, sizeof(int));

		close(fd[1]);
	} else {
		// Parent process waits for the child, then
		// reads 2 numbers from the pipe and multiplies them
		wait(NULL);
		int x, y, res;
		close(fd[1]);

		// Reads from pipe
		read(fd[0], &x, sizeof(int));
		read(fd[0], &y, sizeof(int));

		// Multiplies and prints
		res = x * y;
		printf("Result: %d\n", res);

		close(fd[0]);
	}

	return 0;
}