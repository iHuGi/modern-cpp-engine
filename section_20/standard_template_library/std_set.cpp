#include <iostream>
#include <set>
#include <string>

// ============================================================================
// Custom Class for Associative Container Testing
// ============================================================================
class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) : name{std::move(name)}, age{age} {}

    // CRITICAL: std::set relies strictly on operator< for both sorting AND uniqueness.
    // Two elements are considered equivalent if !(a < b) && !(b < a).
    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }

    bool operator==(const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << ":" << p.age;
    return os;
}

// ============================================================================
// Generic Display Helper
// ============================================================================
template <typename T>
void display(const std::set<T>& s) {
    std::cout << "[ ";
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Automatic Sorting, Uniqueness, and O(log N) Lookup
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Basic std::set Operations ------------------------" << std::endl;

    // Duplicates are silently ignored; elements are stored in sorted order
    std::set<int> s1{1, 4, 3, 5, 2, 1, 4, 3};
    display(s1); // [ 1 2 3 4 5 ]

    s1.insert(0);
    s1.insert(10);
    display(s1);

    // count() returns 1 if present, 0 otherwise (since duplicates cannot exist)
    if (s1.count(10)) {
        std::cout << "10 is in the set" << std::endl;
    } else {
        std::cout << "10 is NOT in the set" << std::endl;
    }

    // Always prefer member .find() (O(log N)) over generic std::find() (O(N))
    auto it = s1.find(5);
    if (it != s1.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    s1.clear();
    display(s1);
}

// ============================================================================
// Test 2: Custom Objects & Equivalence via operator<
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: std::set with Custom Objects (Person) ------------" << std::endl;

    std::set<Person> stooges{
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges); // Sorted by age: Larry:1, Moe:2, Curly:3

    stooges.emplace("James", 50);
    display(stooges);

    // Rejected! Age 50 already exists in the tree, so !(50 < 50) && !(50 < 50) is true
    stooges.emplace("Frank", 50);
    display(stooges);

    // Erase by iterator
    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end()) {
        stooges.erase(it);
    }
    display(stooges);

    // Note: Finds James:50 even though name is "XXXX", because operator< compares age!
    it = stooges.find(Person{"XXXX", 50});
    if (it != stooges.end()) {
        stooges.erase(it);
    }
    display(stooges);
}

// ============================================================================
// Test 3: Inspecting .insert() Return Value (std::pair<iterator, bool>)
// ============================================================================
void test3() {
    std::cout << "\n--- Test 3: Return Value of .insert() ------------------------" << std::endl;

    std::set<std::string> s{"A", "B", "C"};
    display(s);

    // C++17/20 structured binding: unpacks the returned std::pair<iterator, bool>
    auto [it_d, inserted_d] = s.insert("D");
    display(s);
    std::cout << std::boolalpha;
    std::cout << "Element: " << *it_d << " | Inserted: " << inserted_d << std::endl;

    // Attempting to insert duplicate "A" returns iterator to existing "A" and false
    auto [it_a, inserted_a] = s.insert("A");
    display(s);
    std::cout << "Element: " << *it_a << " | Inserted: " << inserted_a << std::endl;
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: STD::SET <<<" << std::endl;

    test1();
    test2();
    test3();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}