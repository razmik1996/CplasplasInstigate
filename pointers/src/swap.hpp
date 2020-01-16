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
