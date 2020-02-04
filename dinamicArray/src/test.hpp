#ifndef TEST_HPP
#define TEST_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>
#include "dynArray.hpp"
#include "utils.hpp"

void test_constructors();
void test_member_functions();
void test_algorithms();

/**
@brief test all constructors
*/
void test_constructors() {
    const int SIZE = 10;
    const int DEF_CAPACITY = 16;
    const int FROM = 2;
    const int TO = 7;
    ///Default constructor
    Dyn_array<int> vectorInt;
    assert(0 == vectorInt.size() && 0 == vectorInt.capacity());
    ///Constructor with size and default value
    Dyn_array<float> vectorFloat(SIZE, 0.8);
    assert(SIZE == vectorFloat.size() && SIZE + 1 == vectorFloat.capacity());
    ///Constructor with Size, capacity and default value
    Dyn_array<std::string> vectorString(SIZE, DEF_CAPACITY, "Hello"); 
    assert(SIZE == vectorString.size() && 
        DEF_CAPACITY == vectorString.capacity());
    assert("Hello" == vectorString[0]);
    ///Creating an array
    int* array = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array[i] = i;
    }
    ///Constructor with array
    Dyn_array<int> vectorArray(array, SIZE);
    assert(SIZE == vectorArray.size());
    ///Constructor with array range
    Dyn_array<int> vectorFromTo(array, FROM, TO);
    assert((TO - FROM) == vectorFromTo.size());
    ///Creating STL vector
    std::vector<int> vec1 = {1, 5, 6, 7, 2, 3, 2};
    ///Constructor with begin end vector iterators
    Dyn_array<int> vec2(vec1.begin(), vec1.end());
    assert(vec2.size() == vec1.size());
    ///Creating a list
    std::list<int> list1;
    list1.push_back(5);
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(3);
    ///Constructor with begin end list iterators
    Dyn_array<int> vec3(list1.begin(), list1.end());
    assert(vec3.size() == list1.size());
    ///Iterator constructor test
    Dyn_array<int>::iterator it;
    Dyn_array<int>::iterator it1 = vec3.begin();
    Dyn_array<int>::iterator iterInt(vec3.begin());
}

void test_member_functions() {
    const int SIZE = 10;
    const int RESERVE_VALUE = 50;
    ///creating Din_array object
    Dyn_array<int> vector;
    ///testing is empty
    assert(vector.is_empty());
    ///pushing 5 to dinamic array
    vector.push_back(5);
    assert(5 == vector[0]);
    assert(1 == vector.size());
    assert(2 == vector.capacity());
    ///Pushing 8 to dinamic array
    vector.push_back(8);
    assert(8 == vector[1]);
    assert(2 == vector.size());
    ///Pushing 20 to dinamic array"
    vector.push_back(20);
    assert(20 == vector[2]);
    assert(3 == vector.size());
    ///Pushing 15 to dinamic array"
    vector.push_back(15);
    ///Pushing 13 to dinamic array"
    vector.push_back(13);
    ///Pushing 3 to dinamic array"
    vector.push_back(3);
    ///Pushing 3 to dinamic array"
    vector.push_back(3);
    ///Pushing 3 to dinamic array"
    vector.push_back(3);
    assert(8 == vector.size());
    ///poping last element from dinamic array
    vector.pop_back();
    assert(7 == vector.size());
    ///using shrink to fit
    vector.shrnk_to_fit();
    assert(vector.capacity() == vector.size());
    ///using reserve
    vector.reserve(RESERVE_VALUE);
    assert(RESERVE_VALUE <= vector.capacity());
    vector.clear();
    assert(0 == vector.size());
    vector.insert(0, 5);
    assert(1 == vector.size());
}

void test_algorithms() {
    const int SIZE = 10;
    int* array = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array[i] = i;
    }
    Dyn_array<int> vector(array, SIZE);
    assert(SIZE == vector.size());
    std::replace(vector.begin(), vector.end(), 4, 5);
    assert(vector[4] == 5);
}

#endif // TEST_HPP