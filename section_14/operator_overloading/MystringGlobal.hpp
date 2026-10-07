/******************************************************************************
 * @file MystringGlobal.hpp
 * @brief Definition of the MystringGlobal class utilizing non-member (global) 
 *        friend functions for operator overloading, including I/O streams.
 ******************************************************************************/

#pragma once

#include <iostream>

class MystringGlobal {
    private:
        char* str;      ///< Pointer to a C-style string allocated on the Heap
        int length;     ///< Cached length of the string for O(1) access

    public:
        // --- Constructors ---
        
        /**
         * @brief Default constructor. Initializes an empty string.
         */
        MystringGlobal();
        
        /**
         * @brief Overloaded constructor.
         * @param s Pointer to a C-style string to initialize with.
         */
        MystringGlobal(const char *s);
        
        /**
         * @brief Copy constructor (Deep Copy).
         * @param source The MystringGlobal object to copy from.
         */
        MystringGlobal(const MystringGlobal &source);
        
        /**
         * @brief Move constructor (Steals memory).
         * @param source The temporary MystringGlobal object to move from.
         */
        MystringGlobal(MystringGlobal &&source) noexcept; 

        // --- Destructor ---
        
        /**
         * @brief Destructor. Frees the dynamically allocated memory.
         */
        ~MystringGlobal();

        // --- Assignment Operators ---
        
        /**
         * @brief Copy assignment operator (Deep Copy).
         * @param rhs The right-hand side MystringGlobal object to assign from.
         * @return A reference to the current object.
         */
        MystringGlobal &operator=(const MystringGlobal &rhs);
        
        /**
         * @brief Move assignment operator (Steals memory from R-values).
         * @param rhs The temporary right-hand side MystringGlobal object to move from.
         * @return A reference to the current object.
         */
        MystringGlobal &operator=(MystringGlobal &&rhs) noexcept;

        // --- Global Friend Operators ---
        
        /**
         * @brief Equality operator (Global). Compares the text of two strings.
         * @param lhs The left-hand side MystringGlobal.
         * @param rhs The right-hand side MystringGlobal.
         * @return True if strings are identical, false otherwise.
         */
        friend bool operator==(const MystringGlobal &lhs, const MystringGlobal &rhs);
        
        /**
         * @brief Unary minus operator (Global). Converts the string to lowercase.
         * @param obj The MystringGlobal object to convert.
         * @return A new MystringGlobal object by value with all lowercase characters.
         */
        friend MystringGlobal operator-(const MystringGlobal &obj);
        
        /**
         * @brief Binary plus operator (Global). Concatenates two strings.
         * @param lhs The left-hand side MystringGlobal.
         * @param rhs The right-hand side MystringGlobal.
         * @return A new MystringGlobal object by value containing the concatenated result.
         */
        friend MystringGlobal operator+(const MystringGlobal &lhs, const MystringGlobal &rhs);

        /**
         * @brief Stream insertion operator (<<). Outputs the string to a stream.
         * @param os The output stream (e.g., std::cout).
         * @param rhs The MystringGlobal object to print.
         * @return Reference to the output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const MystringGlobal &rhs);

        /**
         * @brief Stream extraction operator (>>). Reads input into the string object.
         * @param in The input stream (e.g., std::cin).
         * @param rhs The MystringGlobal object to store the input.
         * @return Reference to the input stream.
         */
        friend std::istream &operator>>(std::istream &in, MystringGlobal &rhs);
        
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
        const char* get_str() const;
};