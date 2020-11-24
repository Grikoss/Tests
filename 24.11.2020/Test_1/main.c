#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "test_1.h"

void main() {
	List* list = createNewList();
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("File not found\n");
		return;
	}

	char string[100];
	fgets(string, sizeof(string), file);
	fillList(list, string);
	printf("Before:\n");
	while (getLastItem(list) != NULL) {
		puts(getLastItem(list));
		deleteElement(list);
	}

	fillList(list, string);
	list = doABarrelRoll(list);
	printf("\nAfter:\n");
	while (getLastItem(list) != NULL) {
		puts(getLastItem(list));
		deleteElement(list);
	}

	deleteList(&list);
}