#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>

// Helper function to display any vector of integers
void display(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Basic Iterator Navigation & Dereferencing
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Basic Iterator Navigation ---" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    // Explicitly typing the iterator (same as using 'auto it = nums1.begin();')
    std::vector<int>::iterator it = nums1.begin();
    std::cout << "First element (*it):      " << *it << std::endl;

    ++it; // Move to index 1 -> value 2
    std::cout << "After ++it:               " << *it << std::endl;

    it += 2; // Random access jump (+2 positions) -> value 4
    std::cout << "After it += 2:            " << *it << std::endl;

    it -= 2; // Move back 2 positions -> value 2
    std::cout << "After it -= 2:            " << *it << std::endl;

    // nums1.end() points ONE PAST the last element, so end() - 1 is the last item
    it = nums1.end() - 1;
    std::cout << "Last element (end() - 1): " << *it << std::endl;
}

// ============================================================================
// Test 2: Iterating Over a Container & Modifying Elements
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: Loop & Modify via Iterator ---" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::iterator it = nums1.begin();
    std::cout << "Printing via while loop:  [ ";
    while (it != nums1.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]" << std::endl;

    // Reset iterator and zero out all elements
    for (auto mod_it = nums1.begin(); mod_it != nums1.end(); ++mod_it) {
        *mod_it = 0; // Dereference and mutate in-place
    }

    std::cout << "After mutating to 0:      ";
    display(nums1);
}

// ============================================================================
// Test 3: Const Iterators (Read-Only Protection)
// ============================================================================
void test3() {
    std::cout << "\n--- Test 3: Const Iterators (cbegin / cend) ---" << std::endl;
    std::vector<int> nums1{10, 20, 30, 40, 50};

    // std::vector<int>::const_iterator it = nums1.begin();
    // Best practice in Modern C++: use cbegin() and cend() with auto
    auto it = nums1.cbegin();

    std::cout << "Const iteration:          [ ";
    while (it != nums1.cend()) {
        std::cout << *it << " ";
        // *it = 0; // COMPILER ERROR: assignment of read-only location
        ++it;
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 4: Reverse Iterators & Non-Contiguous Containers (list, map)
// ============================================================================
void test4() {
    std::cout << "\n--- Test 4: Reverse Iterators & Other Containers ---" << std::endl;

    // 1. Reverse iterator on a vector (rbegin to rend)
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "Reverse vector (rbegin):  [ ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " "; // Note: ++it moves BACKWARDS in a reverse_iterator!
    }
    std::cout << "]" << std::endl;

    // 2. Doubly-linked list with Const Reverse Iterator (crbegin / crend)
    std::list<std::string> names{"Hugo", "Pedro", "Luís", "André"};
    auto list_it = names.crbegin();
    std::cout << "Last name in list:        " << *list_it << std::endl;
    ++list_it; // Moves backward to the previous node
    std::cout << "Second-to-last in list:   " << *list_it << std::endl;

    // 3. Iterating over a std::map (Key-Value pairs)
    std::map<std::string, std::string> favorites{
        {"Hugo", "C++"},
        {"Pedro", "Rust"},
        {"André", "SQL"}
    };
    std::cout << "Map iteration:" << std::endl;
    for (auto map_it = favorites.cbegin(); map_it != favorites.cend(); ++map_it) {
        std::cout << "  - " << map_it->first << " loves " << map_it->second << std::endl;
    }
}

// ============================================================================
// Test 5: Iterating Over a Subset (Slice) of a Container
// ============================================================================
void test5() {
    std::cout << "\n--- Test 5: Subset Iteration ---" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto start = vec.begin() + 2; // Points to 3 (index 2)
    auto finish = vec.end() - 3;  // Points to 8 (stops before printing 8)

    std::cout << "Subset [index 2 to 6]:    [ ";
    while (start != finish) {
        std::cout << *start << " ";
        ++start;
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: STL ITERATORS DEMO <<<" << std::endl;

    test1();
    test2();
    test3();
    test4();
    test5();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}