#include <datamosh/monolithic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, const char** argv) {
	char* fileToOpen = NULL;
	int count = 3;
	srand(time(NULL));
	FILE* file;

	fileToOpen = get_option("-f", "--file", argc, argv, true);

	if (get_option("-c", "--count", argc, argv, false) != NULL)
		count = atoi(get_option("-c", "--count", argc, argv, false));

	file = fopen(fileToOpen, "rb+");

	struct image img = Jpeg_DetermineRealImageCoords(file);

	for (int i = 0; i < count; i++) {
		fseek(file, rand_range(img.start, img.end), SEEK_SET);
		long int foo = rand_range(1, 255);
		fwrite(&foo, sizeof(long int), 1, file);
	}

	fclose(file);

	return 0;
}