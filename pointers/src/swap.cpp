#include <cstdlib>

///Byte copying swap
void swap(void *a, void *b, size_t size) {
	char tmp;
	int i;
	for (i = 0; i < size; ++i) {
		tmp = *((char*)b + i);
		*((char*) b + i) = *((char*) a + i);
		*((char*) a + i) = tmp;
	}
}

///Swap with 3rd element
void swapClassic(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

///Swap by XOR
void swapXor(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}