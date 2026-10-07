#include <iostream>

using namespace std;

int main() {
    // ==========================================
    // 1. CHARACTER TYPES (Single letters/symbols)
    // ==========================================
    char my_initial {'J'}; // MUST use single quotes!

    // ==========================================
    // 2. INTEGER TYPES (Whole numbers)
    // ==========================================
    short exam_score {95};                   // Small numbers
    int bank_balance {-150};                 // Standard (signed by default)
    unsigned int xp_points {4500};           // Positives ONLY (no negatives!)
    long distance_to_moon {238900};          // Bigger numbers
    long long global_population {8'000'000'000}; // MASSIVE numbers (you can use ' as commas for readability)

    // ==========================================
    // 3. FLOATING POINT TYPES (Decimals)
    // ==========================================
    float small_pi {3.14f};                  // Good for basic decimals. Put an 'f' at the end!
    double exact_pi {3.1415926535};          // Double the precision. The standard go-to for decimals.

    // ==========================================
    // 4. BOOLEAN TYPE (True or False)
    // ==========================================
    bool is_tired_of_theory {true};          // Behind the scenes: true = 1, false = 0

    // ==========================================
    // PRINTING SOME SH*T
    // ==========================================
    cout << "--- PRIMITIVE TYPES REFERENCE ---" << endl;
    cout << "Char: " << my_initial << endl;
    cout << "Short: " << exam_score << endl;
    cout << "Int: " << bank_balance << endl;
    cout << "Unsigned Int: " << xp_points << endl;
    cout << "Long: " << distance_to_moon << endl;
    cout << "Long Long: " << global_population << endl;
    cout << "Float: " << small_pi << endl;
    cout << "Double: " << exact_pi << endl;
    
    // This will print '1' because true = 1
    cout << "Bool: " << is_tired_of_theory << endl; 

    return 0;
}