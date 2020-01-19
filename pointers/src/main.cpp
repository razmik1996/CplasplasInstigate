#include <iostream>
#include "postfixPrefix.hpp"
#include "swap.hpp"
#include "utils.hpp"

/**
@file main.cpp
@author Razmik Martirosyan
@brief main file
*/

/**
@brief Mini program to test postfix and prefix increments
*/
void postfixPrefixMiniProgram();

/**
@brief Mini program to test swap two integers
*/
void swapMiniProgram();

/**
@brief function for printing menu 
*/
void printMenu();

/**
@brief function for selecting 
@param &switchNumber - reference to user input for menu;
*/
void switchCase(int &switchNumber);

void printMenu() {
	std::cout << "\nThere are two mini programs to test exercises" << std::endl;
	std::cout << "Select exercises number" << std::endl;
	std::cout << " 1 - for postfix and prefix increments" << std::endl;
	std::cout << " 2 - for swap two integers" << std::endl;
	std::cout << "-1 - exit\n" << std::endl;
}

void switchCase(int &switchNumber) {
	giveInput(switchNumber, 1, 2);
	switch(switchNumber) {
		case 1:
			postfixPrefixMiniProgram();
			break;
		case 2:
			swapMiniProgram();
			break;
		case -1:
			std::cout << "Good Bye!!!" << std::endl;
			exit(0);
		default:
			std::cout << "Invalid number please set 1 or 2: ";
	}
}

void swapMiniProgram() {
	std::cout << "Program to swap two values started\n" << std::endl;
	int x = 5;
	int y = 8;
	std::cout << "Before swap x = " << x << " y = " << y << std::endl;
	swap(&x, &y, sizeof(x));
	std::cout << "After swap x = " << x;
	std::cout << " y = " << y << std::endl << std::endl;
	std::cout << "Before swap with classic way x = " << x << " y = " << y << std::endl;
	swapClassic(x, y);
	std::cout << "After swap  with classic way x = " << x;
	std::cout << " y = " << y << std::endl << std::endl;
	std::cout << "Before swap with XOR x = " << x << " y = " << y << std::endl;
	swapXor(x, y);
	std::cout << "After swap with XOR x = " << x;
	std::cout << " y = " << y << std::endl << std::endl;
	long double a = 55421.5454545;
	long double b = 64842.5471263;
	std::cout << "Before swap a = " << a << " b = " << b << std::endl;
	swap(&a, &b, sizeof(a));
	std::cout << "After swap a = " << a;
	std::cout << " b = " << b << std::endl << std::endl;
}

void postfixPrefixMiniProgram() {
	std::cout << "Program postfix and prefix increment started\n" << std::endl;

	int x = 5;
	std::cout << "Before postfixPlasPlas x = " << x << std::endl;
	std::cout << "During x = " << postfixPlasPlas(&x) << std::endl;
	std::cout << "After postfixPlasPlas x = " << x << std::endl;

	x = 5;
	std::cout << "Before prefixPlasPlas x = " << x << std::endl;
	std::cout << "During x = " << prefixPlasPlas(&x) << std::endl;
	std::cout << "After prefixPlasPlas x = " << x << std::endl;
}

int main() {
	while(true) {
		int switchNumber = 0;
		printMenu();
		switchCase(switchNumber);
	}
	return 0;
}
