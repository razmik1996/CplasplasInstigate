#include <iostream>
#include "test.hpp"

int main() {
    test_constructors();
    std::cout << "Constructors successfully tested" << std::endl;
    test_member_functions();
    std::cout << "Testing member functions was successful" << std::endl;
    test_algorithms();
    std::cout << "Algorithms tested successfully" << std::endl;
    test_my_algorithm();
    std::cout << "My algorithm is working correctly" << std::endl;
    std::cout << "All is okay..." << std::endl;
    return 0;
}
