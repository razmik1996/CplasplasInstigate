#include <iostream>
#include "utils.hpp"

int main() {
    const int SIZE = 10;
	int *array = new int[SIZE];
    randArray(array, SIZE);
    printArray(array, SIZE);

    return 0;
}
