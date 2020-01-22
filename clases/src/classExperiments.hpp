#include <string>

class Person {
    int age;
    int height;
    std::string name;
    std::string surname;
public:
    Person(int age = 10, int height = 180, std::string name = "Poxos", std::string surname = "Poxosyan");
    Person(int age, int height, std::string name, std::string surname);
    void setAge(int age);
    int getAge() const;
    void setHeight(int height);
    int getHeight() const;
    void setName(std::string name);
    std::string getName() const;
    void setSurname(std::string surname);
    std::string getSurname() const;
    void walk();
};

class Student: public Person {
    int course;
public:
    Student(int age, int height, std::string name, std::string surname, int course);
    Student(int course = 1);
    void setCourse(int course);
    int getCourse() const;
    void walk();
};

class Teacher: public Person {
    std::string profession;
public:
    Teacher(int age, int height, std::string name, std::string surname, std::string profession);
    Teacher(std::string profession = "C++ Enginner");
    void setProfession(std::string profession);
    int getProfession() const;
    void walk();
};

class Assistent: public Teacher, public Student {
public:
    Assistent(int age, int height, std::string name, std::string surname, int course, std::string profession);
    Assistent(int age, int height, std::string name, std::string surname, std::string profession, int course);
    Assistent(std::string profession = "C++ Engineer", int course = 1);
};