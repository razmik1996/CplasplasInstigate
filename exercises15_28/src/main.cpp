#include <iostream>
#include "Exercises.hpp"
#include "utils.hpp"

/**
@file main.cpp
@brief Menu
@author Razmik Martirosyan
*/

/**
@brief function for printing menu 
*/
void printMenu();

/**
@brief Function for switch menu case
@param &switchNumber - reference to switch number
*/
void switchCase(int &switchNumber);

/**
@brief Mini program to test min and max
*/
void minAndMaxMiniProgram();

/**
@brief Mini program to test sum of all elements in array 
*/
void sumOfArrayMiniProgram();

/**
@brief Mini program for using sort solution
*/
void sortArrayMiniProgram();

void printMenu() {
	std::cout << "Select exercises number" << std::endl;
	std::cout << "15 - for exercise 15 (minimum and maximum from array)" << std::endl;
	std::cout << "16 - for exercise 16 (occurence of numbers)" << std::endl;
	std::cout << "17 - for exercise 17 (not ended)" << std::endl;
	std::cout << "18 - for exercise 18 (not ended)" << std::endl;
	std::cout << "21 - for exercise 21 (sum of array elements)" << std::endl;
	std::cout << "23 - for exercise 23 (sorting)" << std::endl;
	std::cout << "-1 - exit" << std::endl;
}

void switchCase(int &switchNumber) {
	giveInput(switchNumber, 15, 23);
	switch(switchNumber) {
		case 15:
			minAndMaxMiniProgram();
			break;
		case 16:
			ocurNumbers();
			break;
		case 17:
//			decToBin();
			break;
		case 18:
//			binToDec();
			break;
		case 21:
			sumOfArrayMiniProgram();
			break;
		case 23:
			sortArrayMiniProgram();
			break;
		case -1:
			std::cout << "Good Bye!!!" << std::endl;
			exit(0);
		default:
			std::cout << "Invalid number please set 15-18, 21 or 23: ";
	}
}

void sumOfArrayMiniProgram() {
	int sum = 0;
	const int SIZE = 10;
	int *array = new int[SIZE];
	randArray(array, SIZE);
	printArray(array, SIZE);
	std::cout << std::endl;
	sum = sumOfArray(array, SIZE);
	std::cout << "Sum of all elements is: " << sum << std::endl;
}

void minAndMaxMiniProgram() {
	const int SIZE = 10;
	int *array = new int[SIZE];
	int *minMax = new int[2];
	randArray(array, SIZE);
	printArray(array, SIZE);
	std::cout << std::endl;
	minMax = minAndMax(array, SIZE);
	std::cout << "Min element is: " << minMax[0] << " Max element is: " << minMax[1];
	std::cout << std::endl;
	delete[] array;
}

void sortArrayMiniProgram() {
	const int SIZE = 10;
	int *array = new int[SIZE];
	randArray(array, SIZE);
	printArray(array, SIZE);
	std::cout << std::endl;
	sortArray(array, SIZE);
	printArray(array, SIZE);
}

int main() {
	while(true) {
		int switchNumber = 0;
		printMenu();
		switchCase(switchNumber);
	}
	return 0;
}

