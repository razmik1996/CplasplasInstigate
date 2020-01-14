#include <iostream>
#include <limits>
#include <string>

/**
@brief give valid input number from user in range (from to)
@param &input - reference to input number
@param from, to - range for valid input
*/
void giveInput(int &input, int from, int to);

/**
@brief give valid input operator (+, -, /, *)
@param &input - reference to input char variable
*/
void giveInputOperator(char &input);

/**
@brief count first and second operands with oper operator
@param first - first integer
@param second - second integer
@param oper - +, -, /, * arithmetic operator
*/
void count(int first, int second, char oper);

/**
@brief take from user low, high or correct answers
@param &userInput - reference to string variable for input
*/
void takeUserInput(std::string &userInput);

/**
@brief change minimum and maximum by using userInput
@param &userInput - take user Inputed string
@param &min - reference to min variable
@param &max - reference to max variable
@param &number - reference to number for changing min or max
*/
void minMaxChanger(std::string &userInput, int &min, int &max, int &number);

void arithmeticOper() {
	int number1 = 0;
	int number2 = 0;
	char arithmetic = '+';
	std::cout << "Input first number: ";
	giveInput(number1, -2147483647, 2147483647);
	std::cout << "Input arithmetic operator: ";
	giveInputOperator(arithmetic);
	std::cout << "Input second number: ";
	giveInput(number2, -2147483647, 2147483647);
	count(number1, number2, arithmetic);
}

void reverseTheNumber() {
	int number = 0;
	int reverse = 0;
	int rem = 0;
	std::cout << "Enter a number: ";
	giveInput(number, -2147483647, 2147483647);
	while(number != 0) {
		rem = number % 10;
		reverse = (reverse * 10) + rem;
		number /= 10;
	}
	std::cout << "Reverse number is: " << reverse << std::endl;
}

void guessTheNumber() {
	std::string userInput;
	srand(time(0));
	int min = 0;
	int max = 100;
	std::cout << "Guess The Number revesed\n" << std::endl;
	std::cout << "Type high if your number less than PC" << std::endl;
	std::cout << "Type low if your number high than PC" << std::endl;
	std::cout << "Type correct if your number equal PC" << std::endl;
	do{
		int number = (max + min) / 2;
		std::cout << "\nThe computer's guess is " << number << std::endl;
		std::cout << "\nIs the number yoo high, too low, or correct?: ";
		takeUserInput(userInput);
		if(userInput == "correct") {
			continue;
		}
		minMaxChanger(userInput, min, max, number);
	} while(userInput != "correct");
	std::cout << "\nThe computer's guess the number." << std::endl;
}

void minMaxChanger(std::string &userInput, int &min, int &max, int &number){
	if (userInput == "high") {
		std::cout << "\nThe guess was too high." << std::endl;
		max = number;
	}		
	if (userInput == "low") {
		std::cout << "\nThe guess was too low." << std::endl;
		min = number;
	}	
}

void takeUserInput(std::string &userInput){
	while(true) {
		std::cin >> userInput;
		if (userInput == "high" || userInput == "low" || userInput == "correct") {
			return;
		} else {
			std::cout << "Your input is invalid please type low, high or correct: ";
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

void count(int number1, int number2, char oper){
	switch(oper) {
		case '+':
			std::cout << "Sum of two numbers is: ";
			std::cout << number1 + number2 << std::endl;
			break;
		case '-':
			std::cout << "Substraction of two numbers is: ";
			std::cout << number1 - number2 << std::endl;
			break;
		case '/':
			std::cout << "Division of two numbers is: ";
			std::cout << number1 / number2 << std::endl;
			break;
		case '*':
			std::cout << "Mult of two numbers is: ";
			std::cout << number1 * number2 << std::endl;
			break;
	}
}

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
		if(input == -1) {               ///exit when customer type -1
			std::cout << "Good Bye!!!" << std::endl;
			exit(0);
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

