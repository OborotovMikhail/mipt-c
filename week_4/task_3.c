#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// Task 3 from the presentation 4
// Two processes and two pipes
// a, b -> a*b

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

	free(string);

	return 0;
}