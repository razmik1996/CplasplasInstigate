#ifndef SWAP_HPP
#define SWAP_HPP

/**
@file swap.hpp
@brief prototypes for swaping function
@author Razmik Martirosyan
*/

/**
@brief function for swaping two values by using byte copying
@param void *a - void pointer to first element
@param void *b - void pointer to second element
@param size_t size - sizeof element
*/
void swap(void *a, void *b, size_t size);

/**
@brief function for swaping two values by using third element
@param int &a - reference to first element
@param int &b - reference to second element
*/
void swapClassic(int &a, int &b);

/**
@brief function for swaping two values by using XOR
@param int &a - reference to first element
@param int &b - reference to second element
*/
void swapXor(int &a, int &b);

#endif ///SWAP_HPP