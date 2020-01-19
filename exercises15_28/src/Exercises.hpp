/**
@file Exercises.hpp
@brief Prototypes of functions for exercises
@author Razmik Martirosyan
*/

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
@param *array - pointer to first element from array
@param size - reference to size of array
*/
int sumOfArray(const int *array, const int &size);

/**
@brief Sort array by using quickSort()
@param *array - pointer to first element from array
@param size - reference to size of array
*/
void sortArray(int *array, const int &size);

/**
@brief pirnt from to elements from an array
@param *array - pointer to first element from array
@param from - from elemenet
@param to - to element 
*/
void printArrayCount(const int *array, int from, int to);

/**
@brief quickSort implementation
@param *array - pointer to first element from array
@param low - from elemenet
@param high - to element 
*/
void quickSort(int *array, int low, int high);

/**
@brief swap two integers
@param num1 - first integer
@param num2 - second integer
*/
void swap(int* num1, int* num2);

/**
@brief split array
@param *array - pointer to first element from array
@param low - from elemenet
@param high - to element 
*/
int partition(int *array, int low, int high);