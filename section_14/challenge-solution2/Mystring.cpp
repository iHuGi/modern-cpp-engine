/******************************************************************************
 * @file Mystring.cpp
 * @brief Implementation of the Mystring class using global friend functions 
 *        for all operator overloads, stream I/O, and secure memory management.
 ******************************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include "Mystring.h"

// ============================================================================
// CONSTRUCTORS & DESTRUCTOR
// ============================================================================

/**
 * @brief Default constructor. Initializes an empty string containing '\0'.
 */
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

/**
 * @brief Overloaded constructor. Allocates heap memory and copies a C-style string.
 * @param s Pointer to a C-style string.
 */
Mystring::Mystring(const char *s)
    : str {nullptr} {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
}

/**
 * @brief Copy constructor. Performs a deep copy from another Mystring object.
 * @param source The source Mystring object to copy.
 */
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

/**
 * @brief Move constructor. Steals resources from a temporary object (R-value).
 * @param source The temporary Mystring object to move.
 */
Mystring::Mystring(Mystring &&source) noexcept
    : str(source.str) {
        source.str = nullptr;
}

/**
 * @brief Destructor. Frees dynamically allocated heap memory.
 */
Mystring::~Mystring() {
    delete [] str;
}

// ============================================================================
// ASSIGNMENT OPERATORS (Must remain member functions)
// ============================================================================

/**
 * @brief Copy assignment operator. Safely deep copies data from rhs.
 * @param rhs The right-hand side Mystring object.
 * @return Reference to the updated current object.
 */
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs)
        return *this;
        
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

/**
 * @brief Move assignment operator. Steals resources from an R-value.
 * @param rhs The right-hand side temporary Mystring object.
 * @return Reference to the updated current object.
 */
Mystring &Mystring::operator=(Mystring &&rhs) noexcept {
    if (this == &rhs)
        return *this;
        
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// ============================================================================
// METHODS & GETTERS
// ============================================================================

/**
 * @brief Displays the string and its calculated length to standard output.
 */
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

/**
 * @brief Gets the length of the string.
 * @return Length as an integer.
 */
int Mystring::get_length() const {
    return std::strlen(str); 
}

/**
 * @brief Gets the raw C-style string pointer.
 * @return Constant pointer to the internal character array.
 */
const char *Mystring::get_str() const {
    return str;
}

// ============================================================================
// GLOBAL FRIEND STREAM OPERATORS
// ============================================================================

/**
 * @brief Stream insertion operator (<<). Outputs string to an output stream.
 */
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

/**
 * @brief Stream extraction operator (>>). Safely reads input into a Mystring object.
 * @warning Uses an intermediate std::string to comply with C++20 safety standards and prevent buffer overflows.
 */
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    std::string temp_str;
    in >> temp_str;                         // Safe input reading via std::string
    rhs = Mystring{temp_str.c_str()};       // Assign safely using overloaded constructor
    return in;
}

// ============================================================================
// GLOBAL FRIEND COMPARISON OPERATORS
// ============================================================================

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) > 0);
}

// ============================================================================
// GLOBAL FRIEND ARITHMETIC & ASSIGNMENT OPERATORS
// ============================================================================

/**
 * @brief Unary minus operator (Global). Converts all characters to lowercase.
 */
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i = 0; i < std::strlen(buff); i++) 
        buff[i] = std::tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

/**
 * @brief Binary plus operator (Global). Concatenates two Mystring objects.
 */
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

/**
 * @brief Multiplication operator (Global). Repeats the string n times.
 */
Mystring operator*(const Mystring &lhs, int n) {
    Mystring temp;
    for (int i = 1; i <= n; i++)
        temp = temp + lhs;
    return temp;
}
        
Mystring &operator*=(Mystring &lhs, int n) {
    lhs = lhs * n;
    return lhs;
}

// ============================================================================
// GLOBAL FRIEND INCREMENT OPERATORS
// ============================================================================

/**
 * @brief Pre-increment operator ++s (Global). Converts string to uppercase.
 */
Mystring &operator++(Mystring &obj) {
    for (size_t i = 0; i < std::strlen(obj.str); i++)
        obj.str[i] = std::toupper(obj.str[i]);
    return obj;
}

/**
 * @brief Post-increment operator s++ (Global). Converts string to uppercase, returning old state.
 */
Mystring operator++(Mystring &obj, int) {
    Mystring temp{obj};
    ++obj;      // Invoke pre-increment logic
    return temp;
}