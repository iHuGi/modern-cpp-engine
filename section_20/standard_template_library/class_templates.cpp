#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <iomanip>

// =====================================
// Class Templates
// =====================================

// Generic Item class template holding a string name and a generic value T
template <typename T>
class Item {
private:
    std::string name;
    T value;

public:
    Item(std::string_view name, T value)
        : name{name}, value{value} {}

    // Getters
    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] T get_value() const { return value; }
};

// Overloading operator<< for generic Item<T>
// Allows direct stream printing for any Item instantiation
template <typename T>
std::ostream &operator<<(std::ostream &os, const Item<T> &item) {
    os << item.get_name() << ": " << item.get_value();
    return os;
}

// =====================================
// Struct Templates
// =====================================

// Generic pair struct holding two independent types (T1 and T2)
template <typename T1, typename T2>
struct MyPair {
    T1 first;
    T2 second;
};

// Overloading operator<< for generic MyPair<T1, T2>
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const MyPair<T1, T2> &pair) {
    os << "Pair[" << pair.first << ", " << pair.second << "]";
    return os;
}

// =====================================
// Main Execution
// =====================================
int main() {
    std::cout << "\n>>> SECTION 20: CLASS TEMPLATES DEMO <<<\n" << std::endl;

    // --- 1. Basic Class Template Instantiations ---
    std::cout << "--- 1. Basic Class Templates ---" << std::endl;
    Item<int> item1{"Hugo", 500};
    Item<std::string> item2{"Hugo", "Software Engineer"};

    std::cout << item1 << std::endl;
    std::cout << item2 << "\n" << std::endl;

    // --- 2. Nested Class Templates (Template Composition) ---
    std::cout << "--- 2. Nested Class Templates (Template Composition) ---" << std::endl;
    // Inner Item holds ("C++", "Software Engineering"), producing type Item<std::string>.
    // Outer Item holds ("Hugo", inner_item), producing type Item<Item<std::string>>.
    Item<Item<std::string>> nested_item{"Hugo", {"C++", "Software Engineering"}};

    std::cout << "Outer Item Name:  " << nested_item.get_name() << "\n";
    std::cout << "Inner Nested Item: " << nested_item.get_value() << "\n" << std::endl;

    // --- 3. STL Vector of Templated Objects ---
    std::cout << "--- 3. STL Vector Storing Item<double> ---" << std::endl;
    std::vector<Item<double>> vec;
    vec.reserve(4); // Pre-allocate memory for performance

    // emplace_back constructs Item<double> directly in vector memory
    vec.emplace_back("Hugo", 400.0);
    vec.emplace_back("André", 600.0);
    vec.emplace_back("Pedro", 800.0);
    vec.emplace_back("Luís", 1000.0);

    for (const auto &item : vec) {
        std::cout << "  - " << item << std::endl;
    }
    std::cout << std::endl;

    // --- 4. Multi-Type Struct Templates ---
    std::cout << "--- 4. Multi-Type Struct Templates (MyPair) ---" << std::endl;
    MyPair<std::string, int> p1{"Hugo", 100};
    MyPair<double, int> p2{77.7, 100};

    std::cout << "p1 -> " << p1 << std::endl;
    std::cout << "p2 -> " << p2 << std::endl;

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}