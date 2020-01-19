#ifndef DROWFUNCTIONS_HPP
#define DROWFUNCTIONS_HPP

/**
@file drowFunctions.hpp
@brief Prototypes of functions for drowing
@author Razmik Martirosyan
*/

/**
@brief Draw triangle by using width of basis
*/
void drawTriangleWidth();

/**
@brief Draw triangle by using height 
*/
void drawTriangleHeight();

/**
@brief Draw filled diamond
*/ 
void drawDiamond();

/**
@brief Draw not filled diamond
*/
void drawNotFilledDiamond();

/**
@brief Draw triangle loop
@param int &j = reference to columns
@param int &i = reference to rows 
*/
void drawTriangle(int &j, int &i);

/**
@brief print count amount of stars
@param count - amount of stars
*/
void printLineStar(const int &count);

/**
@brief print count amount of spaces
@param count - amount of spaces
*/
void printLineSpace(const int &count);

/**
@brief Check odd or even and when it's odd print first *
@param &row - reference to rows for adding 1 to row
@param &width - reference to width for checking
*/
void checkWidth(int &row, const int &width);

#endif //DROWFUNCTIONS_HPP