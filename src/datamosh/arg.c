#include <stdbool.h>
#include <string.h>

const char* get_option(
	const char* short_arg, const char* long_arg, const int argc,
	const char** argv) {
	for (int i = 1; i < argc; i++) {
		if ((strcmp(argv[i], short_arg) == 0 ||
			 strcmp(argv[i], long_arg) == 0) &&
			i != argc) {
			if (argv[i + 1][0] != '-') {
				return argv[i + 1];
			}
		}
	}

	return NULL;
}

bool option_exists(
	const char* short_arg, const char* long_arg, const int argc,
	const char** argv) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], short_arg) == 0 || strcmp(argv[i], long_arg) == 0)
			return true;
	}

	return false;
}