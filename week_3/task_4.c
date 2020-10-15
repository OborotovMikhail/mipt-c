#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Task 4 from the presentation 3
// Launches helloworld.c from the child process

// Needed on github

// DONE

int main(int argc, char *argv[]) {
	int pid = fork();
	wait(NULL);

	if (pid == 0) {
		// Child process compiling helloworld.c
		printf("\nI am a child\nCompiling helloworld.c\n");

		execlp("gcc", "gcc", "-o", "hello", "helloworld.c", NULL);
		printf("\nError\n");
	} else if (pid > 0) {
		// Parent process executing hello
		// After waiting for the child process
		printf("\nI am a parent\nExecuting hello\n\n");

		execl("hello", "hello", NULL);
		printf("\nError\n");
	}

	return 0;
}