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

/**
@class Dyn_array
*/
template <class T>
class Dyn_array {
public:
    class iterator {
    public:
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::random_access_iterator_tag iterator_category;
        typedef int difference_type;
        
        iterator();
        iterator(pointer ptr);
        iterator(const iterator& other);
        ~iterator();
        
        iterator& operator=(const iterator& other);
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
        bool operator<(const iterator& other) const;
        bool operator>(const iterator& other) const;
        bool operator<=(const iterator& other) const;
        bool operator>=(const iterator& other) const;
        iterator& operator++(); //prefix
        iterator operator++(int);  //postfix
        iterator& operator--(); //prefix
        iterator operator--(int);  //postfix
        iterator& operator+=(difference_type);
        iterator operator+(difference_type) const;
        iterator& operator-=(difference_type);
        iterator operator-(difference_type) const;
        difference_type operator-(iterator&) const;

        reference operator*() const;
        pointer operator->() const;
        reference operator[](difference_type) const;
    private:
        pointer m_ptr;
    };
    ///friend functions
    /**
    @brief operator<< overwriting << for cout function print all elements of dynamic array
    @param ostream &out - reference to ostream stream
    @param Dyn_array<T> &object - reference to print dynamic array
    */
    template<class S>
    friend std::ostream& operator<<(std::ostream &out, const Dyn_array<S> &object);
    /**
    @brief operator>> overwriting >> for cin function to insert all elements of dynamic array
    @param ostream &out - reference to istream stream
    @param Dyn_array<T> &object - reference to insert dynamic array
    */
    template<class S>
    friend std::istream& operator>>(std::istream &in, Dyn_array<S> &object);
private: ///private members
    T* m_ptr; /*!< Pointer to first element of dynamic array */
    size_t m_size; /*!< size of declared values in Dynamic array */
    size_t m_capacity; /*!< size of allocated memory */
private: ///private methods
    /**
    @brief When capacity = size capacity = capacity * 1.62
    @param capacity - if you want allocate custom capacity give new capacity 
                        or give m_capacity if you want just multiply
    */
    size_t new_capacity(const size_t capacity);
    /**
    @brief just reallocate and copy old values
    */
    size_t reallocate_and_copy();
    /**
    @brief new capacity for insert function with adding value to index pos
    @param size_t index - position for adding value
    @param T& value - reference to value
    */
    size_t new_capacity_insert(const size_t index, const T& value);
    /**
    @brief check equal or not size == capacity
    */
    bool check_capacity();
    /**
    @brief copy for insert function
    @param T* ptr - pointer to old array to value
    @param size_t index - position for adding value
    */
    iterator& copy_for_insert(T* ptr, const size_t index);
public: ///constructors and destructor
    /** TO DO
    template<typename iter, 
         std::enable_if_t<std::is_base_of_v<typename std::iterator_traits<iter>::iterator_category, 
                                            std::random_access_iterator_tag>, bool> = true>
    Dyn_array(iter begin, iter end);
    */
    template <typename iterators>
    Dyn_array(iterators begin, iterators end);
    /**
    @brief default constructor
    */
    Dyn_array();
    /**
    @brief constructor for dynamic array with custom capacity and with default value
    @param size_t capacity - size of array capacity = size + 1
    @param T def_value - default value for all elements
    */
    Dyn_array(const size_t capacity, const T def_value);
    /**
    @brief constructor for dynamic array with custom capacity, size and with default value
    @brief Set of allowed values SIZE < capacity and both > 0
    @param size_t SIZE - size of array
    @param size_t capacity - capacity of array
    @param T def_value - default value for all elements
    */
    Dyn_array(const size_t SIZE, const size_t capacity, const T def_value);
    /**
    @brief constructor for dynamic array with values from other array
    @param T* array - other array
    @param size_t SIZE - array SIZE
    */
    Dyn_array(const T* array, const size_t SIZE);
    /**
    @brief constructor for dynamic array with values from other array
    @param size_t from - from element
    @param size_t to - to element
    */
    Dyn_array(const T* array, size_t from, const size_t to);
    /**
    @brief Copy constructor
    @param Dyn_array &other - other container for copy
    */
    Dyn_array(const Dyn_array &other);
    /**
    @brief Destructor
    */
    ~Dyn_array();
public: ///public methods
    /**
    @brief return capacity
    */
    size_t capacity() const;
    /**
    @brief return iterator to first element of dynamic array
    */
    iterator begin();
    /**
    @brief return const iterator to first element of dynamic array
    */
    const iterator cbegin() const;
    /**
    @brief return iterator to end + 1 element of dynamic array
    */
    iterator end();
    /**
    @brief return const iterator to end + 1 element of dynamic array
    */
    const iterator cend() const;
    /**
    @brief return reverse iterator to first(end) element of dynamic array
    */
    iterator rbegin();
    /**
    @brief return reverse iterator to end + 1(fist - 1) element of dynamic array
    */
    iterator rend();
    /**
    @brief return size
    */
    size_t size() const;
    /**
    @brief is empty array or not
    */
    bool is_empty() const;
    /**
    @brief capacity = size
    */
    bool shrnk_to_fit();
    /**
    @brief reserve capacity
    @param size_t new_capacity - new capacity size for allocating
    */
    size_t reserve(const size_t new_capacity);
    /**
    @brief clear all container
    */
    bool clear();
    size_t resize(const size_t count, const T& value);
    size_t resize(const size_t count);
    /**
    @brief push value after end element
    @param T& value - value for pushing
    */
    bool push_back(const T& value);
//    bool push_back(T&& val);
    /**
    @brief pop from end
    */
    bool pop_back();
    /**
    @brief insert value before index element
    @param index - index of value
    @param value - value for pushing
    */
    T* insert(size_t index, const T& value);
public: ///operator overloading
    T& operator=(Dyn_array &other);
    bool operator==(Dyn_array &other);
    bool operator!=(Dyn_array &other);
    T& operator[](size_t index) const;
};
///iterator member functions for class member functions search private methods
template <class T>
Dyn_array<T>::iterator::iterator() {
    m_ptr = NULL;
}

