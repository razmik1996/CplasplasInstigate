#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <cstdlib>
#include <iostream>
#include "utils.hpp"

/**
@file dynArray.hpp
@author Razmik Martirosyan
@brief class Dyn_array
*/

template <class T>
class Dyn_array {
    ///friend functions
    template<class S>
    friend std::ostream& operator<<(std::ostream &out, const Dyn_array<S> &object);
    template<class S>
    friend std::istream& operator>>(std::istream &in, Dyn_array<S> &object);
private: ///private members
    T* m_ptr;
    size_t m_size;
    size_t m_capacity;
private: ///private methods
    size_t& new_capacity(const size_t capacity);
    size_t copy();
    size_t& new_capacity_insert(const size_t index, const T& value);
    bool check_capacity();
    size_t& copy_for_insert(T* ptr, const size_t index);
public: ///constructors and destructor
    Dyn_array();
    Dyn_array(const size_t capacity, const T def_value);
    Dyn_array(const size_t SIZE, const size_t capacity, const T def_value);
    Dyn_array(const T* array, const size_t SIZE);
    Dyn_array(const T* array, size_t from, const size_t to);
    Dyn_array(const Dyn_array &other);
    ~Dyn_array();
public: ///public methods
    size_t capacity() const;
    size_t size() const;
    bool is_empty() const;
    bool shrnk_to_fit();
    size_t reserve(const size_t new_capacity);
    bool clear();
    size_t resize(const size_t count, const T& value);
    size_t resize(const size_t count);
    bool push_back(const T& value);
    bool push_back(T&& val);
    bool pop_back();
    T* insert(size_t index, const T& value);
public: ///operator overloading
    T& operator=(Dyn_array &other);
    bool operator==(Dyn_array &other);
    bool operator!=(Dyn_array &other);
    T& operator[](size_t index) const;
};

///private methods
template <class T>
size_t& Dyn_array<T>::new_capacity(const size_t capacity) {
    float coeficent = ((1 + 2.23) / 2);
    while (m_capacity <= capacity) {
        m_capacity = (int)(m_capacity * coeficent);
    }
}

template <class T>
bool Dyn_array<T>::check_capacity() {
    if (m_capacity == m_size) {
        return false;
    } else {
        return true;
    }
}

template <class T>
size_t Dyn_array<T>::copy() {
    T* tmp = m_ptr;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_ptr[i] = tmp[i];
    }
    delete[] tmp;
    return m_size;
}

template <class T>
size_t& Dyn_array<T>::copy_for_insert(T* ptr, const size_t index) {
    for (int i = 0; i < m_size; ++i) {
        if (i < index) {
            m_ptr[i] = ptr[i];
        } else {
            m_ptr[i+1] = ptr[i];
        }
    }
}
    
template <class T>
size_t& Dyn_array<T>::new_capacity_insert(const size_t index, const T& value) {
    float coeficent = ((1 + 2.23) / 2);
    m_capacity = (int)(m_capacity * coeficent);
    T* tmp = m_ptr;
    m_ptr = new T[m_capacity];
    copy_for_insert(tmp, index);
    m_ptr[index] = value;
    ++m_size;
    delete[] tmp;
}

///constructors and destructors
template <class T>
Dyn_array<T>::Dyn_array(){
    m_ptr = nullptr;
    m_size = 0;
    m_capacity = 1;
}

template <class T>
Dyn_array<T>::Dyn_array(const size_t SIZE, const T def_value) {
    m_capacity = SIZE + 1;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < SIZE; ++i) {
        m_ptr[i] = def_value;
    }
    m_size = SIZE;
}

template <class T>
Dyn_array<T>::Dyn_array(const size_t SIZE, const size_t capacity, const T def_value) {
    if (capacity <= SIZE) {
        m_capacity = SIZE + 1;
    } else {
        m_capacity = capacity;
    }
    m_ptr = new T[m_capacity];
    for (int i = 0; i < SIZE; ++i) {
        m_ptr[i] = def_value;
    }
    m_size = SIZE;
}

