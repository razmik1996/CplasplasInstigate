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