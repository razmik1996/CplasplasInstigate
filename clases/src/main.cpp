#include <iostream>
#include "classExperiments.hpp"

/**
@file main.cpp
@brief Test Program
@author Razmik Martirosyan
*/

///Testing class
int main() {
    ///Creating 4 sized array for Person*
    const int SIZE = 4;
	Person** array = new Person*[SIZE];

    std::cout << "creating student object with def constructor" << std::endl;
    Student *student1 = new Student;
    std::cout << "\ncreating student object with constructor" << std::endl;
    Student *student2 = new Student(18, 180, "Ani", "Vardanyan", 3);

    std::cout << "\ncreating teacher object with def constructor" << std::endl;
    Teacher *teacher1 = new Teacher;
    std::cout << "\ncreating teacher object with constructor" << std::endl;
    Teacher *teacher2 = new Teacher(35, 165, "Karine", "Minasyan", "Philosophy");

    std::cout << "\ncreating assistent object with def constructor" << std::endl;
    Assistent *assistent1 = new Assistent;
    std::cout << "\ncreating assistent object with constructor 1" << std::endl;
    Assistent *assistent2 = new Assistent(23, 190, "Vardan", "Grigoryan", "Biology", 5);
    std::cout << "\ncreating assistent object with constructor 2" << std::endl;
    Assistent *assistent3 = new Assistent(24, 180, "Karen", "Nahapetyan", "Software Developer", 6);

    array[0] = student1; // first pointer to student
    array[1] = student2; // second pointer to student
    array[2] = teacher1; // third pointer to teacher
    array[3] = teacher2; // fourth pointer to teacher

    assistent1->read();
//    assistent1->write(); // error diamond problem

    for (int i = 0; i < SIZE; ++i) {
        array[i]->walk();
        array[i]->write();
        array[i]->read();
    }
    for (int i = 0; i < SIZE; ++i) {
        delete array[i];
    }
    delete assistent1;
    delete assistent2;
    delete assistent3;
    delete[] array;
    return 0;
}
