#include <stdlib.h>

long int rand_range(int begin, int end) {
	if (begin > end) return 0;

	return (rand() % (end - begin + 1)) + begin;
}