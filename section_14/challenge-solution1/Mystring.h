/******************************************************************************
 * @file Mystring.h
 * @brief Definition of the Mystring class utilizing member functions for 
 *        operator overloading, copy/move semantics, and custom memory management.
 ******************************************************************************/

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring
{
    // --- Global Friend Operators for I/O Streams ---
    
    /**
     * @brief Stream insertion operator (<<). Outputs the string to a stream.
     * @param os The output stream (e.g., std::cout).
     * @param rhs The Mystring object to print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);

    /**
     * @brief Stream extraction operator (>>). Reads input into the string object.
     * @param in The input stream (e.g., std::cin).
     * @param rhs The Mystring object to store the input.
     * @return Reference to the input stream.
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
     * @source The Mystring object to copy from.
     */
    Mystring(const Mystring &source);             

    /**
     * @brief Move constructor (Steals memory).
     * @source The temporary Mystring object to move from.
     */
    Mystring(Mystring &&source) noexcept;                 

    /**
     * @brief Destructor. Frees the dynamically allocated memory.
     */
    ~Mystring();                                     
    
    // --- Assignment Operators ---
    
    /**
     * @brief Copy assignment operator (Deep Copy).
     * @param rhs The right-hand side Mystring object to assign from.
     * @return A reference to the current object.
     */
    Mystring &operator=(const Mystring &rhs);    

    /**
     * @brief Move assignment operator (Steals memory from R-values).
     * @param rhs The temporary right-hand side Mystring object to move from.
     * @return A reference to the current object.
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
   
    // --- Overloaded Operator Member Methods ---
    
    /**
     * @brief Unary minus operator. Converts the string to lowercase.
     * @return A new Mystring object by value with all lowercase characters.
     */
    Mystring operator-() const;                                   

    /**
     * @brief Binary plus operator. Concatenates two strings.
     * @param rhs The right-hand side Mystring object.
     * @return A new Mystring object containing the concatenated result.
     */
    Mystring operator+(const Mystring &rhs) const;         

    /**
     * @brief Equality operator. Checks if two strings are identical.
     * @param rhs The right-hand side Mystring object.
     * @return True if identical, false otherwise.
     */
    bool operator==(const Mystring &rhs) const;             

    /**
     * @brief Inequality operator. Checks if two strings are different.
     * @param rhs The right-hand side Mystring object.
     * @return True if different, false otherwise.
     */
    bool operator!=(const Mystring &rhs) const;             

    /**
     * @brief Less-than operator. Compares lexicographically.
     * @param rhs The right-hand side Mystring object.
     * @return True if lhs comes before rhs alphabetically.
     */
    bool operator<(const Mystring &rhs) const;              

    /**
     * @brief Greater-than operator. Compares lexicographically.
     * @param rhs The right-hand side Mystring object.
     * @return True if lhs comes after rhs alphabetically.
     */
    bool operator>(const Mystring &rhs) const;              

    /**
     * @brief Compound assignment operator (+=). Concatenates and assigns to current.
     * @param rhs The right-hand side Mystring object.
     * @return Reference to the updated current object.
     */
    Mystring &operator+=(const Mystring &rhs);          

    /**
     * @brief Multiplication operator. Repeats the string n times.
     * @param n Number of repetitions.
     * @return A new Mystring object with the repeated string.
     */
    Mystring operator*(int n) const;                        

    /**
     * @brief Compound multiplication operator (*=). Repeats current string in place.
     * @param n Number of repetitions.
     * @return Reference to the updated current object.
     */
    Mystring &operator*=(int n);                            

    /**
     * @brief Pre-increment operator (++s1). Converts the string to uppercase and returns it.
     * @return Reference to the updated current object.
     */
    Mystring &operator++();                                  

    /**
     * @brief Post-increment operator (s1++). Converts the string to uppercase, returning the old state.
     * @return A copy of the Mystring object before modification.
     */
    Mystring operator++(int);                               
};

#endif // _MYSTRING_H_