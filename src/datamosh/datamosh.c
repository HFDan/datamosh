#include <datamosh/monolithic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, const char** argv) {
	const char* mogus = get_option("--sus", "-s", argc, argv);
	printf("You inputted: %s\n", mogus);
	// char* fileToOpen = NULL;
	// int count = 3;
	// srand(time(NULL));

	// if (argc < 2) {
	// 	fprintf(stderr, "Error: Not enough arguments given\n");
	// 	return 1;
	// } else if (argc > 3) {
	// 	fprintf(stderr, "Error: Too many arguments given!\n");
	// 	return 1;
	// }

	// fileToOpen = argv[1];
	// count = atoi(argv[2]);

	// FILE* file = fopen(fileToOpen, "rb+");

	// struct image img = Jpeg_DetermineRealImageCoords(file);

	// for (int i = 0; i < count; i++) {
	// 	fseek(file, rand_range(img.start, img.end), SEEK_SET);
	// 	long int foo = rand_range(1, 255);
	// 	fwrite(&foo, sizeof(long int), 1, file);
	// }

	// fclose(file);

	// return 0;
}