#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

int fillList(List* list, char* input) {
	int intputCount = 0;
	char currentCharacter = input[intputCount];
	++intputCount;
	while (currentCharacter != '\n' && currentCharacter != '\0') {
		int count = 0;
		int size = 1;
		char* tmp = NULL;
		char* buffer = (char*)malloc(sizeof(char));
		if (buffer == NULL) {
			return 1;
		}

		while (currentCharacter >= '0' && currentCharacter <= '9') {
			if (count >= size - 1) {
				size *= 2;
				tmp = (char*)realloc(buffer, sizeof(char) * size);
				if (tmp == NULL) {
					free(buffer);
					return 1;
				}
				else {
					buffer = tmp;
				}
			}

			buffer[count] = currentCharacter;
			++count;
			currentCharacter = input[intputCount];
			++intputCount;
		}

		buffer[count] = '\0';
		if (count <= 0) {
			free(buffer);
		}
		else {
			addElement(list, buffer);
		}
		
		if (currentCharacter == '\0' || currentCharacter == '\n') {
			break;
		}

		currentCharacter = input[intputCount];
		++intputCount;
	}

	return 0;
}

List* doABarrelRoll(List* listInput) {
	List* listOutput = createNewList();
	while (getLastItem(listInput) != NULL) {
		char* buffer = (char*)malloc(sizeof(getLastItem(listInput)));
		if (buffer == NULL) {
			return NULL;
		}

		memcpy(buffer, getLastItem(listInput), strlen(getLastItem(listInput)) + 1);
		addElement(listOutput, buffer);
		deleteElement(listInput);
	}
	
	deleteList(&listInput);
	return listOutput;
}