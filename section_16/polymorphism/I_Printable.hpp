#pragma once
#include <iostream>

/**
 * @class I_Printable
 * @brief Abstract interface that provides polymorphic printing capabilities.
 * 
 * Any class inheriting from I_Printable must implement the print() method,
 * allowing it to be seamlessly output using the standard << operator.
 */
class I_Printable {
    /**
     * @brief Overloads the stream insertion operator to support polymorphic printing.
     * @param os The standard output stream.
     * @param obj The I_Printable object to be printed.
     * @return A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
    
public:
    /**
     * @brief Pure virtual function to define customized printing behavior in derived classes.
     * @param os The standard output stream to write to.
     */
    virtual void print(std::ostream &os) const = 0;
    
    /**
     * @brief Default virtual destructor to ensure proper cleanup of derived objects.
     */
    virtual ~I_Printable() = default;
};