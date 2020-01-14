#include <iostream>
#include <limits>

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
		if(-1 == input) {               ///exit when customer type -1
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

void printLineStar(const int &count) {   ///print count stars
	for (int i = 0; i < count; ++i) {
		std::cout << "* ";
	}
}

void printLineSpace(const int &count) {  ///print count spaces
	for (int i = 0; i < count; ++i) {
		std::cout << "  ";
	}
}

void checkWidth(int &i, const int &width) {
	if(1 == (width % 2)) {
		printLineSpace(width / 2);
		std::cout << "* " << std::endl; ///if width is even print * and row set 1
		i = 1;
	}
}

///drow triangle by width
void drawTriangleWidth() {
	int width = 0;
       	int i = 0, j = 0;
	std::cout << "Enter width of base: ";
	giveInput(width, 3, 30);
	checkWidth(i, width);
	j = (width/2)-1;
	for(; j >= 0; --j) {
		printLineSpace(j);
		i += 2;
		printLineStar(i);
		std::cout << std::endl;
	}	
}

///drow triangle by height
void drawTriangleHeight() {
	int height = 0;
       	int i = 0, j = 0;
	std::cout << "Enter height of triangle: ";
	giveInput(height, 2, 30);
	int jcount = (2 * height)-1;
	for(i = 1; i <= height; ++i) {
		for(j = 1; j <= jcount; ++j) {
			if(j >= height - (i - 1) && j <= height + (i - 1)) {
				std::cout << "* ";
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

///drow filled diamond
void drawDiamond() {
	int width = 0;
       	int i = 0, j = 0;
	std::cout << "Enter width: ";
	giveInput(width, 3, 30);
	checkWidth(i, width);
	j = (width / 2) - 1;
	for(; j >= 0; --j) {
		printLineSpace(j);
		i += 2;
		printLineStar(i);
		std::cout << std::endl;
	}
	for(j = 1; j < width / 2; ++j) {
		printLineSpace(j);
		i -= 2;
		printLineStar(i);
		std::cout << std::endl;
	}
	checkWidth(i, width);
}

///drow not filled diamond
void drawNotFilledDiamond() {
	int width = 0;
       	int i = 0, j = 0;
	std::cout << "Enter width: ";
	giveInput(width, 3, 30);
	checkWidth(i, width);
	j = (width / 2) - 1;
	for(; j >= 0; --j) {
		printLineSpace(j);
		i += 2;
		printLineStar(1);
		printLineSpace(i-2);
		printLineStar(1);
		std::cout << std::endl;
	}
	for(j = 1; j < width / 2; ++j) {
		printLineSpace(j);
		i -= 2;
		printLineStar(1);
		printLineSpace(i-2);
		printLineStar(1);
		std::cout << std::endl;
	}
	checkWidth(i, width);
}
