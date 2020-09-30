#include <stdio.h>

//DONE

int main()
{	
	int pid = fork();
	int ppid = getppid();

	if (pid == -1) {
		printf("error\n");
	} else if (pid == 0) {
		printf("i am a child\n");
	} else {
		printf("i am a parent\n");
	}
	
	return 0;
}