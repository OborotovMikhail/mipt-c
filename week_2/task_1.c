#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void GenerateString(int n, char* string)
{
	char local = 96;
	char one = 1;
	int half_len;
	for (int i = 0; i < n; i++) {
		half_len = pow(2, i) - 1;
		string = local + one;
		string = string + 1;
		if (half_len != 0) {
			string = strncpy(string - 1 - half_len, string, half_len);
		}
		printf("%s\n", string - 1 - 2 * half_len);
	}
}

int main()
{
	int n = 2;
	scanf("%d", &n);

	int len = pow(2, n) - 1;

	char* x = (char*)calloc(len, sizeof(char));

	GenerateString(n, x);

	free(x);
	return 0;
}