#include "classExperiments.hpp"

///class Person
Person::Person(int age = 10, int height = 180, std::string name = "Poxos", std::string surname = "Poxosyan") {

}

Person::Person(int age, int height, std::string name, std::string surname) {

}

void Person::setAge(int age) {

}

int Person::getAge() const {

}

void Person::setHeight(int height) {

}

int Person::getHeight() const {

}

void Person::setName(std::string name) {

}

std::string Person::getName() const {

}

void Person::setSurname(std::string surname) {

}

std::string Person::getSurname() const {

}
    
void Person::walk() {

}

///class Student
Student::Student(int age, int height, std::string name, std::string surname, int course) {

}

Student::Student(int course = 1) {

}

void Student::setCourse(int course) {

}

int Student::getCourse() const {

}

void Student::walk() {

}

///class Teacher
Teacher::Teacher(int age, int height, std::string name, std::string surname, std::string profession) {

}

Teacher::Teacher(std::string profession = "C++ Enginner"){

}

void Teacher::setProfession(std::string profession) {

}

int Teacher::getProfession() const {

}

void Teacher::walk() {

}

///class Assistent
Assistent::Assistent(int age, int height, std::string name, std::string surname, int course, std::string profession) {

}

Assistent::Assistent(int age, int height, std::string name, std::string surname, std::string profession, int course) {
    
}
    
Assistent::Assistent(std::string profession = "C++ Engineer", int course = 1) {

}