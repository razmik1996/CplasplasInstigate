/**
@file Exercises.hpp
@brief Prototypes of functions for exercises
@author Razmik Martirosyan
*/

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

/**
@brief print all the elements from an array
@param &array - reference to first element from array
@param size - size of array
*/
void printArray(const int &array, const int &size);

/**
@brief write to array
@param &array - reference to first element from array
@param size - size of array
*/
void writeArray(int &array, const int &size);

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
@brief find from array min and max elements and print it
@param *array - const reference to array
@param &size - const reference to size
@return int * - pointer to minMax array (first element is min second max)
*/
int * minAndMax(const int *array, const int &size);

/**
@brief function for calculating how many times each of numbers have been entered 
*/
void ocurNumbers();

/**
@brief from decimal to binary
*/
std::string decToBin(int &decimal);

/**
@brief from binary to decimal
*/
int binToDec(std::string &binary);

/**
@brief Sum of all elements from array 
*/
int sumOfArray(const int *array, const int &size);

/**
@brief Sort array by using quickSort()
*/
void sortArray(int &array, const int &size);
