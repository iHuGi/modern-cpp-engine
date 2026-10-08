#include <iostream>
#include <iomanip>
#include <string>

// =====================================
// Function Prototypes
// =====================================
void demo_boolean_manipulators();
void demo_integer_manipulators();
void demo_floating_point_manipulators();
void demo_align_and_fill_manipulators();

int main() {
    std::cout << "\n>>> STARTING STREAM MANIPULATORS LAB <<<\n" << std::endl;

    demo_boolean_manipulators();
    demo_integer_manipulators();
    demo_floating_point_manipulators();
    demo_align_and_fill_manipulators();

    std::cout << ">>> LAB FINISHED SUCCESSFULLY <<<\n" << std::endl;
    return 0;
}

// =====================================
// Demonstrations (Implementations)
// =====================================

void demo_boolean_manipulators() {
    std::cout << "========================================" << std::endl;
    std::cout << "      Stream Manipulators: Booleans     " << std::endl;
    std::cout << "========================================\n" << std::endl;

    // 1. Isolate the logic from the presentation
    bool is_equal = (10 == 10);
    bool is_not_equal = (10 == 20);

    // 2. Default behavior (outputs 0 and 1)
    std::cout << "--- Default (noboolalpha) ---" << std::endl;
    std::cout << "is_equal      : " << is_equal << std::endl;
    std::cout << "is_not_equal  : " << is_not_equal << std::endl;

    // 3. Enable boolalpha (outputs true and false)
    std::cout << std::boolalpha;
    
    std::cout << "\n--- Enabled (boolalpha) ---" << std::endl;
    std::cout << "is_equal      : " << is_equal << std::endl;
    std::cout << "is_not_equal  : " << is_not_equal << std::endl;

    // 4. State RESET (Best Practice)
    std::cout << std::noboolalpha;
    std::cout << "\n"; 
}

void demo_integer_manipulators() {
    std::cout << "========================================" << std::endl;
    std::cout << "      Stream Manipulators: Integers     " << std::endl;
    std::cout << "========================================\n" << std::endl;

    // 1. Isolate the logic from the presentation
    int number = 42;

    // 2. Default behaviour (outputs in decimal)
    std::cout << "--- Default (decimal) ---" << std::endl;
    std::cout << "number (decimal) : " << number << std::endl;

    // 3. Enable hex and oct (outputs in hexadecimal and octal)
    std::cout << "\n--- Enabled (hex & oct) ---" << std::endl;
    std::cout << std::hex << "number (hex) : " << number << std::endl;
    std::cout << std::oct << "number (oct) : " << number << std::endl;

    // 4. Advanced integer manipulators (showbase, uppercase, showpos)
    std::cout << "\n--- Advanced (showbase, uppercase, showpos) ---" << std::endl;
    std::cout << std::showbase << std::uppercase << std::showpos;
    
    std::cout << std::hex << "number (hex) : " << number << std::endl;
    std::cout << std::oct << "number (oct) : " << number << std::endl;
    std::cout << std::dec << "number (dec) : " << number << std::endl;

    // 5. State RESET (Best Practice)
    std::cout << std::dec << std::noshowbase << std::nouppercase << std::noshowpos;
    std::cout << "\n";
}

void demo_floating_point_manipulators() {
    std::cout << "========================================" << std::endl;
    std::cout << "   Stream Manipulators: Floating Point  " << std::endl;
    std::cout << "========================================\n" << std::endl;

    // 1. Isolate the logic from the presentation
    double number = 1234567.891234;

    // 2. Default (outputs max 6 digits by default)
    std::cout << "--- Default ---" << std::endl;
    std::cout << "number : " << number << std::endl;

    // 3. Precision (Changes the number of digits displayed)
    std::cout << "\n--- Precision (4) ---" << std::endl;
    std::cout << std::setprecision(4) << "number : " << number << std::endl;

    // 4. Fixed (Forces exactly the precision amount of digits AFTER the decimal)
    std::cout << "\n--- Fixed (Precision 4 after decimal) ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4) << "number : " << number << std::endl;

    // 5. Scientific (E-notation)
    std::cout << "\n--- Scientific ---" << std::endl;
    std::cout << std::scientific << "number : " << number << std::endl;

    // 6. State RESET (Best Practice)
    // Clearing the scientific/fixed flags and resetting precision to default (6)
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << "\n";
}

void demo_align_and_fill_manipulators() {
    std::cout << "========================================" << std::endl;
    std::cout << "   Stream Manipulators: Align and Fill  " << std::endl;
    std::cout << "========================================\n" << std::endl;

    // 1. Isolate the logic from the presentation
    std::string text = "Hello";
    int num = 1234;

    // 2. Default (no spacing)
    std::cout << "--- Default ---" << std::endl;
    std::cout << text << num << std::endl;

    // 3. Set Width (setw only applies to the VERY NEXT item output)
    std::cout << "\n--- Width (10) ---" << std::endl;
    std::cout << std::setw(10) << text << std::setw(10) << num << std::endl;

    // 4. Left Justify & Set Fill character
    std::cout << "\n--- Left Justify & Fill (-) ---" << std::endl;
    std::cout << std::setfill('-') << std::left;
    std::cout << std::setw(10) << text << std::setw(10) << num << std::endl;

    // 5. State RESET (Best Practice)
    std::cout << std::setfill(' ') << std::right;
    std::cout << "\n";
}