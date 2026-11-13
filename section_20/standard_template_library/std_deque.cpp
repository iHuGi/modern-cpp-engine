#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator> // Required for std::front_inserter and std::back_inserter

// ============================================================================
// Generic Helper Template to Display Any std::deque<T>
// ============================================================================
template <typename T>
void display(const std::deque<T>& d) {
    std::cout << "[ ";
    for (const auto& elem : d) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Initialization & Element Access ([] vs .at())
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Deque Initialization & Element Access ---" << std::endl;

    std::deque<int> d{1, 2, 3, 4, 5};
    display(d);

    d = {2, 4, 5, 6};
    display(d);

    // Overloaded constructor: 10 elements initialized to 100
    std::deque<int> d1(10, 100);
    display(d1);

    d[0] = 100;    // Fast, no bounds checking
    d.at(1) = 200; // Safe, performs bounds checking (throws std::out_of_range)
    display(d);
}

// ============================================================================
// Test 2: Double-Ended Operations (push_front, push_back, pop_front, pop_back)
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: Push & Pop at Both Ends ---" << std::endl;

    std::deque<int> d{0, 0, 0};
    display(d);

    d.push_back(10);  // Appends to the back in O(1)
    d.push_back(20);
    display(d);

    d.push_front(100); // Prepends to the front in O(1) (unlike std::vector!)
    d.push_front(200);
    display(d);

    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back:  " << d.back() << std::endl;
    std::cout << "Size:  " << d.size() << std::endl;

    d.pop_back();  // Removes last element in O(1)
    d.pop_front(); // Removes first element in O(1)
    display(d);
}

// ============================================================================
// Test 3: Partitioning Even (Back) and Odd (Front) Elements Manually
// ============================================================================
void test3() {
    std::cout << "\n--- Test 3: Manual Front/Back Partitioning ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    // Even numbers go to the back (preserve order), odd numbers go to the front (reverse order)
    for (const auto& elem : vec) {
        if (elem % 2 == 0) {
            d.push_back(elem);
        } else {
            d.push_front(elem);
        }
    }
    display(d);
}

// ============================================================================
// Test 4: Order Preservation (push_back) vs Reversal (push_front)
// ============================================================================
void test4() {
    std::cout << "\n--- Test 4: push_back vs push_front Ordering ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    // Appending sequentially preserves the original order: [ 1 2 3 ... 10 ]
    for (const auto& elem : vec) {
        d.push_back(elem);
    }
    std::cout << "Using push_back:  ";
    display(d);

    d.clear();

    // Prepending sequentially reverses the order: [ 10 9 8 ... 1 ]
    for (const auto& elem : vec) {
        d.push_front(elem);
    }
    std::cout << "Using push_front: ";
    display(d);
}

// ============================================================================
// Test 5: STL Algorithms with std::front_inserter and std::back_inserter
// ============================================================================
void test5() {
    std::cout << "\n--- Test 5: std::copy with front_inserter & back_inserter ---" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    // Calls d.push_back() for each element
    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    std::cout << "With back_inserter:  ";
    display(d);

    d.clear();

    // Calls d.push_front() for each element (unavailable on std::vector!)
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    std::cout << "With front_inserter: ";
    display(d);
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: std::deque DEMO <<<" << std::endl;

    test1();
    test2();
    test3();
    test4();
    test5();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}