#include <iostream>
#include "Exercises.hpp"

void printMenu(int &);
void switchCase(int &);

int main() {
	int switchNumber = 0;
	printMenu(&switchNumber);
}

void printMenu(int &switchNumber) {
	std::cout << "Select exercises number" << std::endl;
	std::cout << "1 - for exercises 1" << std::endl;
	std::cout << "5 - for exercises 5" << std::endl;
	std::cout << "14 - for exercises 14" << std::endl;
	std::cin >> switchNumber;
}

void switchCase(int &switchNumber) {
	
}
