#include "classExperiments.hpp"
#include <iostream>

//static value initializing
int Person::sm_count = 0;
int Student::sm_count = 0;
int Teacher::sm_count = 0;
int Assistent::sm_count = 0;

int defValueAge = 15;
int defValueHeight = 180;
std::string defValueName = "Poxos";
std::string defValueSurname = "Poxosyan";
std::string defValueProfession = "C++ Enigineer";
int defValueCourse = 0;

///class Person
Person::Person(const int age = defValueAge, const int height = defValueHeight,
              const std::string name = defValueName, const std::string surname = defValueSurname) {
    ++sm_count;
    std::cout << "Constructor called for Person: " << sm_count << std::endl;
    setAge(age);
    setHeight(height);
    setName(name);
    setSurname(surname);
}

void Person::setAge(const int age) {
    int minimumAge = 0;
    int maximumAge = 150;
    m_age = ((age > minimumAge) && (age < maximumAge)) ? age : defValueAge;
}

int Person::getAge() const {
    return m_age;
}

void Person::setHeight(const int height) {
    int minimumHeight = 20;
    int maximumHeight = 250;
    m_height = ((height > minimumHeight) && (height < maximumHeight)) ? height : defValueHeight;
}

int Person::getHeight() const {
    return m_height;
}

void Person::setName(const std::string name) {
    int nameLenght = name.length();
    int minNameLenght = 2;
    int maxNameLenght = 30;
    if ((nameLenght > minNameLenght) && (nameLenght < maxNameLenght)) {
        m_name = name;
    } else {
        m_name = defValueName;
    }
}

std::string Person::getName() const {
    return m_name;
}

void Person::setSurname(const std::string surname) {
    int surnameLenght = surname.length();
    int minSurnameLenght = 2;
    int maxSurnameLenght = 30;
    if (surnameLenght > minSurnameLenght && surnameLenght < maxSurnameLenght) {
        m_surname = surname;
    } else {
        m_surname = defValueSurname;
    }
}

std::string Person::getSurname() const {
    return m_surname;
}
    
void Person::walk() const {
    std::cout << "Person is walking..." << std::endl;
}

void Person::read() const {
    std::cout << "Person is reading..." << std::endl;
}

Person::~Person() {
    std::cout << "Destructor for Person called..." << sm_count << std::endl;
    --sm_count;
}

///class Student
Student::Student(const int age, const int height, const std::string name,
                const std::string surname, const int course)
:Person(age, height, name, surname)
{
    ++sm_count;
    std::cout << "Constructor called for Student: " << sm_count << std::endl;
    setCourse(course);
}

Student::Student(const int course)
:Person()
{
    ++sm_count;
    std::cout << "Constructor called for Student: " << sm_count << std::endl;
    setCourse(course);
}

Student::Student()
:Person()
{
    ++sm_count;
    std::cout << "Constructor called for Student: " << sm_count << std::endl;
    setCourse(0);
}

void Student::setCourse(const int course) {
    m_course = ((course >= 0) && (course <= 10)) ? course : 0;
}

int Student::getCourse() const {
    return m_course;
}

void Student::walk() const {
    std::cout << "Student is walking..." << std::endl;
}

void Student::write() const {
    std::cout << "Student is writing..." << std::endl;
}

void Student::read() const {
    std::cout << "Student is reading..." << std::endl;
}

Student::~Student() {
    std::cout << "Destructor called for Student..." << sm_count << std::endl;
    --sm_count;
}

///class Teacher
Teacher::Teacher(const int age, const int height, const std::string name,
                const std::string surname, const std::string profession)
:Person(age, height, name, surname)
{
    ++sm_count;
    std::cout << "Constructor called for Teacher: " << sm_count << std::endl;
    setProfession(profession);
}

Teacher::Teacher(const std::string profession)
:Person()
{
    ++sm_count;
    std::cout << "Constructor called for Teacher: " << sm_count << std::endl;
    setProfession(profession);
}

Teacher::Teacher()
:Person()
{
    ++sm_count;
    std::cout << "Constructor called for Teacher: " << sm_count << std::endl;
    setProfession("C++ Engineer");
}

void Teacher::setProfession(const std::string profession) {
    int professionLenght = profession.length();
    int minProfessionLenght = 2;
    int maxProfessionLenght = 30;
    if (professionLenght > minProfessionLenght && professionLenght < maxProfessionLenght) {
        m_profession = profession;
    } else {
        m_profession = defValueSurname;
    }
}

std::string Teacher::getProfession() const {
    return m_profession;
}

void Teacher::walk() const {
    std::cout << "Teacher is walking..." << std::endl;
}

void Teacher::write() const {
    std::cout << "Teacher is writing..." << std::endl;
}

void Teacher::read() const {
    std::cout << "Teacher is reading..." << std::endl;
}

Teacher::~Teacher() {
    std::cout << "Called destructor for Teacher: " << sm_count << std::endl;
    --sm_count;
}

///class Assistent
Assistent::Assistent(const int age, const int height, const std::string name, 
                    const std::string surname, const int course, const std::string profession)
                    :Student(age, height, name, surname, course) {
    ++sm_count;
    std::cout << "Constructor called for Assistent: " << sm_count << std::endl;
    setProfession(profession);
}

Assistent::Assistent(const int age, const int height, const std::string name,
                    const std::string surname, const std::string profession, const int course)
                    :Teacher(age, height, name, surname, profession) {
    ++sm_count;
    std::cout << "Constructor called for Assistent: " << sm_count << std::endl;
    setCourse(course);
}
    
Assistent::Assistent(const std::string profession, const int course)
:Student() 
{
    ++sm_count;
    std::cout << "Constructor called for Assistent: " << sm_count << std::endl;
    setProfession(profession);
}

Assistent::Assistent()
:Student()
{
    ++sm_count;
    std::cout << "Constructor called for Assistent: " << sm_count << std::endl;
    setProfession("C++ Developer");
}

void Assistent::read() const {
    std::cout << "Assistent is reading..." << std::endl;
}

Assistent::~Assistent() {
    std::cout << "Called destructor for Assistent: " << sm_count << std::endl;
    --sm_count;
}