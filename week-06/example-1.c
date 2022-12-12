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
#include <sys/ipc.h>
#include <sys/sem.h>

// Dead lock example from presentation 6

// DONE


// Function A(S,n)
// Adds 1 to S_n
void func_A (int semid, struct sembuf mybuf, int n) {
	mybuf.sem_num = n;
	mybuf.sem_op = 1;
	semop(semid, &mybuf, 1);
}

// Function D(S,n)
// Subtracts 1 from S_n
void func_D (int semid, struct sembuf mybuf, int n) {
	mybuf.sem_num = n;
	mybuf.sem_op = -1;
	semop(semid, &mybuf, 1);
}

int main(int argc, char *argv[]) {
	// Creating a key
	char pathname[] = "example_1.c";
	key_t key;
	if (key = ftok(pathname, 0) < 0) {
		printf("Could not get key\n");
		exit(-1);
	}

	// Creating semaphore
	int semid;
	if ((semid = semget(key, 2, 0666 | IPC_CREAT)) < 0) {
		printf("Could not create semaphore\n");
		exit(-2);
	}

	struct sembuf mybuf;
	mybuf.sem_flg = 0;
	func_A(semid, mybuf, 0);
	func_A(semid, mybuf, 1);

	// Creating child process
	pid_t pid = fork();

	int i = 0;

	// Parent process code (process 1)
	if (pid > 0) {
		printf("I am a parent process\n");
		while (1) {
			printf("Process 1, i = %d\n", i);

			func_D(semid, mybuf, 0);
			func_D(semid, mybuf, 1);
			func_A(semid, mybuf, 0);
			func_A(semid, mybuf, 1);

			i++;
		}
	}

	// Child process code (process 2)
	if (pid == 0) {
		printf("I am a child process\n");
		while (1) {
			printf("Process 2, i = %d\n", i);

			func_D(semid, mybuf, 0);
			func_D(semid, mybuf, 1);
			func_A(semid, mybuf, 0);
			func_A(semid, mybuf, 1);

			i++;
		}
	}

	return 0;
}