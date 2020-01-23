#include "classExperiments.hpp"
#include <iostream>

/**
@file Exercises.hpp
@brief Prototypes of functions for exercises
@author Razmik Martirosyan
*/

//static value initializing
int Person::count = 0;
int Student::count = 0;
int Teacher::count = 0;
int Assistent::count = 0;

///class Person
Person::Person(int age = 10, int height = 180, std::string name = "Poxos", std::string surname = "Poxosyan") {
    ++count;
    std::cout << "Constructor called for Person: " << count << std::endl;
    setAge(age);
    setHeight(height);
    setName(name);
    setSurname(surname);
}

void Person::setAge(int age) {
    this->age = ((age > 0) && (age < 150)) ? age : 10;
}

int Person::getAge() const {
    return age;
}

void Person::setHeight(int height) {
    this->height = ((height > 20) && (height < 250)) ? height : 180;
}

int Person::getHeight() const {
    return height;
}

void Person::setName(std::string name) {
    if (name.length() > 2 && name.length() < 30) {
        this->name = name;
    }
}

std::string Person::getName() const {
    return name;
}

void Person::setSurname(std::string surname) {
    if (surname.length() > 2 && surname.length() < 30) {
        this->surname = surname;
    }
}

std::string Person::getSurname() const {
    return surname;
}
    
void Person::walk() {
    std::cout << "Person is walking..." << std::endl;
}

void Person::read() {
    std::cout << "Person is reading..." << std::endl;
}

Person::~Person() {
    std::cout << "Destructor for Person called..." << count << std::endl;
    --count;
}

///class Student
Student::Student(int age, int height, std::string name, std::string surname, int course)
:Person(age, height, name, surname)
{
    ++count;
    std::cout << "Constructor called for Student: " << count << std::endl;
    setCourse(course);
}

Student::Student(int course)
:Person()
{
    ++count;
    std::cout << "Constructor called for Student: " << count << std::endl;
    setCourse(course);
}

Student::Student()
:Person()
{
    ++count;
    std::cout << "Constructor called for Student: " << count << std::endl;
    setCourse(course);
}

void Student::setCourse(int course) {
    this->course = ((course >= 0) && (course <= 10)) ? course : 0;
}

int Student::getCourse() const {
    return course;
}

void Student::walk() {
    std::cout << "Student is walking..." << std::endl;
}

void Student::write() {
    std::cout << "Student is writing..." << std::endl;
}

void Student::read() {
    std::cout << "Student is reading..." << std::endl;
}

Student::~Student() {
    std::cout << "Destructor called for Student..." << count << std::endl;
    --count;
}

///class Teacher
Teacher::Teacher(int age, int height, std::string name, std::string surname, std::string profession)
:Person(age, height, name, surname)
{
    ++count;
    std::cout << "Constructor called for Teacher: " << count << std::endl;
    setProfession(profession);
}

Teacher::Teacher(std::string profession )
:Person()
{
    ++count;
    std::cout << "Constructor called for Teacher: " << count << std::endl;
    setProfession(profession);
}

Teacher::Teacher()
:Person()
{
    ++count;
    std::cout << "Constructor called for Teacher: " << count << std::endl;
    setProfession(profession);
}

void Teacher::setProfession(std::string profession) {
    if (profession.length() > 2 && profession.length() < 30) {
        this->profession = profession;
    }
}

std::string Teacher::getProfession() const {
    return profession;
}

void Teacher::walk() {
    std::cout << "Teacher is walking..." << std::endl;
}

void Teacher::write() {
    std::cout << "Teacher is writing..." << std::endl;
}

void Teacher::read() {
    std::cout << "Teacher is reading..." << std::endl;
}

Teacher::~Teacher() {
    std::cout << "Called destructor for Teacher: " << count << std::endl;
    count--;
}

///class Assistent
Assistent::Assistent(int age, int height, std::string name, 
                    std::string surname, int course, std::string profession)
                    :Student(age, height, name, surname, course) {
    ++count;
    std::cout << "Constructor called for Assistent: " << count << std::endl;
    setProfession(profession);
}

Assistent::Assistent(int age, int height, std::string name,
                    std::string surname, std::string profession, int course)
                    :Teacher(age, height, name, surname, profession) {
    ++count;
    std::cout << "Constructor called for Assistent: " << count << std::endl;
    setCourse(course);
}
    
Assistent::Assistent(std::string profession, int course)
:Student() 
{
    ++count;
    std::cout << "Constructor called for Assistent: " << count << std::endl;
    setProfession(profession);
}

Assistent::Assistent()
:Student()
{
    ++count;
    std::cout << "Constructor called for Assistent: " << count << std::endl;
    setProfession("C++ Developer");
}

void Assistent::read() {
    std::cout << "Assistent is reading..." << std::endl;
}

Assistent::~Assistent() {
    std::cout << "Called destructor for Assistent: " << count << std::endl;
    --count;
}