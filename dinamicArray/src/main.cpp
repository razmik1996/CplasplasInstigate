#include <iostream>
#include <string>
#include "dynArray.hpp"
#include "utils.hpp"

int miniProgramforTest() {
    int SIZE = 10;
    Dyn_array<int> vector;
    Dyn_array<float> vectorFloat(SIZE, 0.5);
    Dyn_array<char> vectorChar(SIZE, 16, 'a');

    int * ptr = new int[SIZE];
    randArray(ptr, SIZE);
    Dyn_array<int> vectorArray(ptr, SIZE);

    Dyn_array<std::string> vectorString(SIZE, 15, "");


    
    vector.push_back(5);
    std::cout << "Pushing 5 to dinamic array" << std::endl;
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Print first element of dinamic array" << std::endl;
    std::cout << vector[0] << std::endl;
    std::cout << "Pushing 8 to dinamic array" << std::endl;
    vector.push_back(8);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 20 to dinamic array" << std::endl;
    vector.push_back(20);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 15 to dinamic array" << std::endl;
    vector.push_back(15);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 13 to dinamic array" << std::endl;
    vector.push_back(13);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 3 to dinamic array" << std::endl;
    vector.push_back(3);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 3 to dinamic array" << std::endl;
    vector.push_back(3);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 3 to dinamic array" << std::endl;
    vector.push_back(3);
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Printing dinamic array" << std::endl;
    std::cout << vector << std::endl;
    std::cout << "Poping element from dinamic array" << std::endl;
    vector.pop_back();
    std::cout << "Printing dinamic array" << std::endl;
    std::cout << vector << std::endl;
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "After shrink to fit" << std::endl;
    vector.shrnk_to_fit();
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Printing dinamic array" << std::endl;
    std::cout << vector << std::endl;
}

int main() {
    miniProgramforTest();
    return 0;
}