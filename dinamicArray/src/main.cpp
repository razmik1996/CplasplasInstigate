#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "dynArray.hpp"
#include "utils.hpp"

int miniProgramforTest() {
    int SIZE = 10;
    Dyn_array<int> vector;
    if(vector.size() != 0) {
        std::cout << "vector created with default constructor but size is not 0" << std::endl;
        abort();
    }
    Dyn_array<float> vectorFloat(SIZE, 0.5);
    if(vectorFloat.size() != SIZE) {
        std::cout << "vectorFloat created with m_size = SIZE but m_size is not SIZE" << std::endl;
        abort();
    }
    Dyn_array<char> vectorChar(SIZE, 16, 'a');
    if(vectorChar.size() != SIZE) {
        std::cout << "vectorChar created with m_size = SIZE but m_size is not SIZE" << std::endl;
        abort();
    }
    if(vectorChar.capacity() != 16) {
        std::cout << "vectorChar created with m_capacity = 16 but m_capacity is not 16" << std::endl;
        abort();
    }
    int * ptr = new int[SIZE];
    randArray(ptr, SIZE);
    Dyn_array<int> vectorArray(ptr, SIZE);
    if(vectorArray.size() != SIZE) {
        std::cout << "vectorArray created with m_size = SIZE but m_size is not SIZE" << std::endl;
        abort();
    }

    Dyn_array<std::string> vectorString(SIZE, 15, "");
    
    vector.push_back(5);
    if(vector[0] != 5) {
        std::cout << "pushed 5 to 0 element but vector[0] is not 5" << std::endl;
        abort();
    }
    std::cout << "Pushing 5 to dinamic array" << std::endl;
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Print first element of dinamic array" << std::endl;
    std::cout << vector[0] << std::endl;
    std::cout << "Pushing 8 to dinamic array" << std::endl;
    vector.push_back(8);
    if(vector[1] != 8) {
        std::cout << "pushed 8 to 1 element but vector[1] is not 8" << std::endl;
        abort();
    }
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 20 to dinamic array" << std::endl;
    vector.push_back(20);
    if(vector[2] != 20) {
        std::cout << "pushed 20 to 2 element but vector[2] is not 20" << std::endl;
        abort();
    }
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Pushing 15 to dinamic array" << std::endl;
    vector.push_back(15);
    if(vector[3] != 15) {
        std::cout << "pushed 15 to 3 element but vector[3] is not 15" << std::endl;
        abort();
    }
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
    if(vector.size() != vector.capacity()) {
        std::cout << "called shrink to fit function but size != capacity" << std::endl;
        abort();
    }
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is: " << vector.capacity() << std::endl;
    std::cout << "Printing dinamic array" << std::endl;
    std::cout << vector << std::endl;

    Dyn_array<int>::iterator iterInt(vector.begin());
    Dyn_array<float>::iterator iterFloat;
    iterFloat = vectorFloat.begin();
}

void miniProgramforTestAlgorithm() {
    const int SIZE = 10;
    int* array = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array[i] = i;
    }
    Dyn_array <int>vector(array, SIZE);
    if(vector.size() != SIZE) {
        std::cout << "vector created with m_size = SIZE but m_size is not SIZE" << std::endl;
        abort();
    }
    std::cout << "Vector size is: " << vector.size() << std::endl;
    std::cout << "Vector capacity is:" << vector.capacity() << std::endl;
    std::cout << "Vector elements before replace" << std::endl;
    std::cout << vector << std::endl;
    std::replace(vector.begin(), vector.end(), 4, 5);
    std::cout << "Vector elements after replace 5 instead 4" << std::endl;
    std::cout << vector << std::endl;
    if(vector[4] != 5) {
        std::cout << "After replace 4rd element of vector need to be 5" << std::endl;
        abort();
    }
}

int main() {
    miniProgramforTestAlgorithm();
    miniProgramforTest();
    return 0;
}