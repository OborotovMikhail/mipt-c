#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// Task 1 from the presentation 4
// Read from the file and print by the chunks of N symbols

// Needed on github

// DONE

int main() {
	int fd, N;

	// Opening text file
	if ( (fd = open("task-1-text.txt", O_RDONLY, 0666)) < 0 ) {
		printf("Error opening text file\n");
		return 1;
	}

	// Getting the N and creating a buffer
	printf("Type the amount of symbols per line\n");
	scanf("%d", &N);
	char * buffer = (char *) malloc(N * sizeof(char));

	// Reading N symbols from the file to buffer
	// then printing from the buffer
	size_t size;
	while ( (size = read( fd, buffer, N)) != 0 ) {
		write(1, buffer, size);
		printf("\n");
	}

	close(fd);
	free(buffer);

	return 0;
}