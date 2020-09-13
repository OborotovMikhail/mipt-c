#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void GenerateString(int n, char * string)
{
	char local_char = 96;
	char * local_string = string;
	int half_len;

	for (int i = 0; i < n; i++) {

		half_len = pow(2, i) - 1;

		local_char++;
		* local_string = local_char;

		local_string = local_string + 1;

		if (half_len != 0) {
			local_string = strncpy(local_string, string, half_len);
		}

		local_string = local_string + half_len;

		printf("%s\n", string);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int len = pow(2, n);

	char * string = (char *) calloc(len, sizeof(char));

	GenerateString(n, string);

	free(string);
	return 0;
}