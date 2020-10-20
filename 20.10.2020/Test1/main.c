#include <stdlib.h>
#include <stdio.h>

int SumOfDigit(int value) {
	value = abs(value);
	int sum = 0;
	while (value > 0) {
		sum += value % 10;
		value /= 10;
	}

	return sum;
}

int numbersWithTheLargestSumOfDigit(int* array, int sizeOfArray, int** pointer, int* sizeOfPointer) {
	int theLargestSumOfDigit = 0;
	for (int i = 0; i < sizeOfArray; ++i) {
		if (theLargestSumOfDigit < SumOfDigit(array[i])) {
			theLargestSumOfDigit = SumOfDigit(array[i]);
		}
	}

	int* result = (int*)malloc(sizeof(int));
	if (result == NULL) {
		return 1;
	}

	int index = 0;
	for (int i = 0; i < sizeOfArray; ++i) {
		if (theLargestSumOfDigit == SumOfDigit(array[i])) {
			result[index] = array[i];
			++index;
			result = realloc(result, sizeof(int) * (index + 1));
			if (result == NULL) {
				return 1;
			}
		}
	}

	*pointer = result;
	*sizeOfPointer = index;
	return 0;
}






void main() {
	int array[] = { 100, -50, -345, 435, 345, 23, 543 };
	int size = 7;
	int* pointer = NULL;
	int sizeOfPointer = 0;
	numbersWithTheLargestSumOfDigit(array, size, &pointer, &sizeOfPointer);
	for (int i = 0; i < sizeOfPointer; ++i) {
		printf("%i\n", pointer[i]);
	}

	free(pointer);
}