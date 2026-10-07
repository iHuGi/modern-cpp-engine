#include <iostream>
#include "Account.h"
#include "AccountExceptions.h"

int main() {
    std::cout << "--- Test 1: Initializing with negative balance ---" << std::endl;
    try {
        Account myAccount(-100.0);
        std::cout << "This line will NEVER print." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Overdrawing an account ---" << std::endl;
    try {
        Account myAccount(100.0);
        myAccount.withdraw(150.0);
        std::cout << "This line will NEVER print." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "\nProgram finished successfully." << std::endl;
    
    return 0;
}