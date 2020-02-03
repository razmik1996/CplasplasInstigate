#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

void giveInput(int &input, int from, int to) {
	while(true) {
		std::cin >> input;
		if(std::cin.fail()) {           ///catch fails
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You have entered wrong input enter number from " 
				  << from << " to " << to << ": ";
			continue;
		}
		if(-1 == input) {               ///exit when customer type -1
			std::cout << "Good Bye!!!" << std::endl;
			std::exit(0);
		}
		if(input < from || input > to) { ///validate input range
			std::cout << "Invalid input please enter number from " 
				  << from << " to " << to << ": ";
			continue;
		}	
		if(!std::cin.fail()) {   ///if all is okay
			break;
		}
	}
}

void giveInputOperator(char &input) {
	while(true) {
		std::cin >> input;
		switch(input) {
			case '+':
				return;
			case '-':
				return;
			case '/':
				return;
			case '*':
				return;
			default:
				std::cout << "Invalid operator please type + - * or /: ";
				break;
		}
	}
}

void printArray(const int *array, const int &size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void randArray(int *array, const int &size) {
	std::srand(time(NULL));
	for(int i = 0; i < size; ++i) {
		array[i] = std::rand() % 100;
	}
}