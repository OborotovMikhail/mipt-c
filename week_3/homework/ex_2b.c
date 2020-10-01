#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// DONE

int main(int argc, char *argv[]) {
	int n, pid, i = 0;

	printf("Type \"N\"\n");

	scanf("%d", &n);

	// Main part
	while (i < n) {
		i++;
		pid = fork();

		wait(NULL);

		if (pid > 0) {
			break;
		}
	}

	// Output section in the format of
	// My number:
	// pid:
	// ppid:
	printf("\n");
	if (pid > 0) {
		printf("My number: %d\n", i);
		printf("pid: %d\n", getpid());
		printf("ppid: %d\n", getppid());
		printf("\n");
	}

	return 0;
}