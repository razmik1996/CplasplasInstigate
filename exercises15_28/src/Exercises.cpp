#include <iostream>
#include <limits>
#include <string>
#include "utils.hpp"

int sumOfArray(const int *array, const int &size) {
	int sum = 0;
	for(int i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum;
}

void printArrayCount(const int *array, int from, int to) {
	std::cout << "element\tcount" << std::endl;
	for (from; from <= to; ++from) {
		std::cout << from << "\t" << array[from] << std::endl;
	}
}

int * minAndMax(const int *array, const int &size) {
	static int minMax[2] = {0};    /// first element is minimum second maximum
	minMax[0] = array[0];
	minMax[1] = array[0];
	for(int i = 0; i < size; ++i) {
		if(array[i] < minMax[0]) {
			minMax[0] = array[i];
		}
		if(array[i] > minMax[1]) {
			minMax[1] = array[i];
		}
	}
	return minMax;
}

void ocurNumbers() {
	const int SIZE = 11;
	int *array = new int[SIZE]{0};
	int input;
	std::cout << "\nOccurence of numbers" << std::endl;
	std::cout << "Enter the value from 1 to 10" << std::endl;
	std::cout << "For print of occurence input 0" << std::endl;
	std::cout << "For exit from program input -1" << std::endl;
	while (input != 0) {
			giveInput(input, 0, 10);
			++array[input];
	}
	printArrayCount(array, 1, 10);
}

void swap(int* num1, int* num2)  
{  
    int tmp = *num1;  
    *num1 = *num2;  
    *num2 = tmp;  
}  

int partition(int *array, int low, int high) {  
    int pivot = array[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {   
        if (array[j] < pivot) {  
            i++;
            swap(&array[i], &array[j]);  
        }  
    }  
    swap(&array[i + 1], &array[high]);  
    return (i + 1);  
}  

void quickSort(int *array, int low, int high) {  
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);  
        quickSort(array, pi + 1, high);  
    }  
}  

void sortArray(int *array, const int &size) {
	quickSort(array, 0, size);
}