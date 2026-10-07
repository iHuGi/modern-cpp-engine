/******************************************************************************
 * @file Mystring.cpp
 * @brief Implementation of the Mystring class, constructors, assignment 
 *        operators, global streams, and member operator overloads.
 ******************************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
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
// ASSIGNMENT OPERATORS
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
 * @brief Stream insertion operator. Outputs the string to an output stream.
 * @param os Output stream (e.g., std::cout).
 * @param rhs Mystring object to output.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

/**
 * @brief Stream extraction operator. Reads input safely into a Mystring object.
 * @param in Input stream (e.g., std::cin).
 * @param rhs Mystring object to store the input.
 * @return Reference to the input stream.
 */
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    std::string temp_str;
    in >> temp_str;                 // Lê de forma segura usando std::string
    rhs = Mystring{temp_str.c_str()}; // Atualiza o objeto usando o construtor por C-string
    return in;
}

// ============================================================================
// COMPARISON OPERATORS
// ============================================================================

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

// ============================================================================
// ARITHMETIC & ASSIGNMENT OPERATORS
// ============================================================================

/**
 * @brief Unary minus operator. Converts all characters in the string to lowercase.
 * @return A new lowercase Mystring object.
 */
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

/**
 * @brief Binary plus operator. Concatenates two Mystring objects.
 * @param rhs Right-hand side Mystring object.
 * @return A new combined Mystring object.
 */
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

/**
 * @brief Multiplication operator. Repeats the string n times.
 * @param n Number of repetitions.
 * @return A new Mystring object containing the repeated sequence.
 */
Mystring Mystring::operator*(int n) const {
    Mystring temp;
    for (int i = 1; i <= n; i++)
        temp = temp + *this;
    return temp;
}

Mystring &Mystring::operator*=(int n) {
    *this = *this * n;
    return *this;
}

// ============================================================================
// INCREMENT OPERATORS
// ============================================================================

/**
 * @brief Pre-increment operator (++s). Converts string to uppercase and returns reference.
 */
Mystring &Mystring::operator++() {
    for (size_t i = 0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

/**
 * @brief Post-increment operator (s++). Converts string to uppercase, returning original state.
 */
Mystring Mystring::operator++(int) {
    Mystring temp(*this);       // Create copy of current state
    operator++();               // Invoke pre-increment logic
    return temp;                // Return the old state
}