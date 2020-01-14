/**
@file Exercises.hpp
@brief Prototypes of functions for exercises
@author Razmik Martirosyan
*/

/**
@brief take arithmetic operators and do it
*/
void arithmeticOper();

/**
@brief take number and revese it
*/
void reverseTheNumber();

/**
@brief Pc guess your number
*/
void guessTheNumber();

/**
@brief give valid input from user
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

