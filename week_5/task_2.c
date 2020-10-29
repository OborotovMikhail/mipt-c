#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

// Task 2 from presentation 5
// Sort function

// Needed on git

// NOT DONE

// 2 number compare function
int compare(void* a, void* b) {
	int x = *(int*)a;
	int y = *(int*)b;
	return y - x;
}

// Array sort function
void sort_func(void* arr, size_t arr_len, int (*compare)(void*, void*), size_t size) {
	char* array = (char*)arr;
	char* buffer = (char*)malloc(size);

	for (size_t i = 0; i < size * arr_len; i += size)
		for (size_t j = 0; j < size * arr_len; j += size) {
			// Comparing numbers with the comare function
			int out = compare(arr + i, arr + j);
			if (out >= 0) {
				// Moving the elements in array
				memcpy(buffer, array + i, size);
				memcpy(array + i, array + j, size);
				memcpy(array + j, buffer, size);
			}
		}
	free(buffer);
}

int main(int argc, char const *argv[]) {
	// Array
	int arr[10] = {2, 1, 6, 8, 5, 3, 7, 4, 10, 9};

	// Printing old array
	printf("Old array:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	// Sorting
	sort_func(arr, 10, compare, sizeof(int));

	// Printing new array
	printf("New array:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}