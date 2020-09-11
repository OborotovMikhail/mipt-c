#include <stdio.h>
#include <math.h>

int func_2to10 (int input) {
	int res = 0, staff, len = 0, plus, current;
	staff = input;

	while (staff > 0) {
		staff = staff / 10;
		len++;
	}

	input = input + pow(10, len);
	//printf("\nnew input = %d\n", input);

	int full_len = len;
	int big = pow(10, len);
	int process = input - big;
	//printf("process = %d\n", process);

	len = len - 1;
	//printf("len = %d\n", len);

	while (process > 0) {
		//printf("\ninput: %d\n", input);

		plus = input / pow(10, len);
		current = pow(10, full_len - len);
		//printf("plus - current: %d - %d = ", plus, current);
		plus = plus - current;
		//printf("%d\n", plus);
		plus = plus * pow(2, len);

		//printf("BODY: %d + %d = ", res, plus);

		res = res + plus;

		//printf("%d\n", res);

		if (plus != 0) {
			input = input - pow(10, len);
		}
		len--;
		//printf("input at the end: %d\n", input);

		process = input - big;
		//printf("process: %d\n", process);
	}

	return res;
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("\n%d\n", func_2to10(x));
	return 0;
}
