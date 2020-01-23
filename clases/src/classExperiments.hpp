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
    static int sm_count;
    int m_age;
    int m_height;
    std::string m_name;
    std::string m_surname;
public:
    /**
    @brief Class constructor
    @param age - age of person (minimum age = 0, maximum 150 else default value is 15)
    @param height - height of person (minimum height = 20, maximum 250 else def val is 180)
    @param name - person name (minimum lenght is 2 max 30 else def value is Poghos)
    @param surname - person surname (minimum lenght is 2 max 30 else def val is Poghos)
    */
    Person(const int age, const int height,
            const std::string name, const std::string surname);
    /**
    @brief Seter for age
    @param age - age of person
    */
    void setAge(const int age);
    /**
    @brief Geter for age
    */
    int getAge() const;
    /**
    @brief Seter for height
    @param height - height of person
    */
    void setHeight(const int height);
    /**
    @brief Geter for height
    */
    int getHeight() const;
    /**
    @brief Seter for name
    @param name - person name
    */
    void setName(const std::string name);
    /**
    @brief Geter for name
    */
    std::string getName() const;
    /**
    @brief Seter for surname
    @param surname - person surname
    */
    void setSurname(const std::string surname);
    /**
    @brief Geter for surname
    */
    std::string getSurname() const;
    /**
    @brief Function for printing person is walking non-virtual
    */
    void walk() const;
    /**
    @brief Function for printing person is reading virtual
    */
    virtual void read() const;
    /**
    @brief Function for printing person is writing clean virtual
    */
    virtual void write() const = 0;
    /**
    @brief virtual destructor for person
    */
    virtual ~Person();
};

/**
@class Student
*/
class Student: public Person {
    int m_course;
    static int sm_count;
public:
    /**
    @brief Class constructor
    @param age - age of person (minimum age = 0, maximum 150 else default value is 15)
    @param height - height of person (minimum height = 20, maximum 250 else def val is 180)
    @param name - person name (minimum lenght is 2 max 30 else def value is Poghos)
    @param surname - person surname (minimum lenght is 2 max 30 else def val is Poghos)
    @param course - course of student (minimum course is 0 max 10 else def val is 0)
    */
    Student(const int age, const int height, const std::string name,
            const std::string surname, const int course);
    /**
    @brief Class constructor 2
    @param course - course of student
    */
    Student(const int course);
    /**
    @brief Class default constructor
    */
    Student();
    /**
    @brief Seter for course
    @param course - student course
    */
    void setCourse(const int course);
    /**
    @brief geter for course
    */
    int getCourse() const;
    /**
    @brief Function for printing student is reading virtual
    */
    virtual void read() const;
    /**
    @brief Function for printing student is walking non-virtual
    */
    void walk() const;
    /**
    @brief Function for printing student is writing virtual for this
    */
    void write() const;
    /**
    @brief virtual destructor for student
    */
    virtual ~Student();
};

/**
@class Teacher 
*/
class Teacher: public Person {
    std::string m_profession;
    static int sm_count;
public:
    /**
    @brief Class constructor
    @param age - age of person (minimum age = 0, maximum 150 else default value is 15)
    @param height - height of person (minimum height = 20, maximum 250 else def val is 180)
    @param name - person name (minimum lenght is 2 max 30 else def value is Poghos)
    @param surname - person surname (minimum lenght is 2 max 30 else def val is Poghos)
    @param profession - profession of teacher (minimum lenght is 2 max 30 else def val is C++ Engineer)
    */
    Teacher(const int age, const int height, const std::string name,
            const std::string surname, const std::string profession);
    /**
    @brief Class constructor 2
    @param profession - profession of teacher
    */
    Teacher(const std::string profession);
    /**
    @brief Class default constructor
    */
    Teacher();
    /**
    @brief Setter for teacher profession
    @param profession - profession of teacher
    */
    void setProfession(const std::string profession);
    /**
    @brief Getter for teacher profession
    */
    std::string getProfession() const;
    /**
    @brief Function for printing teacher is reading virtual
    */
    virtual void read() const;
    /**
    @brief Function for printing teacher is walking non-virtual
    */
    void walk() const;
    /**
    @brief Function for printing teacher is rwriting virtual for this
    */
    void write() const;
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
    static int sm_count;
public:
    /**
    @brief Class constructor
    @param age - age of person (minimum age = 0, maximum 150 else default value is 15)
    @param height - height of person (minimum height = 20, maximum 250 else def val is 180)
    @param name - person name (minimum lenght is 2 max 30 else def value is Poghos)
    @param surname - person surname (minimum lenght is 2 max 30 else def val is Poghos)
    @param course - course of student (minimum course is 0 max 10 else def val is 0)
    @param profession - profession of teacher (minimum lenght is 2 max 30 else def val is C++ Engineer)
    */
    Assistent(const int age, const int height, const std::string name,
                const std::string surname, const int course,
                const std::string profession);
    /**
    @brief Class constructor
    @param age - age of person
    @param height - height of person
    @param name - person name
    @param surname - person surname
    @param profession - profession of assistent
    @param course - course of assistent
    */
    Assistent(const int age, const int height, const std::string name,
                const std::string surname, const std::string profession,
                const int course);
    /**
    @brief Class constructor
    @param profession - profession of assistent
    @param course - course of assistent
    */
    Assistent(const std::string profession, const int course);
    /**
    @brief Class default constructor 
    */
    Assistent();
    /**
    @brief Function for printing assistent is reading virtual
    */
    virtual void read() const;
    /**
    @brief virtual destructor for assistent
    */
    virtual ~Assistent();
};