#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    size_t n = input.length();

    for (size_t i = 0; i < n; ++i) {
        // 1. Print Leading Spaces
        // Row 0 needs n-1 spaces, Row 1 needs n-2, etc.
        for (size_t j = 0; j < n - i - 1; ++j) {
            cout << " ";
        }

        // 2. Print Increasing Part
        // Print from index 0 up to current row i
        for (size_t j = 0; j <= i; ++j) {
            cout << input[j];
        }

        // 3. Print Decreasing Part
        // Print from row i-1 down to 0
        for (int j = i - 1; j >= 0; --j) {
            cout << input[j];
        }

        // Move to next row
        cout << endl;
    }

    return 0;
}