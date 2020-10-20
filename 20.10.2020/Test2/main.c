#include <stdio.h>

void swapFunctionForArray(int* array, int numberOne, int numberTwo) {
	const int swap = array[numberOne];
	array[numberOne] = array[numberTwo];
	array[numberTwo] = swap;
}

int insertionSort(int* array, int startIndex, int endIndex) {
	const int size = endIndex - startIndex + 1;
	if (size <= 0) {
		return 1;
	}

	for (int i = startIndex + 1; i <= endIndex; ++i) {
		int j = i;
		while (array[j] < array[j - 1] && j > startIndex) {
			swapFunctionForArray(array, j, j - 1);
			--j;
		}
	}

	return 0;
}

int ShellsSort(int* array, int size) {
	int step = size / 2;
	while (step > 1) {
		for (int i = step; i < size; i += step) {
			if (array[i] > array[i + step]) {
				swapFunctionForArray(array, i, i + step);
			}
		}

		step /= 2;
	}

	insertionSort(array, 0, size - 1);
	return 0;
}

void main() {
	int array[] = { -10, 0 , 90, 245, 5, 3, 19, 53, -14 };
	int size = 9;
	ShellsSort(array, size);
	for (int i = 0; i < size; ++i) {
		printf("%i\n", array[i]);
	}
}