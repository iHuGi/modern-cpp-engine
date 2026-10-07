/******************************************************************************
 * @file MystringGlobal.cpp
 * @brief Implementation of the MystringGlobal class, friend operators, and I/O.
 ******************************************************************************/

#include <cstring>
#include <iostream>
#include <cctype>
#include <string>
#include "MystringGlobal.hpp"

// --- Constructors ---

// Default constructor: Initializes an empty string with just a null terminator '\0'
MystringGlobal::MystringGlobal() : str{nullptr}, length{0} {
    str = new char[1];
    *str = '\0'; 
}

// Overloaded constructor: Allocates memory and copies the provided C-style string
MystringGlobal::MystringGlobal(const char *s) : str{nullptr}, length{0} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        length = std::strlen(s);
        str = new char[length + 1]; 
        std::strcpy(str, s);
    }
}

// Copy constructor: Performs a deep copy of the source object's memory
MystringGlobal::MystringGlobal(const MystringGlobal &source) : str{nullptr}, length{0} {
    length = source.length;
    str = new char[length + 1];
    std::strcpy(str, source.str);
}

// Move constructor: Steals the pointer from an R-value and nullifies the source to prevent deletion
MystringGlobal::MystringGlobal(MystringGlobal &&source) noexcept : str{source.str}, length{source.length} {
    source.str = nullptr;
    source.length = 0;
}

// --- Destructor ---

// Destructor: Frees the dynamically allocated Heap memory to prevent memory leaks
MystringGlobal::~MystringGlobal() {
    delete[] str;
}

// --- Assignment Operators ---

// Copy assignment operator: Cleans up current memory and performs a deep copy from rhs
MystringGlobal &MystringGlobal::operator=(const MystringGlobal &rhs) {
    if (this == &rhs) {
        return *this; // Protect against self-assignment (e.g., a = a)
    }
    
    delete[] this->str; // Clear old memory
    
    length = rhs.length;
    str = new char[length + 1];
    std::strcpy(str, rhs.str);
    
    return *this;
}

// Move assignment operator: Cleans up current memory and steals the pointer from an R-value
MystringGlobal &MystringGlobal::operator=(MystringGlobal &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    delete[] this->str; // Clear old memory

    length = rhs.length;
    str = rhs.str; // Steal the pointer
    
    rhs.str = nullptr; // Nullify the source
    rhs.length = 0;
    
    return *this;
}

// --- Global Friend Operators ---

// Equality operator (Friend): Compares the actual text of two strings using std::strcmp
bool operator==(const MystringGlobal &lhs, const MystringGlobal &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Unary minus operator (Friend): Creates a new lowercase version of the string
MystringGlobal operator-(const MystringGlobal &obj) {
    char *buff = new char[obj.length + 1];
    std::strcpy(buff, obj.str);

    for (int i = 0; i < obj.length; i++) {
        buff[i] = std::tolower(buff[i]);
    }

    MystringGlobal temp{buff};
    delete[] buff;

    return temp;
}

// Binary plus operator (Friend): Concatenates two strings and returns a new object
MystringGlobal operator+(const MystringGlobal &lhs, const MystringGlobal &rhs) {
    int new_length = lhs.length + rhs.length;
    char *buff = new char[new_length + 1];

    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);

    MystringGlobal temp{buff};
    delete[] buff;

    return temp;
}

// Stream insertion operator (Friend): Outputs the string directly to std::ostream
std::ostream &operator<<(std::ostream &os, const MystringGlobal &rhs) {
    os << rhs.str;
    return os;
}

// Stream extraction operator (Friend): Safely reads input into the object via std::string
std::istream &operator>>(std::istream &in, MystringGlobal &rhs) {
    std::string temp_str;
    in >> temp_str; // Safe input reading without fixed-size buffer overflows
    rhs = MystringGlobal(temp_str.c_str()); // Safely assign using the overloaded constructor and assignment
    return in;
}

// --- Methods & Getters ---

// Display method: Prints the string and its length to standard output
void MystringGlobal::display() const {
    std::cout << str << " : " << length << std::endl;
}

// Getter: Returns the length of the string
int MystringGlobal::get_length() const {
    return length;
}

// Getter: Returns the raw C-style string pointer
const char* MystringGlobal::get_str() const {
    return str;
}