#include "I_Printable.hpp"

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    // Delegates the printing logic to the specific derived class at runtime
    obj.print(os); 
    return os;
}