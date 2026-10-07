#include <iostream>
#include <string>

using namespace std;

int main() {
    // ---------------------------------------------------------
    // SECTION 1: BASIC OUTPUT (CLEANED UP)
    // ---------------------------------------------------------
    cout << "\n======================================================\n";
    cout << "          [ SECTION 1: STANDARD OUTPUT TEST ]           \n";
    cout << "======================================================\n\n";
    
    cout << "Executing output variants...\n";
    cout << "-> Standard Hello World!" << endl;
    cout << "-> Chained output: Hello " << "World!" << endl;
    cout << "-> Using newline characters:\n   Line 1\n   Line 2\n   Line 3\n";

    // ---------------------------------------------------------
    // SECTION 2: SINGLE INTEGER INPUT
    // ---------------------------------------------------------
    cout << "\n======================================================\n";
    cout << "          [ SECTION 2: INTEGER INPUT STREAM ]           \n";
    cout << "======================================================\n\n";

    int single_num;
    cout << "Enter a single integer: ";
    cin >> single_num;
    cout << "Memory captured. You entered: " << single_num << endl;

    // ---------------------------------------------------------
    // SECTION 3: MULTIPLE INTEGER INPUT
    // ---------------------------------------------------------
    cout << "\n======================================================\n";
    cout << "         [ SECTION 3: MULTIPLE INTEGER INPUT ]          \n";
    cout << "======================================================\n\n";

    int num1, num2;
    cout << "Enter two integers separated by a space (e.g., 10 20): ";
    cin >> num1 >> num2;
    cout << "Data received: " << num1 << " and " << num2 << endl;

    // ---------------------------------------------------------
    // SECTION 4: FLOATING POINT
    // ---------------------------------------------------------
    cout << "\n======================================================\n";
    cout << "           [ SECTION 4: FLOATING POINT DATA ]           \n";
    cout << "======================================================\n\n";

    double float_num;
    cout << "Enter a floating-point number (e.g., 3.14159): ";
    cin >> float_num;
    cout << "Precision recorded: " << float_num << endl;

    // ---------------------------------------------------------
    // SECTION 5: MIXED DATA TYPES (NEW EXAMPLE)
    // ---------------------------------------------------------
    cout << "\n======================================================\n";
    cout << "             [ SECTION 5: MIXED DATA TYPES ]            \n";
    cout << "======================================================\n\n";

    std::string user_name;
    int user_age;
    
    cout << "Enter your first name: ";
    cin >> user_name;
    
    cout << "Enter your age: ";
    cin >> user_age;
    
    // Formatting the final output string
    cout << "\n>>> Profile Summary <<<\n";
    cout << "Name: " << user_name << " | Age: " << user_age << endl;
    
    cout << "\n======================================================\n";
    cout << "                 [ EXECUTION COMPLETE ]                 \n";
    cout << "======================================================\n\n";

    return 0; // Signals to the OS that the program ran successfully
}