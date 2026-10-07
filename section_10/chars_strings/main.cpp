#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

// ========================================
// HELPER FUNCTION: C-Style String Trimmer
// ========================================
void c_trim(char* str) {
    if (str == nullptr) return;

    // Trim trailing spaces
    size_t len = strlen(str);
    while (len > 0 && isspace(static_cast<unsigned char>(str[len - 1]))) {
        len--;
    }
    str[len] = '\0';

    // Trim leading spaces
    size_t start = 0;
    while (str[start] != '\0' &&
           isspace(static_cast<unsigned char>(str[start]))) {
        start++;
    }

    // Shift left if needed
    if (start > 0) {
        memmove(str, str + start, strlen(str + start) + 1);
    }
}

// ========================================
// HELPER FUNCTION: Modern String Trimmer
// ========================================
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");

    if (first == string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t");

    return str.substr(first, last - first + 1);
}

int main() {
    // ========================================
    // 1. C-Style Strings (Cleaned)
    // ========================================
    cout << "--- 1. C-STYLE STRINGS ---\n";

    char first_name[500]{};
    char last_name[500]{};
    char full_name[1000]{};

    cout << "Please enter your first name: ";
    cin.getline(first_name, sizeof(first_name));

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    c_trim(first_name);

    cout << "Please enter your last name: ";
    cin.getline(last_name, sizeof(last_name));

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    c_trim(last_name);

    cout << "\nHello, " << first_name << "!\n";
    cout << "Your first name has " << strlen(first_name) << " characters.\n";
    cout << "Your last name is " << last_name
         << " which has " << strlen(last_name) << " characters.\n";

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    cout << "\nYour full name is: " << full_name << "\n";

    cout << "\n=======================================\n\n";

    // ========================================
    // Modern C++ Strings
    // ========================================
    cout << "--- 2. MODERN C++ STRINGS ---\n";

    string cpp_first;
    string cpp_last;
    string cpp_full;

    cout << "Please enter your first name: ";
    getline(cin, cpp_first);
    cpp_first = trim(cpp_first);

    cout << "Please enter your last name: ";
    getline(cin, cpp_last);
    cpp_last = trim(cpp_last);

    cout << "\nHello, " << cpp_first << "!\n";
    cout << "Your first name has " << cpp_first.length() << " characters.\n";
    cout << "Your last name is " << cpp_last
         << " which has " << cpp_last.length() << " characters.\n";

    cpp_full = cpp_first + " " + cpp_last;

    cout << "\nYour full name is: " << cpp_full << '\n';

    return 0;
}