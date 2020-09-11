#include <stdio.h>
#include <math.h>

int func_10to2 (int input) {
	int res = 0, left, n = 0;

	while (input > 0) {
		left = input % 2;

		res = res + left * pow(10, n);
		n++;

		if (left == 0) {
			res = res * 10;
		}

		//printf("test - %d\n", res);

		input = input / 2;
	}

	return res;
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("\n%d\n", func_10to2(x));
	return 0;
}
