/******************************************************************************
 * @file Mystring.cpp
 * @brief Implementation of the Mystring class.
 ******************************************************************************/

#include <cstring>
#include <iostream>
#include "Mystring.hpp"

// --- Constructors ---

// Default constructor
Mystring::Mystring() : str{nullptr}, length{0} {
    str = new char[1];
    *str = '\0'; 
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr}, length{0} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        length = std::strlen(s);
        str = new char[length + 1]; 
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr}, length{0} {
    length = source.length;
    str = new char[length + 1];
    std::strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source) noexcept : str{source.str}, length{source.length} {
    std::cout << "Calling Move constructor" << std::endl;
    source.str = nullptr;
    source.length = 0;
}

// --- Destructor ---
Mystring::~Mystring() {
    delete[] str;
}

// --- Operators ---

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Calling Copy assignment operator" << std::endl;
    
    if (this == &rhs) {
        return *this;
    }
    
    delete[] this->str;
    
    length = rhs.length;
    str = new char[length + 1];
    std::strcpy(str, rhs.str);
    
    return *this;
}

// Move assignment operator
Mystring &Mystring::operator=(Mystring &&rhs) noexcept {
    std::cout << "Calling Move assignment operator" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete[] this->str;

    length = rhs.length;
    str = rhs.str;
    
    rhs.str = nullptr;
    rhs.length = 0;
    
    return *this;
}

// --- Math & Logical Operators ---

// Equality operator (s1 == s2)
bool Mystring::operator==(const Mystring &rhs) const {
    // std::strcmp returns 0 if both strings are exactly the same
    return (std::strcmp(str, rhs.str) == 0);
}

// Unary minus operator (-s1)
Mystring Mystring::operator-() const {
    // 1. Allocate a temporary buffer for the new lowercase string
    char *buff = new char[length + 1];
    std::strcpy(buff, str);

    // 2. Loop through using the cached length (O(N) performance)
    for (int i = 0; i < length; i++) {
        buff[i] = std::tolower(buff[i]);
    }

    // 3. Create a new object using the overloaded constructor
    Mystring temp{buff};
    
    // 4. Prevent memory leak
    delete[] buff;

    return temp;
}

// Binary plus operator (s1 + s2)
Mystring Mystring::operator+(const Mystring &rhs) const {
    // 1. Calculate the exact required size
    int new_length = length + rhs.length;
    
    // 2. Allocate memory (+1 for the null terminator)
    char *buff = new char[new_length + 1];

    // 3. Copy the left side (this->str) and concatenate the right side (rhs.str)
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    // 4. Create the new object
    Mystring temp{buff};
    
    // 5. Clean up the heap
    delete[] buff;

    return temp;
}

// --- Methods & Getters ---

void Mystring::display() const {
    std::cout << str << " : " << length << std::endl;
}

int Mystring::get_length() const {
    return length;
}

const char* Mystring::get_str() const {
    return str;
}