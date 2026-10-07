/******************************************************************************
 * @file Mystring.hpp
 * @brief Definition of the Mystring class with custom memory management.
 ******************************************************************************/

#pragma once

class Mystring {
    private:
        char* str;      ///< Pointer to a C-style string allocated on the Heap
        int length;     ///< Cached length of the string for O(1) access

    public:
        // --- Constructors ---
        Mystring();
        Mystring(const char *s);
        Mystring(const Mystring &source);
        Mystring(Mystring &&source) noexcept; 

        // --- Destructor ---
        ~Mystring();

        // --- Assignment Operators ---
        Mystring &operator=(const Mystring &rhs);
        Mystring &operator=(Mystring &&rhs) noexcept;

        // --- Math & Logical Operators (Member Functions) ---
        
        /**
         * @brief Unary minus operator. Converts the string to lowercase.
         * @return A new Mystring object by value with all lowercase characters.
         */
        Mystring operator-() const;
        
        /**
         * @brief Binary plus operator. Concatenates two strings.
         * @param rhs The right-hand side Mystring to append.
         * @return A new Mystring object by value containing the concatenated result.
         */
        Mystring operator+(const Mystring &rhs) const;
        
        /**
         * @brief Equality operator. Compares the text of two strings.
         * @param rhs The right-hand side Mystring to compare against.
         * @return True if the strings are identical, false otherwise.
         */
        bool operator==(const Mystring &rhs) const;

        // --- Methods & Getters ---
        void display() const;
        int get_length() const;
        const char* get_str() const;
};