#include <cstdlib>

void swap(void *a, void *b, size_t size) {
	char tmp;
	int i;
	for (i = 0; i < size; ++i) {
		tmp = *((char*)b + i);
		*((char*) b + i) = *((char*) a + i);
		*((char*) a + i) = tmp;
	}
}
