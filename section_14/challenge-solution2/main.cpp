/******************************************************************************
 * @file main.cpp
 * @brief Test suite for the Mystring class utilizing global friend functions
 *        for all operator overloads, stream I/O, comparisons, and increments.
 ******************************************************************************/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    cout << boolalpha << endl;
    
    // ------------------------------------------------------------------------
    // 1. COMPARISON OPERATORS (Global Friend)
    // ------------------------------------------------------------------------
    Mystring a {"frank"};
    Mystring b {"frank"};
    cout << (a == b) << endl;         // true
    cout << (a != b) << endl;         // false
    
    b = "george";
    cout << (a == b) << endl;         // false
    cout << (a != b) << endl;         // true
    cout << (a < b) << endl;          // true
    cout << (a > b) << endl;          // false
    
    // ------------------------------------------------------------------------
    // 2. UNARY MINUS, BINARY PLUS & += (Global Friend)
    // ------------------------------------------------------------------------
    Mystring s1 {"FRANK"};
    s1 = -s1;       
    cout << s1 << endl;               // frank                    

    s1 = s1 + "*****";
    cout << s1 << endl;               // frank*****       
    
    s1 += "-----";                        // frank*****-----
    cout << s1 << endl;
    
    // ------------------------------------------------------------------------
    // 3. MULTIPLICATION & REPETITION (*, *= Global Friend)
    // ------------------------------------------------------------------------
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;               // 123451234512345
    
    Mystring s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;               // abcdefabcdefabcdefabcdefabcdef
    
    // ------------------------------------------------------------------------
    // 4. STREAM EXTRACTION (>>) & CHAINED OPERATIONS
    // ------------------------------------------------------------------------
    Mystring repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "How many times would you like it repeated? " << endl;
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;
    
    cout << (repeat_string * 12) << endl;
    
    repeat_string = "RepeatMe";
    cout << (repeat_string + repeat_string + repeat_string) << endl;
    
    // ------------------------------------------------------------------------
    // 5. INCREMENT OPERATORS (PRE & POST via Global Friend)
    // ------------------------------------------------------------------------
    Mystring s = "Frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s; 
    cout << s << endl;                  // frank
    
    Mystring result;
    result = ++s;                         
    cout << s << endl;                  // FRANK
    cout << result << endl;             // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    
    result = s++;
    cout << s << endl;                  // FRANK
    cout << result << endl;             // frank

    return 0;
}