#include <string>

/**
@file classExperiments.hpp
@brief Some experiments with clases, diamond problem and etc.
@author Razmik Martirosyan
*/

/**
@class Person
*/
class Person {
    static int count;
    int age;
    int height;
    std::string name;
    std::string surname;
public:
    /**
    @brief Class constructor
    @param age - age of person
    @param height - height of person
    @param name - person name
    @param surname - person surname
    */
    Person(int age, int height, std::string name, std::string surname);
    /**
    @brief Seter for age
    @param age - age of person
    */
    void setAge(int age);
    /**
    @brief Geter for age
    */
    int getAge() const;
    /**
    @brief Seter for height
    @param height - height of person
    */
    void setHeight(int height);
    /**
    @brief Geter for height
    */
    int getHeight() const;
    /**
    @brief Seter for name
    @param name - person name
    */
    void setName(std::string name);
    /**
    @brief Geter for name
    */
    std::string getName() const;
    /**
    @brief Seter for surname
    @param surname - person surname
    */
    void setSurname(std::string surname);
    /**
    @brief Geter for surname
    */
    std::string getSurname() const;
    /**
    @brief Function for printing person is walking non-virtual
    */
    void walk();
    /**
    @brief Function for printing person is reading virtual
    */
    virtual void read();
    /**
    @brief Function for printing person is writing clean virtual
    */
    virtual void write() = 0;
    /**
    @brief virtual destructor for person
    */
    virtual ~Person();
};

/**
@class Student
*/
class Student: public Person {
    int course;
    static int count;
public:
    /**
    @brief Class constructor
    @param age - age of person
    @param height - height of person
    @param name - person name
    @param surname - person surname
    @param course - course of student
    */
    Student(int age, int height, std::string name, std::string surname, int course);
    /**
    @brief Class constructor 2
    @param course - course of student
    */
    Student(int course);
    /**
    @brief Class default constructor
    */
    Student();
    /**
    @brief Seter for course
    @param course - student course
    */
    void setCourse(int course);
    /**
    @brief geter for course
    */
    int getCourse() const;
    /**
    @brief Function for printing student is reading virtual
    */
    virtual void read();
    /**
    @brief Function for printing student is walking non-virtual
    */
    void walk();
    /**
    @brief Function for printing student is writing virtual for this
    */
    void write();
    /**
    @brief virtual destructor for student
    */
    virtual ~Student();
};

/**
@class Teacher 
*/
class Teacher: public Person {
    std::string profession;
    static int count;
public:
    /**
    @brief Class constructor
    @param age - age of person
    @param height - height of person
    @param name - person name
    @param surname - person surname
    @param profession - profession of teacher
    */
    Teacher(int age, int height, std::string name, std::string surname, std::string profession);
    /**
    @brief Class constructor 2
    @param profession - profession of teacher
    */
    Teacher(std::string profession);
    /**
    @brief Class default constructor
    */
    Teacher();
    /**
    @brief Setter for teacher profession
    @param profession - profession of teacher
    */
    void setProfession(std::string profession);
    /**
    @brief Getter for teacher profession
    */
    std::string getProfession() const;
    /**
    @brief Function for printing teacher is reading virtual
    */
    virtual void read();
    /**
    @brief Function for printing teacher is walking non-virtual
    */
    void walk();
    /**
    @brief Function for printing teacher is rwriting virtual for this
    */
    void write();
    /**
    @brief virtual destructor for teacher
    */
    virtual ~Teacher();
};

/**
@class Assistent
*/
class Assistent: public Teacher, public Student {
private:
    static int count;
public:
    /**
    @brief Class constructor
    @param age - age of person
    @param height - height of person
    @param name - person name
    @param surname - person surname
    @param course - course of assistent
    @param profession - profession of assistent
    */
    Assistent(int age, int height, std::string name, std::string surname, int course, std::string profession);
    /**
    @brief Class constructor
    @param age - age of person
    @param height - height of person
    @param name - person name
    @param surname - person surname
    @param profession - profession of assistent
    @param course - course of assistent
    */
    Assistent(int age, int height, std::string name, std::string surname, std::string profession, int course);
    /**
    @brief Class constructor
    @param profession - profession of assistent
    @param course - course of assistent
    */
    Assistent(std::string profession, int course);
    /**
    @brief Class default constructor 
    */
    Assistent();
    /**
    @brief Function for printing assistent is reading virtual
    */
    virtual void read();
    /**
    @brief virtual destructor for assistent
    */
    virtual ~Assistent();
};