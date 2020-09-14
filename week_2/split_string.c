#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define len 100

int if_letter (char x) {
	if ( ((x > 47) && (x < 58)) || ((x > 64) && (x < 91)) || ((x > 96) && (x < 123)) ) {
		return 1;
	}
	return 0;
}

void ReadText (char * string) {
	char * local_string = string;

	for (int i = 0; i < len; i++) {
		scanf("%c", local_string);
		if (* local_string == '\n') {
			* local_string = 32;
			break;
		}
		local_string++;
	}
}

void PrintWords (char * string) {
	char * local_string = string;
	
	int if_previous_non_letter = 1;

	for (int i = 0; i < len; i++) {
		if (if_letter(* local_string)) {
			printf("%c", * local_string);
			if_previous_non_letter = 0;
		}
		if ((if_letter(* local_string) == 0) && (if_previous_non_letter == 0)) {
			printf("\n");
			if_previous_non_letter = 1;
		}
		local_string++;
	}
}

int main() {
	char * string = (char *) calloc(len + 1, sizeof(char));

	ReadText(string);
	PrintWords(string);

	free(string);
	return 0;
}