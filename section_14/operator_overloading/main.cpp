/******************************************************************************
 * @file main.cpp
 * @brief Test suite for MystringGlobal class covering global friend operators and I/O streams.
 ******************************************************************************/

#include <iostream>
#include "MystringGlobal.hpp"

int main() {
    std::cout << "=== 1. INITIAL CREATION ===" << std::endl;
    MystringGlobal a{"Solid Snake"};
    MystringGlobal b;
    MystringGlobal c_obj;
    
    // Testando o novo operador de stream (<<) em vez do .display() antigo
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "\n=== 2. TESTING COPY ASSIGNMENT ===" << std::endl;
    b = a;          // Calls Copy Assignment Operator
    std::cout << "b (after copy): " << b << std::endl;

    std::cout << "\n=== 3. TESTING MOVE CONSTRUCTOR ===" << std::endl;
    // Passing a temporary R-value object triggers the Move Constructor
    MystringGlobal c{MystringGlobal{"Big Boss"}};
    std::cout << "c: " << c << std::endl;

    std::cout << "\n=== 4. TESTING MOVE ASSIGNMENT ===" << std::endl;
    // Assigning a temporary R-value to an existing object triggers Move Assignment
    b = MystringGlobal{"Foxhound"};
    std::cout << "b (after move assignment): " << b << std::endl;

    std::cout << "\n=== 5. TESTING SELF ASSIGNMENT ===" << std::endl;
    a = a;          // Should hit the 'if (this == &rhs)' check
    std::cout << "a (after self assignment): " << a << std::endl;

    // ---------------------------------------------------------
    // TESTS: GLOBAL FUNCTION OPERATORS
    // ---------------------------------------------------------

    std::cout << "\n=== 6. TESTING EQUALITY OPERATOR (==) ===" << std::endl;
    MystringGlobal clone{"Solid Snake"};
    MystringGlobal liquid{"Liquid Snake"};
    
    std::cout << "Is 'a' equal to 'clone'? " << (a == clone ? "True" : "False") << std::endl;
    std::cout << "Is 'a' equal to 'liquid'? " << (a == liquid ? "True" : "False") << std::endl;

    std::cout << "\n=== 7. TESTING UNARY MINUS OPERATOR (-) ===" << std::endl;
    MystringGlobal uppercase_boss{"OUTER HEAVEN"};
    std::cout << "Original: " << uppercase_boss << std::endl;
    
    MystringGlobal lowercase_boss = -uppercase_boss; // Should convert to lowercase
    std::cout << "Lowercase: " << lowercase_boss << std::endl;

    std::cout << "\n=== 8. TESTING BINARY PLUS OPERATOR (+) ===" << std::endl;
    MystringGlobal part1{"Metal Gear "};
    MystringGlobal part2{"Solid"};
    
    MystringGlobal game = part1 + part2; // Concatenates and returns a new object
    std::cout << "Game: " << game << std::endl;

    std::cout << "\n=== 9. TESTING CHAINING CONCATENATION (+) ===" << std::endl;
    MystringGlobal word1{"Tactical "};
    MystringGlobal word2{"Espionage "};
    MystringGlobal word3{"Action"};
    
    MystringGlobal genre = word1 + word2 + word3; 
    std::cout << "Genre: " << genre << std::endl;

    // ---------------------------------------------------------
    // THE TRUE POWER OF GLOBAL FUNCTIONS
    // ---------------------------------------------------------

    std::cout << "\n=== 10. TESTING C-STYLE LITERAL + OBJECT ===" << std::endl;
    MystringGlobal snake{"Snake"};
    MystringGlobal venom = "Punished " + snake; 
    std::cout << "Venom: " << venom << std::endl;

    std::cout << "\n=== 11. TESTING C-STYLE LITERAL == OBJECT ===" << std::endl;
    std::cout << "Is \"Snake\" == snake? " << ("Snake" == snake ? "True" : "False") << std::endl;

    // ---------------------------------------------------------
    // NEW TEST: STREAM EXTRACTION (>>)
    // ---------------------------------------------------------

    std::cout << "\n=== 12. TESTING STREAM EXTRACTION (>>) ===" << std::endl;
    MystringGlobal input_test;
    std::cout << "Escreve uma palavra para testar o std::cin >> input_test: ";
    std::cin >> input_test;
    std::cout << "Recebi do terminal: " << input_test << std::endl;

    std::cout << "\n=== 13. PROGRAM END ===" << std::endl;
    return 0;
}