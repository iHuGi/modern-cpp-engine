#include <iostream>
#include <string>

// =====================================
// Function Templates
// =====================================

// 1. Single Type Templates
// Requires both parameters to be of the exact same type T
template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

// Pass-by-reference template for swapping generic types
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// 2. Multiple Types Template (C++14/C++20 best practice)
// Allows mixed types and automatically deduces return type
template <typename T, typename U>
auto add_mixed(T a, U b) {
    return a + b;
}

template <typename T, typename U>
void print_pair(T a, U b) {
    std::cout << a << " and " << b << std::endl;
}

// =====================================
// Custom Data Structure
// =====================================
struct Person {
    std::string name;
    int age;
    std::string sex;

    // Overload < operator required by min() template
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }

    // Overload + operator required by add() and add_mixed() templates
    Person operator+(const Person &rhs) const {
        return Person{
            this->name + " & " + rhs.name,
            this->age + rhs.age,
            this->sex
        };
    }
};

// Stream insertion operator for clean logging
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << " (" << p.age << ", " << p.sex << ")";
    return os;
}

// =====================================
// Main Execution
// =====================================
int main() {
    std::cout << "\n>>> SECTION 20: FUNCTION TEMPLATES <<<\n" << std::endl;

    // --- Example 1: Single Type Templates (Automatic Type Deduction) ---
    std::cout << "--- Single Type Templates ---" << std::endl;
    std::cout << "add(10, 20):         " << add(10, 20) << std::endl;             // Deduces T = int
    std::cout << "add(10.5, 20.3):     " << add(10.5, 20.3) << std::endl;         // Deduces T = double
    std::cout << "min(5, 12):          " << min(5, 12) << std::endl;              // Deduces T = int
    
    std::string s1{"Hello "};
    std::string s2{"World!"};
    std::cout << "add(string, string): " << add(s1, s2) << std::endl;           // Deduces T = std::string

    // --- Example 2: Generic Swap Function Template ---
    std::cout << "\n--- Generic Swap Template ---" << std::endl;
    int x{100};
    int y{200};
    std::cout << "Before swap -> X: " << x << ", Y: " << y << std::endl;
    swap(x, y);
    std::cout << "After swap  -> X: " << x << ", Y: " << y << std::endl;

    // --- Example 3: Explicit Type Specifications ---
    std::cout << "\n--- Explicit Type Arguments ---" << std::endl;
    // Forces '5' (int) to be treated as double so both match T = double
    std::cout << "add<double>(5, 10.5): " << add<double>(5, 10.5) << std::endl;

    // --- Example 4: Multiple Type Templates (Mixed Types) ---
    std::cout << "\n--- Multiple Template Parameters ---" << std::endl;
    std::cout << "add_mixed(5, 10.5):  " << add_mixed(5, 10.5) << std::endl;     // T = int, U = double
    
    std::cout << "print_pair:          ";
    print_pair("Age", 34);                                                     // T = const char*, U = int

    // --- Example 5: Function Templates with Custom Structs ---
    std::cout << "\n--- Templates with Custom Struct (Person) ---" << std::endl;
    Person p1{"Hugo", 35, "Male"};
    Person p2{"Pedro", 32, "Male"};
    Person p3{"Luís", 35, "Male"};
    Person p4{"André", 33, "Male"};

    // Uses min() template via Person::operator<
    Person younger = min(p1, p4);
    std::cout << "Younger Person (min): " << younger << std::endl;

    // Uses add_mixed() template via Person::operator+
    Person combined = add_mixed(p2, p3);
    std::cout << "Combined Person (add_mixed): " << combined << std::endl;

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}