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

// Task 3 from presentation 10
// RT/FUPM champion
// Two processes "shouting" at each other

// Needed on github

// DONE

int child_pid;

void handler_1 (int nsig) {
	printf("RT champion!\n");
	sleep(1);
	kill(child_pid, SIGUSR2);
}

void handler_2 (int nsig) {
	printf("FUPM champion!\n");
	sleep(1);
	kill(getppid(), SIGUSR1);
}

int main(int argc, char *argv[]) {
	(void) signal (SIGUSR1, handler_1);
	(void) signal (SIGUSR2, handler_2);

	int pid = fork();

	if (pid == 0) {
		while(1);
	}

	if (pid > 0) {
		child_pid = pid;
		kill(child_pid, SIGUSR2);
		while(1);
	}
	
	return 0;
}