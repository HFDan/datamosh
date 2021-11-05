#include <ctype.h>
#include <datamosh/format.h>
#include <stdlib.h>
#include <string.h>

enum fileFormat DetermineFileFormat(const char* fileName) {
	enum fileFormat fmt;
	char* copy = calloc(
		strlen(fileName),
		sizeof(char));	// We clone the string because the strtok() function
						// modifies the string. We do not want to mangle the
						// actual file name
	strcpy(copy, fileName);

	char* tok = strtok(copy, ".");

	while (tok != NULL) {
		for (int i = 0; tok[i]; i++) {
			tok[i] = tolower(tok[i]);
		}

		if (strcmp(tok, "jpg") == 0 || strcmp(tok, "jpeg") == 0)
			fmt = JPG;
		else
			fmt = UNSUPPORTED;

		tok = strtok(NULL, ".");
	}

	free(copy);
	return fmt;
}