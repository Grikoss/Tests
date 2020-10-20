#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("File not found!");
		return;
	}

	char* string = (char*)malloc(sizeof(char));
	char buffer = '1';
	int index = 0;
	while (!feof(file)) {
		buffer = fgetc(file);
		if (buffer == ';') {
			while (buffer != '\n' && !feof(file)) {
				buffer = fgetc(file);
				string[index] = buffer;
				++index;
				string = realloc(string, sizeof(char) * (index + 1));
			}
		}
	}
	
	fclose(file);
	for (int i = 0; i <= index - 1; ++i) {
		printf("%c", string[i]);
	}
	free(string);
}
