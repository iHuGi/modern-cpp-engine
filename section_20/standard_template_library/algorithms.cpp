#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <string>

// ============================================================================
// Custom Struct for STL Algorithm Testing
// ============================================================================
struct Person {
    std::string name;
    int age;

    // Required by std::find to compare Person objects!
    bool operator==(const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }

    // Required by std::sort or ordered containers
    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }
};

// ============================================================================
// Functor (Function Object) Example
// ============================================================================
struct SquareFunctor {
    void operator()(int x) const {
        std::cout << (x * x) << " ";
    }
};

// Regular function pointer target
void square_func(int x) {
    std::cout << (x * x) << " ";
}

// ============================================================================
// 1. std::find with Primitives & Custom Objects
// ============================================================================
void find_test() {
    std::cout << "\n--- 1. std::find Test ---" << std::endl;

    std::vector<int> nums{1, 2, 3, 4, 5};
    auto loc = std::find(nums.begin(), nums.end(), 3);

    if (loc != nums.end()) {
        std::cout << "Found primitive value: " << *loc << std::endl;
    } else {
        std::cout << "Primitive value not found!" << std::endl;
    }

    // Finding a custom Person object (uses Person::operator== under the hood)
    std::list<Person> team{
        {"Hugo", 35},
        {"Pedro", 32},
        {"André", 33}
    };

    auto loc_person = std::find(team.begin(), team.end(), Person{"Pedro", 32});
    if (loc_person != team.end()) {
        std::cout << "Found Person in list:  " << loc_person->name
                  << " (" << loc_person->age << ")" << std::endl;
    } else {
        std::cout << "Person not found!" << std::endl;
    }
}

// ============================================================================
// 2. std::count (Exact Value Matching)
// ============================================================================
void count_test() {
    std::cout << "\n--- 2. std::count Test ---" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5, 1, 2, 1};

    int occurrences = std::count(nums.begin(), nums.end(), 1);
    std::cout << "Number 1 occurs " << occurrences << " times." << std::endl;
}

// ============================================================================
// 3. std::count_if (Predicate / Lambda Matching)
// ============================================================================
void count_if_test() {
    std::cout << "\n--- 3. std::count_if Test (with Lambdas) ---" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5, 1, 2, 1, 100};

    // Count only even numbers
    int evens = std::count_if(nums.begin(), nums.end(), [](int x) {
        return x % 2 == 0;
    });
    std::cout << "Even numbers count: " << evens << std::endl;

    // Count numbers >= 5
    int ge_five = std::count_if(nums.begin(), nums.end(), [](int x) {
        return x >= 5;
    });
    std::cout << "Numbers >= 5 count: " << ge_five << std::endl;
}

// ============================================================================
// 4. std::replace (In-place Element Replacement)
// ============================================================================
void replace_test() {
    std::cout << "\n--- 4. std::replace Test ---" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5, 1, 2, 1};

    std::cout << "Before replace: [ ";
    for (int n : nums) { std::cout << n << " "; }
    std::cout << "]" << std::endl;

    // Replace all occurrences of 1 with 100
    std::replace(nums.begin(), nums.end(), 1, 100);

    std::cout << "After replace:  [ ";
    for (int n : nums) { std::cout << n << " "; }
    std::cout << "]" << std::endl;
}

// ============================================================================
// 5. std::all_of (Boolean Quantifier Check)
// ============================================================================
void all_of_test() {
    std::cout << "\n--- 5. std::all_of Test ---" << std::endl;
    std::vector<int> nums{1, 3, 5, 7, 9, 1, 3, 13, 19, 5};

    if (std::all_of(nums.begin(), nums.end(), [](int x) { return x > 10; })) {
        std::cout << "All elements are > 10" << std::endl;
    } else {
        std::cout << "Not all elements are > 10" << std::endl;
    }

    if (std::all_of(nums.begin(), nums.end(), [](int x) { return x < 20; })) {
        std::cout << "All elements are < 20" << std::endl;
    } else {
        std::cout << "Not all elements are < 20" << std::endl;
    }
}

// ============================================================================
// 6. std::for_each (Functors, Function Pointers, and Lambdas)
// ============================================================================
void for_each_test() {
    std::cout << "\n--- 6. std::for_each Test ---" << std::endl;
    std::vector<int> nums{1, 2, 3, 4};

    // 1. Using a Functor
    SquareFunctor sq;
    std::cout << "Using Functor:          [ ";
    std::for_each(nums.begin(), nums.end(), sq);
    std::cout << "]" << std::endl;

    // 2. Using a Function Pointer
    std::cout << "Using Function Pointer: [ ";
    std::for_each(nums.begin(), nums.end(), square_func);
    std::cout << "]" << std::endl;

    // 3. Using an Inline Lambda (Modern C++ standard approach)
    std::cout << "Using Lambda:           [ ";
    std::for_each(nums.begin(), nums.end(), [](int x) {
        std::cout << (x * x) << " ";
    });
    std::cout << "]" << std::endl;
}

// ============================================================================
// 7. std::transform (String Uppercase Transformation)
// ============================================================================
void string_transform_test() {
    std::cout << "\n--- 7. std::transform Test ---" << std::endl;
    std::string str1{"Modern C++ STL is awesome!"};
    std::cout << "Before transform: " << str1 << std::endl;

    // Reads from str1 [begin, end), writes back into str1 starting at begin()
    // ::toupper comes from global scope <cctype>
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

    std::cout << "After transform:  " << str1 << std::endl;
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: STL ALGORITHMS DEMO <<<" << std::endl;

    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    for_each_test();
    string_transform_test();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}