template <class T>
Dyn_array<T>::iterator::iterator(T* ptr) {
    m_ptr = ptr;
}

template <class T>
Dyn_array<T>::iterator::iterator(const Dyn_array<T>::iterator& other) {
    m_ptr = other.m_ptr;
}

template <class T>
Dyn_array<T>::iterator::~iterator() {

}
 
template <class T>
typename Dyn_array<T>::iterator& Dyn_array<T>::iterator::operator=(const iterator& other) {
    if (m_ptr != other.m_ptr) {
        m_ptr = other.m_ptr;
    }
    return *this;
}

template <class T>
bool Dyn_array<T>::iterator::operator==(const iterator& other) const {
    if (m_ptr == other.m_ptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Dyn_array<T>::iterator::operator!=(const iterator& other) const {
    if (m_ptr != other.m_ptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Dyn_array<T>::iterator::operator<(const iterator& other) const {
    if (m_ptr < other.m_ptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Dyn_array<T>::iterator::operator>(const iterator& other) const {
    if (m_ptr > other.m_ptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Dyn_array<T>::iterator::operator<=(const iterator& other) const {
    if (m_ptr <= other.m_ptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Dyn_array<T>::iterator::operator>=(const iterator& other) const {
    if (m_ptr >= other.m_ptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
typename Dyn_array<T>::iterator& Dyn_array<T>::iterator::operator++() {
    m_ptr++;
    return *this;
} //prefix

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::iterator::operator++(int){
    T* tmp = m_ptr;
    m_ptr++;
    return iterator(tmp);
} //postfix

template <class T>
typename Dyn_array<T>::iterator& Dyn_array<T>::iterator::operator--() {
    m_ptr--;
    return *this;
} //prefix

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::iterator::operator--(int) {
    T* tmp = m_ptr;
    m_ptr--;
    return iterator(tmp);
}  //postfix

template <class T>
typename Dyn_array<T>::iterator& Dyn_array<T>::iterator::operator+=(int value) {
    m_ptr = m_ptr + value;
    return *this;
}

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::iterator::operator+(int value) const {
    return *(this->m_ptr + value);
}

template <class T>
typename Dyn_array<T>::iterator& Dyn_array<T>::iterator::operator-=(int value) {
    m_ptr = m_ptr - value;
    return *this;
}

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::iterator::operator-(int value) const {
    return *(this->m_ptr - value);
}

template <class T>
int Dyn_array<T>::iterator::operator-(iterator &other) const {
    return (m_ptr - other.m_ptr);
}

template <class T>
T& Dyn_array<T>::iterator::operator*() const {
    return *m_ptr;
}

template <class T>
T* Dyn_array<T>::iterator::operator->() const {
    return m_ptr;
}

template <class T>
T& Dyn_array<T>::iterator::operator[](int value) const {
    return *(m_ptr + value);
}

///private methods
template <class T>
size_t Dyn_array<T>::new_capacity(const size_t capacity) {
    if (m_capacity < 2) {
        m_capacity = 2;
    } else {
        float coeficent = 1.62;
        while (m_capacity <= capacity) {
            m_capacity = (int)(m_capacity * coeficent);
        }
    }
    return m_capacity;
}

template <class T>
bool Dyn_array<T>::check_capacity() {
    if (m_capacity == m_size) {
        return true;
    } else {
        return false;
    }
}

template <class T>
size_t Dyn_array<T>::reallocate_and_copy() {
    T* tmp = m_ptr;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_ptr[i] = tmp[i];
    }
    delete[] tmp;
    return m_size;
}

template <class T>
typename Dyn_array<T>::iterator& Dyn_array<T>::copy_for_insert(T* ptr, const size_t index) {
    for (int i = 0; i < m_size; ++i) {
        if (i < index) {
            m_ptr[i] = ptr[i];
        } else {
            m_ptr[i+1] = ptr[i];
        }
    }
    return iterator(index);
}
    
template <class T>
size_t Dyn_array<T>::new_capacity_insert(const size_t index, const T& value) {
    new_capacity(m_capacity);
    T* tmp = m_ptr;
    m_ptr = new T[m_capacity];
    copy_for_insert(tmp, index);
    m_ptr[index] = value;
    ++m_size;
    delete[] tmp;
    return m_capacity;
}

///constructors and destructors
template <class T>
Dyn_array<T>::Dyn_array(){
    m_ptr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<class T>
template<typename iterators>
Dyn_array<T>::Dyn_array(iterators begin, iterators end) {
    m_capacity = 2;
    m_size = 0;
    m_ptr = new T[m_capacity];
    int i = 0;
    for(auto it = begin; it != end; ++it) {
        if(check_capacity()) {
            new_capacity(m_capacity);
            reallocate_and_copy();
        }
        m_ptr[i] = *it;
        i++;
        m_size++;
    }
}

template<class T>
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
    m_size = SIZE;
    m_capacity = SIZE + 1;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < SIZE; ++i) {
        m_ptr[i] = array[i];
    }
}

template <class T>
Dyn_array<T>::Dyn_array(const T* array, size_t from, const size_t to) {
    size_t size = to - from;
    m_size = size;
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
    for (int i = 0; i < m_size; ++i) {
        m_ptr[i] = other[i];
    }
}

template <class T>
Dyn_array<T>::~Dyn_array() {
    delete[] m_ptr;
}

///public methods
template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::begin() {
    return iterator(m_ptr);
}

template <class T>
const typename Dyn_array<T>::iterator Dyn_array<T>::cbegin() const {
    return iterator(m_ptr);
}

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::end() {
    return iterator(m_ptr + m_size);
}

template <class T>
const typename Dyn_array<T>::iterator Dyn_array<T>::cend() const {
    return iterator(m_ptr + m_size);
}

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::rbegin() {
    return iterator(m_ptr + m_size - 1);
}

template <class T>
typename Dyn_array<T>::iterator Dyn_array<T>::rend() {
    return iterator(m_ptr - 1);
}

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
    if (check_capacity()) {
        return true;
    }
    if (m_size < m_capacity) {
        m_capacity = m_size;
        reallocate_and_copy();
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
        reallocate_and_copy();
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
    if (check_capacity()) {
        new_capacity(m_capacity);
        reallocate_and_copy();
    }
    m_ptr[m_size] = value;
    ++m_size;
    return true;
}

/*
template <class T>
bool Dyn_array<T>::push_back(T&& val) {

}
*/

template <class T>
bool Dyn_array<T>::pop_back() {
    --m_size;
    return true;
}

template <class T>
T* Dyn_array<T>::insert(size_t index, const T& value) {
    if (check_capacity()) {
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
    for (int i = 0; i < m_size; ++i) {
        m_ptr[i] = other[i];
    }
    return *this;
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
