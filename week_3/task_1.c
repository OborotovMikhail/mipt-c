#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

//DONE

int main()
{	
	int N = 3;

	for (int i = 0; i < N; ++i) {
		pid_t pid = fork();
		if (pid == 0) {
			sleep(i + 1);
			printf("%d\n", i);
		}
	}
	
	return 0;
}