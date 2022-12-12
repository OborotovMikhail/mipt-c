#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// Task 1 from presentation 5
// Messenger with fifos

// Not working in a shared folder
// (no permission to create fifos)
// So there is a copy in linux_coding/week_5

// Needed on git

// DONE

#define MAXWORD 100

int main(int argc, char *argv[]) {
	(void)umask(0);

	// Checking the argument
	if (argc < 2) {
		printf("Program needs argument (client id)\n");
		exit(-1);
	}

	int fd1, fd2, result;
	size_t size;
	char str[MAXWORD];

	// Fifo file names
	char fifo1to2_filename[] = "fifo12";
	char fifo2to1_filename[] = "fifo21";
	
	// Creating fifos
	if (mknod(fifo1to2_filename, S_IFIFO | 0666, 0) < 0) {
		if (errno != EEXIST) {
			printf("Could not create fifo 1 to 2\n");
			return 1;
		}
	}
	if (mknod(fifo2to1_filename, S_IFIFO | 0666, 0) < 0) {
		if (errno != EEXIST) {
			printf("Could not create fifo 2 to 1\n");
			return 1;
		}
	}
	
	// The other way to create fifos
	/*
	if (mkfifo(fifo1to2_filename, 0777) == -1) {
		if (errno != EEXIST) {
			printf("Could not create fifo 1 to 2\n");
			return 1;
		}
	}
	if (mkfifo(fifo2to1_filename, 0777) == -1) {
		if (errno != EEXIST) {
			printf("Could not create fifo 2 to 1\n");
			return 1;
		}
	}
	*/

	// Client id
	int client_id = atoi(argv[1]);
	
	// Client 1 code
	if (client_id == 1) {
		// Opening or creating fifos
		if ((fd1 = open(fifo1to2_filename, O_WRONLY)) < 0) {
			printf("Could not open fifo for writing (Client 1)\n");
			return 2;
		}
		if ((fd2 = open(fifo2to1_filename, O_RDONLY)) < 0) {
			printf("Could not open fifo for reading (Client 1)\n");
			return 2;
		}
		
		// Creating second process
		pid_t pid = fork();

		// Reading and writing from fifos
		while (1) {
			// Child process reads from fifo
			if (pid == 0) {
				read(fd2, str, MAXWORD);
				printf("%s", str);
			}
			// Parent process writes to fifo
			if (pid > 0) {
				fgets(str, MAXWORD, stdin);
				write(fd1, str, strlen(str) + 1);
			}
		}
	}

	// Client 2 code
	if (client_id == 2) {
		// Opening or creating fifos
		if ((fd1 = open(fifo1to2_filename, O_RDONLY)) < 0) {
			printf("Could not open fifo for reading (Client 2)\n");
			return 2;
		}
		if ((fd2 = open(fifo2to1_filename, O_WRONLY)) < 0) {
			printf("Could not open fifo for writing (Client 2)\n");
			return 2;
		}

		// Creating second process
		pid_t pid = fork();

		// Reading and writing from fifos
		while(1) {
			// Child process reads from fifo
			if (pid == 0) {
				read(fd1, str, MAXWORD);
				printf("%s", str);
			}
			// Parent process writes to fifo
			if (pid > 0) {
				fgets(str, MAXWORD, stdin);
				write(fd2, str, strlen(str) + 1);
			}
		}
	}

	return 0;
}