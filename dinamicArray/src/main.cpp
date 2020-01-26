#include <iostream>
#include "dynArray.hpp"

int main() {
    Dyn_array<int> vector;
    vector.push_back(5);
    
    std::cout << vector << std::endl;
    return 0;
}