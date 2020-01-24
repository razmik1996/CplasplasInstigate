#ifndef UTILS_HPP
#define UTILS_HPP

/**
@file utils.hpp
@author Razmik Martirosyan
@brief utilites for our programs
*/

/**
@brief Take valid input from customer
@param &inp - reference to varriable for input
@param f,l - input range
*/
void giveInput(int &inp, int f, int l);

/**
@brief give valid input operator (+, -, /, *)
@param &input - reference to input char variable
*/
void giveInputOperator(char &input);

/**
@brief print all the elements from an array
@param &array - reference to first element from array
@param size - size of array
*/
void printArray(const int *array, const int &size);

/**
@brief generate random array
@param &array - reference to first element from array
@param size - size of array
*/
void randArray(int *array, const int &size);

#endif ///UTILS_HPP