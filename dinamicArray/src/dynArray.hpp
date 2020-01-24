#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <cstdlib>
#include <iostream>

template <class T>
class Dyn_array {
private: ///private members
    T* m_ptr;
    size_t m_size;
    size_t m_capacity;
private: ///private methods
    int& new_capacity(const size_t SIZE);
public: ///constructors and destructor
    Dyn_array();
    explicit Dyn_array(const size_t SIZE);
    Dyn_array(const size_t SIZE, const T def_value);
    Dyn_array(const size_t SIZE, const size_t capacity);
    Dyn_array(const size_t SIZE, const size_t capacity, const T def_value);
    Dyn_array(const T* array, const size_t SIZE);
    Dyn_array(const T* array, const size_t from, const size_t to);
    Dyn_array(const Dyn_array &other);
    ~Dyn_array();
public: ///public methods
    size_t capacity() const;
    size_t size() const;
    bool is_empty() const;
    bool shrnk_to_fit();
    size_t reserve(const size_t new_capacity);
    bool clear();
    bool push_back(const &T value);
    bool pop_back();
///friend functions
friend std::ostream& operator<<(std::ostream out, const Dyn_array &object) const;
friend std::istream& operator>>(std::istream in, Dyn_array &object);
public: ///operator overloading
    T& operator=(Dyn_array &other);
    bool operator==(Dyn_array &other);
    bool operator!=(Dyn_array &other);
};

#endif ///DYNARRAY_HPP