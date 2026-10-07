/******************************************************************************
 * @file Mystring.h
 * @brief Definition of the Mystring class utilizing global friend functions 
 *        for operator overloading, custom heap management, and I/O streams.
 ******************************************************************************/

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring
{
    // --- Global Friend Operator Overloads ---
    
    /**
     * @brief Unary minus operator (Global). Converts string characters to lowercase.
     * @param obj The Mystring object to convert.
     * @return A new Mystring object in lowercase.
     */
    friend Mystring operator-(const Mystring &obj);

    /**
     * @brief Binary plus operator (Global). Concatenates two Mystring objects.
     * @param lhs Left-hand side Mystring object.
     * @param rhs Right-hand side Mystring object.
     * @return A new combined Mystring object.
     */
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

    /**
     * @brief Equality operator (Global). Checks if two strings are identical.
     */
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);

    /**
     * @brief Inequality operator (Global). Checks if two strings are different.
     */
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);

    /**
     * @brief Less-than operator (Global). Lexicographical comparison.
     */
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);

    /**
     * @brief Greater-than operator (Global). Lexicographical comparison.
     */
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);

    /**
     * @brief Compound assignment operator += (Global). Concatenates and assigns to lhs.
     */
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);

    /**
     * @brief Multiplication operator (Global). Repeats string n times.
     */
    friend Mystring operator*(const Mystring &lhs, int n);

    /**
     * @brief Compound multiplication operator *= (Global). Repeats and assigns in place.
     */
    friend Mystring &operator*=(Mystring &lhs, int n);

    /**
     * @brief Pre-increment operator ++s (Global). Converts string to uppercase.
     */
    friend Mystring &operator++(Mystring &obj);

    /**
     * @brief Post-increment operator s++ (Global). Converts string to uppercase, returning old state.
     */
    friend Mystring operator++(Mystring &obj, int);

    /**
     * @brief Stream insertion operator (<<). Outputs string to stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);

    /**
     * @brief Stream extraction operator (>>). Reads input into string.
     */
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;  ///< Pointer to a char[] that holds a C-style string on the Heap

public:
    // --- Constructors & Destructor ---
    
    /**
     * @brief Default constructor. Initializes an empty string.
     */
    Mystring();

    /**
     * @brief Overloaded constructor.
     * @param s Pointer to a C-style string to initialize with.
     */
    Mystring(const char *s);

    /**
     * @brief Copy constructor (Deep Copy).
     * @param source The Mystring object to copy from.
     */
    Mystring(const Mystring &source);

    /**
     * @brief Move constructor (Steals memory).
     * @param source The temporary Mystring object to move from.
     */
    Mystring(Mystring &&source) noexcept;

    /**
     * @brief Destructor. Frees the dynamically allocated memory.
     */
    ~Mystring();
    
    // --- Assignment Operators (Must remain member functions) ---
    
    /**
     * @brief Copy assignment operator (Deep Copy).
     */
    Mystring &operator=(const Mystring &rhs);

    /**
     * @brief Move assignment operator (Steals memory from R-values).
     */
    Mystring &operator=(Mystring &&rhs) noexcept;
    
    // --- Methods & Getters ---
    
    /**
     * @brief Displays the string and its length to standard output.
     */
    void display() const;
    
    /**
     * @brief Gets the length of the string.
     * @return The length as an integer.
     */
    int get_length() const;

    /**
     * @brief Gets the raw C-style string pointer.
     * @return A constant pointer to the internal character array.
     */
    const char *get_str() const;
};

#endif // _MYSTRING_H_