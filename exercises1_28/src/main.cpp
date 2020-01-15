#include <iostream>
#include <ctime>
#include "Exercises.hpp"

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

void printMenu() {
	std::cout << "Select exercises number" << std::endl;
	std::cout << " 1 - for exercise 1 (arithmetic operations)" << std::endl;
	std::cout << " 5 - for exercise 5 (reverse int number)" << std::endl;
	std::cout << "14 - for exercise 14 (guess the number role changed)" << std::endl;
	std::cout << "15 - for exercise 15 (minimum and maximum from array)" << std::endl;
	std::cout << "16 - for exercise 16 (not ended)" << std::endl;
	std::cout << "17 - for exercise 17 (not ended)" << std::endl;
	std::cout << "18 - for exercise 18 (not ended)" << std::endl;
	std::cout << "21 - for exercise 21 (sum of array elements)" << std::endl;
//	std::cout << "23 - for exercise 23" << std::endl;
	std::cout << "-1 - exit" << std::endl;
}

void switchCase(int &switchNumber) {
	giveInput(switchNumber, 1, 23);
	switch(switchNumber) {
		case 1:
			arithmeticOper();
			break;
		case 5:
			reverseTheNumber();
			break;
		case 14:
			guessTheNumber();
			break;
		case 15:
			minAndMaxMiniProgram();
			break;
		case 16:
	//		ocurNumbers();
			break;
		case 17:
	//		decToBin();
			break;
		case 18:
	//		binToDec();
			break;
		case 21:
			sumOfArrayMiniProgram();
			break;
		case 23:
	//		sortArray();
			break;
		case -1:
			std::cout << "Good Bye!!!" << std::endl;
			exit(0);
		default:
			std::cout << "Invalid number please set 1, 5, 14-18, 21 or 23: ";
	}
}

void sumOfArrayMiniProgram() {
	srand(time(NULL));
	int sum = 0;
	const int SIZE = 10;
	int *array = new int[SIZE];
	for(int i = 0; i < SIZE; ++i) {
		array[i] = rand() % 100;
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	sum = sumOfArray(array, SIZE);
	std::cout << "Sum of all elements is: " << sum << std::endl;
}

void minAndMaxMiniProgram() {
	srand(time(NULL));
	const int SIZE = 10;
	int *array = new int[SIZE];
	int *minMax = new int[2];
	for(int i = 0; i < SIZE; ++i) {
		array[i] = rand() % 100;
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	minMax = minAndMax(array, SIZE);
	std::cout << "Min element is: " << minMax[0] << " Max element is: " << minMax[1];
	std::cout << std::endl;
	delete[] array;
}

int main() {
	while(true) {
		int switchNumber = 0;
		printMenu();
		switchCase(switchNumber);
	}
	return 0;
}

