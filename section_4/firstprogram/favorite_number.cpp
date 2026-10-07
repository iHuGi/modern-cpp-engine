#include <iostream>

int main() {
    std::cout << "C++ Standard version: " << __cplusplus << std::endl;

    int favorite_number; // Create a variable to store the number

    std::cout << "Enter your favorite number between 1 and 100: ";
    std::cin >> favorite_number; // Read the input from the keyboard

    std::cout << "Amazing! " << favorite_number << " is my favorite number too!" << std::endl;

    return 0;
}