template <class T>
Dyn_array<T>::Dyn_array(const T* array, const size_t SIZE) {
    m_capacity = SIZE + 1;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < SIZE; ++i) {
        m_ptr[i] = array[i];
    }
}

template <class T>
Dyn_array<T>::Dyn_array(const T* array, size_t from, const size_t to) {
    size_t size = to - from;
    m_capacity = size + 1;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < size; ++i) {
        m_ptr[i] = array[from++];
    }
}

template <class T>
Dyn_array<T>::Dyn_array(const Dyn_array &other) {
    m_capacity = other.capacity();
    m_ptr = new T[m_capacity];
    m_size = other.size();
}

template <class T>
Dyn_array<T>::~Dyn_array() {
    delete[] m_ptr;
}

///public methods
template <class T>
size_t Dyn_array<T>::capacity() const {
    return m_capacity;
}

template <class T>
size_t Dyn_array<T>::size() const {
    return m_size;
}

template <class T>
bool Dyn_array<T>::is_empty() const {
    return (0 == m_size);
}

template <class T>
bool Dyn_array<T>::shrnk_to_fit() {
    if (!(check_capacity())) {
        return true;
    }
    if (m_size < m_capacity) {
        T* ptr = nullptr;
        ptr = m_ptr + m_size;
        delete[] ptr;
        m_capacity = m_size;
        return true;
    }
    return false;
}

template <class T>
size_t Dyn_array<T>::reserve(const size_t capacity) {
    if (m_capacity >= capacity) {
        return m_capacity;
    } else {
        new_capacity(capacity);
        copy();
        return m_capacity;
    }
}

template <class T>
bool Dyn_array<T>::clear() {
    delete[] m_ptr;
    m_ptr = new T[m_capacity];
    m_size = 0;
    return true;
}

template <class T>
bool Dyn_array<T>::push_back(const T& value) {
    if (!(check_capacity())) {
        new_capacity(m_capacity);
        copy();
    }
    m_ptr[m_size] = value;
    ++m_size;
    return true;
}

template <class T>
bool Dyn_array<T>::push_back(T&& val) {

}

template <class T>
bool Dyn_array<T>::pop_back() {
    m_ptr[m_size - 1] = NULL;
    --m_size;
    return true;
}

template <class T>
T* Dyn_array<T>::insert(size_t index, const T& value) {
    if (!(check_capacity())) {
        new_capacity_insert(index, &value);
    } else if(index == m_size) {
        push_back(value);
    } else {
        for (int i = m_size - 1; i > index; --i) {
            m_ptr[i + 1] = m_ptr[i];
        }
        m_ptr[index] = value;
        ++m_size;
    }
    return (m_ptr + index);
}

///friend functions
template <class T>
std::ostream& operator<<(std::ostream &out, const Dyn_array<T> &object) {
    for (int i = 0; i < object.size(); ++i) {
        out << object[i] << " ";
    }
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, Dyn_array<T> &object) {
    for (int i = 0; i < object.size(); ++i) {
        in >> object[i];
    }
    return in;
}

///operator overloading
template<class T>
T& Dyn_array<T>::operator=(Dyn_array &other) {
    m_capacity = other.capacity();
    m_ptr = new T[m_capacity];
    m_size = other.size();
    return this;
}

template<class T>
bool Dyn_array<T>::operator==(Dyn_array &other) {
    if(m_size != other.size()) {
        return false;
    } else if(m_capacity != other.capacity()) {
        return false;
    } else {
        for (int i = 0; i < m_size; i++) {
            if (m_ptr[i] != other[i]) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
bool Dyn_array<T>::operator!=(Dyn_array &other) {
    return !(*this == other);
}

template<class T>
T& Dyn_array<T>::operator[](size_t index) const {
    return m_ptr[index];
}

#endif ///DYNARRAY_HPP