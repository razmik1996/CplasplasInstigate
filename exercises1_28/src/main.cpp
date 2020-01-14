#include <iostream>
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

void printMenu() {
	std::cout << "Select exercises number" << std::endl;
	std::cout << " 1 - for exercises 1" << std::endl;
	std::cout << " 5 - for exercises 5" << std::endl;
	std::cout << "14 - for exercises 14" << std::endl;
	std::cout << "-1 - exit" << std::endl;
}

void switchCase(int &switchNumber) {
	giveInput(switchNumber, 1, 14);
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
		case -1:
			std::cout << "Good Bye!!!" << std::endl;
			exit(0);
		default:
			std::cout << "Invalid number please set 1, 5 or 14: ";
	}
}

int main() {
	while(true) {
		int switchNumber = 0;
		printMenu();
		switchCase(switchNumber);
	}
	return 0;
}

