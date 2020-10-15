#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

// Task 5 from the presentation 3
// Reads program names and arguments from the file
// then launches the programs from child processes

// Needed on github

// NOT DONE

#define len 100


void GetWords(char * string) {
	//Getting a pointer for the 1st word
	char * word = strtok(string, " ");

	//Printing a word and getting a pointer for the next word
	//Until the end of the string
	while (word != NULL) {
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}
}


int main(int argc, char *argv[]) {

	// Opening the file
	FILE* txt;
	txt = fopen("task_5_text.txt", "r");
	if (txt == NULL) {
		printf("Can\'t open file\n");
		return 1;
	}


	char buffer[len + 1];
	char * word;

	char storage[8][4][len + 1];

	int i = 0, j;

	// Splitting text from the file into words
	while (i < 4) {
		// Putting a line from the file to the buffer
		
		word = fgets(buffer, len, txt);
		if (word == NULL) {
			break;
		}


		printf("\nLINE LINE LINE LINE LINE LINE LINE LINE LINE LINE: %d\n", i);
		printf("buffer: %s\n", buffer);

		// Splitting a line in the buffer into words
		// and putting them into storage
		j = 0;
		word = strtok(buffer, " \n");
		while (word != NULL) {
			printf("i = %d, j = %d\n", i, j);
			printf("word: %s\n", word);

			storage[i][j] = word;

			word = strtok(NULL, " ");
			
			printf("current storage:\n");
			for (int m = 0; m < 4; m++) {
				printf("%s %s %s %s\n",
					storage[m][0],
					storage[m][1],
					storage[m][2],
					storage[m][3]);
			}
			printf("\n");

			j++;
		}


		i++;
	}


	printf("\n\nOUTPUT: %s\n", storage[3][1]);
	

	fclose(txt);
	return 0;
}