#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> // Required for std::accumulate

// ============================================================================
// Helper Function Template to Display Any std::array
// ============================================================================
template <typename T, std::size_t N>
void display(const std::array<T, N>& arr) {
    std::cout << "[ ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Initialization, Element Access (.at vs []), .front(), .back()
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Initialization & Element Access ---" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5}; // Aggregate initialization
    std::array<int, 5> arr2;                // Uninitialized (contains garbage values!)

    display(arr1);
    display(arr2); // Will print random stack memory values

    arr2 = {10, 20, 30, 40, 50};
    display(arr2);

    std::cout << "Size of arr1: " << arr1.size() << std::endl;
    std::cout << "Size of arr2: " << arr2.size() << std::endl;

    arr1[0] = 1000;    // Fast, NO bounds checking
    arr1.at(1) = 2000; // Safe, performs bounds checking (throws std::out_of_range)
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;
    std::cout << "Back of arr2:  " << arr2.back() << std::endl;
}

// ============================================================================
// Test 2: .fill() and .swap()
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: .fill() and .swap() ---" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2{10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr1.fill(0); // Fills all elements with 0
    display(arr1);

    arr1.swap(arr2); // Swaps contents (O(N) for std::array, unlike O(1) for std::vector)
    display(arr1);
    display(arr2);
}

// ============================================================================
// Test 3: Accessing Raw Underlying C-Style Array Pointer via .data()
// ============================================================================
void test3() {
    std::cout << "\n--- Test 3: Raw Pointer Access (.data()) ---" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};

    // Useful when interfacing with legacy C APIs or libraries (e.g., OpenGL, C sockets)
    int* ptr = arr1.data();
    std::cout << "Raw pointer address: " << ptr << std::endl;

    *ptr = 10000; // Mutates arr1[0] directly through raw pointer
    display(arr1);
}

// ============================================================================
// Test 4: Sorting with std::sort
// ============================================================================
void test4() {
    std::cout << "\n--- Test 4: std::sort ---" << std::endl;
    std::array<int, 5> arr1{2, 1, 4, 5, 3};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

// ============================================================================
// Test 5: Finding Minimum & Maximum Elements (std::min_element / max_element)
// ============================================================================
void test5() {
    std::cout << "\n--- Test 5: std::min_element & std::max_element ---" << std::endl;
    std::array<int, 5> arr1{2, 1, 4, 5, 3};

    // Both algorithms return iterators, so we must dereference them (*)
    auto min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());

    std::cout << "Min: " << *min_num << " | Max: " << *max_num << std::endl;
}

// ============================================================================
// Test 6: Finding Adjacent Duplicate Elements (std::adjacent_find)
// ============================================================================
void test6() {
    std::cout << "\n--- Test 6: std::adjacent_find ---" << std::endl;
    std::array<int, 5> arr1{2, 1, 3, 3, 5};

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) {
        std::cout << "Adjacent duplicate element found with value: " << *adjacent << std::endl;
    } else {
        std::cout << "No adjacent duplicate elements found." << std::endl;
    }
}

// ============================================================================
// Test 7: Summing Elements with std::accumulate (<numeric>)
// ============================================================================
void test7() {
    std::cout << "\n--- Test 7: std::accumulate ---" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};

    // The 3rd argument (0) sets the initial value AND the return type!
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of elements in arr1: " << sum << std::endl;
}

// ============================================================================
// Test 8: Counting Exact Matches with std::count
// ============================================================================
void test8() {
    std::cout << "\n--- Test 8: std::count ---" << std::endl;
    std::array<int, 10> arr1{1, 2, 3, 1, 2, 3, 3, 3, 3, 3};

    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3: " << count << " times." << std::endl;
}

// ============================================================================
// Test 9: Conditional Counting with std::count_if & Lambda
// ============================================================================
void test9() {
    std::cout << "\n--- Test 9: std::count_if ---" << std::endl;
    std::array<int, 10> arr1{1, 2, 3, 50, 60, 70, 80, 200, 300, 400};

    // Count how many numbers are strictly between 10 and 200
    int count = std::count_if(arr1.begin(), arr1.end(), [](int x) {
        return x > 10 && x < 200;
    });

    std::cout << "Found " << count << " matches (10 < x < 200)." << std::endl;
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: std::array DEMO <<<" << std::endl;

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}