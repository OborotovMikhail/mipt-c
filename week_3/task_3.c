#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// Task 3 from the presentation 3
// Program that prints main function arguments

// Not needed on github

// NOT DONE YET

int main(int argc, char *argv[], char *envp[])
{
	printf("argc = %d\n", argc);
	printf("argv = %s\n", * argv);
	printf("envp = %s\n", * envp);

	return 0;
}