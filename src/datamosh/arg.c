#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This is an internal function, do not expose to a header file
 *
 * @param a
 * @param b
 * @return int
 */
int strcmp_safe(const char* a, const char* b) {
	if (a == NULL || b == NULL) {
		return 1;
	}

	return strcmp(a, b);
}

const char* get_option(
	const char* short_arg, const char* long_arg, const int argc,
	const char** argv, bool required) {
	for (int i = 1; i < argc; i++) {
		if ((strcmp_safe(argv[i], short_arg) == 0 ||
			 strcmp_safe(argv[i], long_arg) == 0) &&
			i != argc) {
			if (argv[i + 1][0] != '-') {
				return argv[i + 1];
			}
		}
	}

	if (required) {
		fprintf(
			stderr, "Required argument not given: %s\n",
			(long_arg != NULL) ? long_arg : short_arg);
		exit(EXIT_FAILURE);
	}

	return NULL;
}

bool option_exists(
	const char* short_arg, const char* long_arg, const int argc,
	const char** argv, bool required) {
	for (int i = 1; i < argc; i++) {
		if (strcmp_safe(argv[i], short_arg) == 0 ||
			strcmp_safe(argv[i], long_arg) == 0)
			return true;
	}

	if (required) {
		fprintf(
			stderr, "Required argument not given: %s\n",
			(long_arg != NULL) ? long_arg : short_arg);
		exit(EXIT_FAILURE);
	}

	return false;
}