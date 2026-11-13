#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator> // Required for std::back_inserter

// ============================================================================
// Custom Class for STL Vector & Algorithm Testing
// ============================================================================
class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name{std::move(name)}, age{age} {}

    // Required for std::sort and ordered comparisons
    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }

    // Required for std::find and equality checks
    bool operator==(const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << ":" << p.age;
    return os;
}

// ============================================================================
// Helper Display Functions
// ============================================================================

// 1. Display using std::for_each and a Lambda expression
void display2(const std::vector<int>& vec) {
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "]" << std::endl;
}

// 2. Generic template function to display any std::vector<T>
template <typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Initialization & Overloaded Constructor Pitfall
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Vector Initialization ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5}; // Initializer list
    display(vec);

    vec = {2, 4, 5, 6}; // Reassignment via initializer list
    display2(vec);

    // Parentheses () invoke the overloaded constructor: 10 elements initialized to 100
    // Note: Curly braces {10, 100} would create a 2-element vector instead!
    std::vector<int> vec1(10, 100);
    display(vec1);
}

// ============================================================================
// Test 2: Dynamic Growth, .size(), .capacity(), .reserve(), .shrink_to_fit()
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: Size, Capacity & Reallocation ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    std::cout << "vec size:     " << vec.size() << std::endl;
    std::cout << "vec max_size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    // Exceeding capacity triggers heap reallocation (typically doubling capacity)
    vec.push_back(6);
    display(vec);
    std::cout << "After push_back(6) -> size: " << vec.size()
              << " | capacity: " << vec.capacity() << std::endl;

    // Releases unused allocated heap memory back to the OS
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit() -> size: " << vec.size()
              << " | capacity: " << vec.capacity() << std::endl;

    // Pre-allocates contiguous memory block to avoid repeated reallocations
    vec.reserve(100);
    std::cout << "After reserve(100) -> size: " << vec.size()
              << " | capacity: " << vec.capacity() << std::endl;
}

// ============================================================================
// Test 3: Element Access ([] vs .at())
// ============================================================================
void test3() {
    std::cout << "\n--- Test 3: Element Access ([] vs .at()) ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    vec[0] = 100;    // Fast, no bounds checking
    vec.at(1) = 200; // Safe, performs bounds checking (throws std::out_of_range)

    display(vec);
}

// ============================================================================
// Test 4: Custom Objects & .emplace_back() vs .push_back()
// ============================================================================
void test4() {
    std::cout << "\n--- Test 4: Custom Objects & emplace_back ---" << std::endl;

    std::vector<Person> vec;

    Person p1{"Larry", 18};
    vec.push_back(p1);                // Copies existing object into vector
    vec.push_back(Person{"Moe", 25}); // Constructs temporary and moves it

    // Best practice: constructs Person directly inside the vector's heap memory
    vec.emplace_back("Curly", 30);

    display(vec);
}

// ============================================================================
// Test 5: .front(), .back(), and .pop_back()
// ============================================================================
void test5() {
    std::cout << "\n--- Test 5: Front, Back & pop_back ---" << std::endl;

    std::vector<Person> vec{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };

    display(vec);
    std::cout << "Front: " << vec.front() << std::endl;
    std::cout << "Back:  " << vec.back() << std::endl;

    vec.pop_back(); // Removes last element ("Curly") in O(1) time
    display(vec);
}

// ============================================================================
// Test 6: .clear() and .erase() (Safe Iterator Removal)
// ============================================================================
void test6() {
    std::cout << "\n--- Test 6: Clear & Erase ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec.clear(); // Removes all elements (size becomes 0, capacity remains unchanged)
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);

    // Erase a range [begin, begin + 2) -> removes 1 and 2
    vec.erase(vec.begin(), vec.begin() + 2);
    display(vec);

    // Erase all even numbers safely without invalidating the loop iterator
    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0) {
            it = vec.erase(it); // erase() returns the valid iterator to the next element
        } else {
            ++it;
        }
    }
    display(vec);
}

// ============================================================================
// Test 7: .swap() (O(1) Internal Pointer Swap)
// ============================================================================
void test7() {
    std::cout << "\n--- Test 7: Vector Swap ---" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};

    display(vec1);
    display(vec2);

    vec2.swap(vec1); // Swaps internal heap pointers in O(1) time (even if sizes differ)
    display(vec1);
    display(vec2);
}

// ============================================================================
// Test 8: Sorting with std::sort
// ============================================================================
void test8() {
    std::cout << "\n--- Test 8: std::sort ---" << std::endl;

    std::vector<int> vec1{1, 21, 3, 40, 12};
    display(vec1);

    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

// ============================================================================
// Test 9: std::copy and std::copy_if with std::back_inserter
// ============================================================================
void test9() {
    std::cout << "\n--- Test 9: std::copy & std::back_inserter ---" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20};

    display(vec1);
    display(vec2);

    // Appends all elements of vec1 to the end of vec2 using push_back under the hood
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);

    // Conditional copy: appends only even numbers from vec1 into vec2
    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x) {
        return x % 2 == 0;
    });
    display(vec1);
    display(vec2);
}

// ============================================================================
// Test 10: Element-wise Transformation with std::transform
// ============================================================================
void test10() {
    std::cout << "\n--- Test 10: std::transform ---" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};
    std::vector<int> vec3;

    // Multiplies corresponding elements of vec1 and vec2, pushing results into vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
                   std::back_inserter(vec3),
                   [](int x, int y) { return x * y; });

    display(vec3);
}

// ============================================================================
// Test 11: Inserting a Range into Another Vector (std::find + .insert())
// ============================================================================
void test11() {
    std::cout << "\n--- Test 11: Range Insertion with .insert() ---" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2{100, 200, 300, 400};

    display(vec1);
    display(vec2);

    // Locate value 5 and insert all of vec2 right before it
    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        std::cout << "Inserting vec2 before 5..." << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Target element 5 not found." << std::endl;
    }

    display(vec1);
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: std::vector DEMO <<<" << std::endl;

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}