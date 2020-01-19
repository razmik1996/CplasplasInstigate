#include <iostream>
#include "utils.hpp"
#include "drowFunctions.hpp"  ///include functions

/**
@file main.cpp
@brief Menu
@author Razmik Martirosyan
*/

/**
@brief Function for printing menu
*/
void printmenu();

/**
@brief Function for switch block
@param switchNumber - variable for switching
*/
void inputSwitchNumber(int &switchNumber);

void printmenu() {
	std::cout << "What do you want to drow?" << std::endl;
	std::cout << " 1 - for triangle by width" << std::endl;
	std::cout << " 2 - for triangle by hight" << std::endl;
	std::cout << " 3 - for diamond" << std::endl;
	std::cout << " 4 - for not filled diamond" << std::endl;
	std::cout << "-1 - for exit" << std::endl;

}

void inputSwitchNumber(int &switchNumber) {
	giveInput(switchNumber, 1, 4);	
	switch(switchNumber) {
		case 1:
			drawTriangleWidth();
			break;
		case 2:
			drawTriangleHeight();
			break;
		case 3:
			drawDiamond();
			break;
		case 4:
			drawNotFilledDiamond();
			break;
		default:
			std::cout << "Invalid input please trype from 1 to 4: ";
			break;
	}
}

int main() {
	while(true) {
		int switchNumber = 0;
		printmenu();
		inputSwitchNumber(switchNumber);
	}
	return 0;
}
