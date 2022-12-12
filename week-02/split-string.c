#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Program that splits a sentence into words

// Needed on github

// DONE

#define len 100

void PrintWords(char * string) {
	//Getting a pointer for the 1st word
	char * word = strtok(string, " ");

	//Printing a word and getting a pointer for the next word
	//Until the end of the string
	while (word != NULL) {
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}
}

int main() {
	char * string = (char *) calloc(len + 1, sizeof(char));

	scanf("%[^\n]", string);

	PrintWords(string);

	free(string);
	return 0;
}
