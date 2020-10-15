#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// Task 2 from the presentation 4
// Compute the size of the pipe

// Needed on github

// NOT DONE

int main() {
	size_t size = 0;;
	int fd[2];

	int i = 0;

	char * string = (char *) malloc(10 * sizeof(char));

	while (1) {
		i++;
		write( fd[1], string, 1);
		printf("%d\n", i);
	}


	return 0;
}