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

#endif ///UTILS_HPP