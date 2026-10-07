#include <iostream>
#include <vector>

using namespace std;

// Functions prototypes
void display (int *ptr, int n);
void swap_pointers(int *a, int *b);
void display_vec(const vector<string> * const v);
int* find_max_pointer (int arr[], int size);

int main() {
    // ===============================
    // 1. DECLARING POINTERS
    // ===============================
    cout << "1. Declaring Pointers. " << endl;
    cout << "--------------------------------------------------------" << endl;
    
    int *intpointer {nullptr};
    double *doublepointer {nullptr};
    char *charpointer {nullptr};
    float *floatpointer {nullptr};

    // Nullptr means no value or zero, should be intialized as that so we avoid garbage that 
    // and addresses we have no business messing around
    
    cout << intpointer << endl;
    cout << doublepointer << endl;
    
    // Note: C++ tries to treat char pointers as strings when printing. 
    // Casting it to (void*) forces it to print the raw memory address instead!
    cout << (void*)charpointer << endl; 
    
    cout << floatpointer << endl;

    // =================================================================
    // 2. ACCESSING THE POINTER ADDRESS AND STORING ADDRESS IN A POINTER
    // =================================================================
    cout << "\n2. Pointer address and storing address in a pointer. " << endl;
    cout << "--------------------------------------------------------" << endl;
    
    int num {10};

    cout << "Value of num is: " << num << endl;
    cout << "Size of num is: " << sizeof num << " bytes" << endl;
    cout << "Address of num is: " << &num << endl;

    int *p;
    cout << "\n[GARBAGE] Value of p is: " << p << endl; // garbage, not initialized
    cout << "Size of p is: " << sizeof p << " bytes" << endl;
    cout << "Address of p is: " << &p << endl;

    p = nullptr; // This is how we should initialize it if we do not have a value
    cout << "\nValue of p is: " << p << endl; // no longer garbage, now 0
    cout << "Size of p is: " << sizeof p << " bytes" << endl;
    cout << "Address of p is: " << &p << endl;

    // -----------------------------------------------------------------
    // Proving that all pointers are the same size in memory
    // regardless of the data type they point to
    // -----------------------------------------------------------------
    
    cout << "\n--- Size of the Actual Data ---" << endl;
    cout << "sizeof(int) is: " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(double) is: " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(unsigned long long) is: " << sizeof(unsigned long long) << " bytes" << endl;
    cout << "sizeof(string) is: " << sizeof(string) << " bytes" << endl;
    cout << "sizeof(vector<string>) is: " << sizeof(vector<string>) << " bytes" << endl;

    cout << "\n--- Size of the Pointers ---" << endl;
    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    string *p4 {nullptr};
    vector<string> *p5 {nullptr};

    cout << "sizeof p1 (int*) is: " << sizeof p1 << " bytes" << endl;
    cout << "sizeof p2 (double*) is: " << sizeof p2 << " bytes" << endl;
    cout << "sizeof p3 (unsigned long long*) is: " << sizeof p3 << " bytes" << endl;
    cout << "sizeof p4 (string*) is: " << sizeof p4 << " bytes" << endl;
    cout << "sizeof p5 (vector<string>*) is: " << sizeof p5 << " bytes" << endl;

    // Demonstrating that a pointer stores the memory address of a variable
    cout << "\n--- Equal value and address ---" << endl;
    
    int score {100};
    int *score_ptr {nullptr};
    
    // Assign the memory address of 'score' to the pointer
    score_ptr = &score; 
    
    cout << "Value of score is: " << score << endl; // Displays the integer value
    cout << "Address of score (&score) is: " << &score << endl; // Displays the memory address
    
    // The value of the pointer itself is the memory address it holds
    cout << "Value of score_ptr is: " << score_ptr << endl; // Matches the address of 'score'

    // =================================================================
    // 3. DEREFERENCING POINTERS (STEP BY STEP)
    // =================================================================
    cout << "\n3. Dereferencing pointers step by step. " << endl;
    cout << "--------------------------------------------------------" << endl;

    // Declare sample data and point directly to its stack address
    vector<size_t> numbers_vector {100, 101, 102, 103, 104, 105};
    vector<size_t> *numbers_vector_ptr = &numbers_vector;
    
    // Step 3.1: Verify memory addresses match
    cout << "\n[3.1] Storing Addresses & Memory Setup:" << endl;
    cout << "  -> Stack Address  (&numbers_vector)    : " << &numbers_vector << endl;
    cout << "  -> Pointer Holds  (numbers_vector_ptr) : " << numbers_vector_ptr << endl;
    cout << "  -> Is memory synced?                   : "
         << (&numbers_vector == numbers_vector_ptr ? "YES (Identical)" : "NO") << endl;

    // Step 3.2: Direct Member Access via Arrow Operator (->)
    cout << "\n[3.2] Accessing Container Methods via Pointer Arrow (->):" << endl;
    cout << "  -> numbers_vector_ptr->size()          : " << numbers_vector_ptr->size() << " elements" << endl;
    cout << "  -> numbers_vector_ptr->capacity()      : " << numbers_vector_ptr->capacity() << " allocated capacity" << endl;

    // Step 3.3: Reading Values — Dereference Mechanics
    cout << "\n[3.3] Fetching Values (Dereferencing):" << endl;
    cout << "  -> Parentheses Way   ((*numbers_vector_ptr)[0]): " << (*numbers_vector_ptr)[0] << endl;
    cout << "  -> Double Index Way  (numbers_vector_ptr[0][0]): " << numbers_vector_ptr[0][0] << endl;
    cout << "  -> Safe Method Way   (numbers_vector_ptr->at(0)): " << numbers_vector_ptr->at(0) << endl;

    // Step 3.4: Iterating Through Memory via Pointer Dereference (*numbers_vector_ptr)
    cout << "\n[3.4] Traversal over Dereferenced Range Loop (*numbers_vector_ptr):" << endl;
    cout << "  -> Values: [ ";
    for (const auto &val : *numbers_vector_ptr) {
        cout << val << " ";
    }
    cout << "]" << endl;
    cout << "--------------------------------------------------------" << endl;

    // =================================================================
    // 4. DYNAMIC MEMORY ALLOCATION
    // =================================================================
    cout << "\n4. Dynamic memory allocation. " << endl;
    cout << "--------------------------------------------------------" << endl;

    // Dynamically allocate the object on the heap
    vector<int> *vec_ptr {nullptr};
    vec_ptr = new vector<int>;

    // Generate values from 10 to 150 (incrementing by 10) and push them
    for (int i = 10; i <= 150; i += 10) {
        vec_ptr->push_back(i);
    }

    cout << "--- Iterating through a dynamically allocated vector ---" << endl;

    for (auto val : *vec_ptr) {
        cout << "Value: " << val << endl;
    }

    // Free the heap memory
    delete vec_ptr;
    vec_ptr = nullptr;

    // =================================================================
    // 5. THE RELATIONSHIP BETWEEN ARRAYS AND POINTERS
    // =================================================================
    cout << "\n5. The relationship between arrays and pointers. " << endl;
    cout << "--------------------------------------------------------" << endl;

    int scores[] {10, 20, 30, 40, 50, 60, 70};
    int *ptr_scores {scores};

    cout << "\n[ BASE MEMORY ADDRESSES ]" << endl;
    cout << "Array 'scores' RAM address:     " << scores << endl;
    cout << "Pointer 'ptr_scores' RAM addr:  " << ptr_scores << endl;

    cout << "\n[ SUBSCRIPT NOTATION (Getting Values) ]" << endl;
    cout << "scores[0]:     " << scores[0] << endl;
    cout << "scores[1]:     " << scores[1] << endl;
    cout << "ptr_scores[2]: " << ptr_scores[2] << endl;

    cout << "\n[ OFFSET NOTATION - GETTING VALUES (Using '*') ]" << endl;
    // The '*' dereferences the address to get the integer inside
    cout << "*(scores)         = " << *(scores)     << " (Value at index 0)" << endl;
    cout << "*(scores + 1)     = " << *(scores + 1) << " (Value at index 1)" << endl;
    cout << "*(ptr_scores + 2) = " << *(ptr_scores + 2) << " (Value at index 2)" << endl;

    cout << "\n[ OFFSET NOTATION - GETTING RAM ADDRESSES (No '*') ]" << endl;
    // Removing the '*' leaves just the raw memory address calculations
    cout << "(scores)          = " << (scores)     << " (Addr of index 0)" << endl;
    cout << "(scores + 1)      = " << (scores + 1) << " (Addr of index 1, +4 bytes)" << endl;
    cout << "(ptr_scores + 2)  = " << (ptr_scores + 2) << " (Addr of index 2, +8 bytes)" << endl;

    // =================================================================
    // 6. POINTER ARITHMETIC
    // =================================================================
    cout << "\n6. Pointer arithmetic. " << endl;
    cout << "--------------------------------------------------------" << endl;

    // The '-1' acts as a sentinel value so the loop knows where the data ends
    int new_scores[] {200, 150, 100, 50, 10, -1};
    int *ptr_new_scores {new_scores};

    cout << "\n[ METHOD 1: Separate Dereference and Increment ]" << endl;
    while (*ptr_new_scores != -1) {
        // Print the value, then print the RAM address to see it jump
        cout << "Value: " << *ptr_new_scores << "\t| RAM: " << ptr_new_scores << endl;
        ptr_new_scores++; // Moves the pointer forward by 4 bytes (size of int)
    }

    cout << "\n--- Resetting pointer to index 0 (new_scores) ---" << endl;
    ptr_new_scores = new_scores; // Point it back to the start of the array

    cout << "\n[ METHOD 2: The 'One-Liner' (*ptr++) ]" << endl;
    while (*ptr_new_scores != -1) {
        // The ++ happens AFTER the value is fetched
        cout << "Value: " << *ptr_new_scores++ << endl; 
    }

    // =================================================================
    // 7. POINTER COMPARISON (Address vs Value)
    // =================================================================
    cout << "\n7. Pointer Comparison" << endl;
    cout << "--------------------------------------------------------" << endl;

    string name1 = "hugo";
    string name2 = "hugo";
    string name3 = "pedro";

    string *ptr1 {&name1};
    string *ptr2 {&name2};
    string *ptr3 {&name3};
    string *ptr4 {ptr1}; // ptr4 points to the exact same address as ptr1

    // Enable true/false console output instead of 1/0
    cout << boolalpha; 

    cout << "\n[ THE RAW RAM ADDRESSES ]" << endl;
    cout << "ptr1 (name1): " << ptr1 << endl;
    cout << "ptr2 (name2): " << ptr2 << endl;
    cout << "ptr3 (name3): " << ptr3 << endl;
    cout << "ptr4 (alias): " << ptr4 << " (Look! Matches ptr1)" << endl;

    cout << "\n[ 1. COMPARING MEMORY ADDRESSES (Are they the same box?) ]" << endl;
    cout << "ptr1 == ptr2 : " << (ptr1 == ptr2) 
         << "  -> (False: They hold the same word, but live in different RAM boxes)" << endl;
    
    cout << "ptr1 == ptr4 : " << (ptr1 == ptr4)
         << "  -> (True: They both point to the exact same RAM box)" << endl;

    cout << "\n[ 2. COMPARING VALUES (Is the content inside the box the same?) ]" << endl;
    cout << "*ptr1 == *ptr2 : " << (*ptr1 == *ptr2)
         << "  -> (True: The boxes are different, but both contain 'hugo')" << endl;
    
    cout << "*ptr1 == *ptr3 : " << (*ptr1 == *ptr3)
         << " -> (False: 'hugo' does not equal 'pedro')" << endl;

    // =================================================================
    // 8. CONST AND POINTERS (PASSING POINTERS TO FUNCTIONS)
    // =================================================================
    cout << "\n8. Const and pointers (passing pointers to functions) " << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << "\nPassing C-style arrays to functions (by pointer)" << endl;
    int arr[] {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    // ptr will store the address of first block of array
    int* ptr = arr;

    // passing argument to a function as pointer, will play the values of the whole array by dereferecing
    display(ptr, n);

    cout << endl;

    cout << "\nSwapping values using pointers" << endl;

    int x {200};
    int y {400};

    cout << "x value before swapping is: " << x << endl;
    cout << "y value before swapping is: " << y << endl;

    cout << "\n--- Executing Swap ---" << endl;
    // We pass the memory addresses of x and y using the '&' (address-of) operator
    swap_pointers(&x, &y);

    cout << "x value after swapping is: " << x << endl;
    cout << "y value after swapping is: " << y << endl;

    cout << "\nPassing vectors to functions (by pointer)" << endl;

    vector<string> names {"Hugo", "Pedro", "Luís", "André"};

    cout << "Displaying Vector data: \n> ";
    display_vec(&names); // Passing the memory address of the vector

    // =================================================================
    // 9. RETURNING A POINTER FROM A FUNCTION
    // =================================================================
    cout << "\n9. Returning a pointer from a function " << endl;
    cout << "--------------------------------------------------------" << endl;

    // Initializes the dataset to be evaluated
    int numbers[] {100, 250, 450, 600, 500, 210};
    
    // Calculates the element count dynamically to maintain accuracy if the underlying data type changes
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    // Retrieves a pointer to the maximum value within the dataset
    int* ptr_to_max = find_max_pointer(numbers, array_size);

    // Outputs the memory address followed by the dereferenced maximum value
    cout << "Memory address of max: " << ptr_to_max << endl;
    cout << "Actual highest value: " << *ptr_to_max << endl;

    // =================================================================
    // 10. REFERENCES 
    // =================================================================
    cout << "\n10. References" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    // A reference (&) serves as an alias for an existing variable, utilizing the exact same memory address.
    // Iterating via reference optimizes performance by eliminating memory allocation for data duplication.

    vector<string> my_names {"Hugo", "Pedro", "André", "Rebelo"};

    cout << "\n--- Pass-by-Value Execution ---" << endl;
    
    // Iterates by value, modifying only temporary copies. The underlying vector remains unmodified.
    for (auto str : my_names) {
        str = "Modified";
    }

    cout << "State post-pass-by-value: \n> ";
    
    // Iterates via constant reference to output data efficiently without triggering copy constructors.
    for (auto const &str : my_names) {
        cout << str << " "; 
    }
    cout << endl;

    cout << "\n--- Pass-by-Reference Execution ---" << endl;
    
    // Iterates by reference, directly accessing and modifying the underlying memory locations.
    for (auto &str : my_names) {
        str = "Hugo";
    }

    cout << "State post-pass-by-reference: \n> ";
    for (auto const &str : my_names) {
        cout << str << " ";
    }
    cout << endl;

    // =================================================================
    // 11. L-VALUES AND R-VALUES
    // =================================================================
    cout << "\n11. L-Values and R-Values" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Concept: L-values possess an identifiable memory address (persistent state).
    // R-values represent temporary data or literals without a persistent memory address.

    // 'x_x' is an L-value (addressable). '100' is an R-value (literal).
    int x_x = 100;
    
    // 'y_y' is an L-value. The evaluated result of '(x_x + 20)' is a temporary R-value.
    int y_y = x_x + 20;

    cout << "x_x value: " << x_x << " | y_y value: " << y_y << endl;

    cout << "\n--- Reference Binding Rules ---" << endl;

    // 1. L-Value References (&)
    // Binds exclusively to addressable L-values.
    int &l_ref = x_x; 
    
    // int &invalid_ref = 100; // COMPILER ERROR: Cannot bind an L-value reference to a temporary R-value.
    cout << "L-value reference mapped to x_x: " << l_ref << endl;

    // 2. R-Value References (&&) - Modern C++11 Feature
    // Binds explicitly to temporary R-values. Used in move semantics to transfer data without copying.
    int &&r_ref = 200;
    
    cout << "R-value reference mapped to temporary literal: " << r_ref << endl;
    cout << endl;

    return 0;
}

// Function Definitions
void display (int *ptr, int n) {
    for (int i = 0; i < n; ++i) {
        // Uses offset notation. 'ptr + i' calculates the address for index 'i', and '*' gets the value inside.
        cout << *(ptr + i) << " ";
    }
}

// Swaps the VALUES stored at two memory addresses.
void swap_pointers(int *a, int *b) {
    int temp = *a; // temp holds the actual VALUE inside box 'a' (200), not the address
    *a = *b;       // Overwrite the value in box 'a' with the value from box 'b' (400)
    *b = temp;     // Put the original value of 'a' (saved in temp) into box 'b' (200)
}

// The 'const' guarantees that whatever this pointer points to CANNOT be modified
void display_vec(const vector<string> * const v) {
    for (auto str : *v) {
        cout << str << " ";
    }
    cout << endl;
}

// Return a memory address to an integer
int* find_max_pointer (int arr[], int size) {
    // Store the address of the first element instead of the value
    int* max_ptr = &arr[0];

    // Loop through the array, use size to avoid out of bounds
    for (int i = 1; i < size; ++i) {
        if (arr[i] > *max_ptr) { // Dereference max_ptr to access value, check if array and position i is higher
            max_ptr = &arr[i]; // if yes, max_ptr has a new memory address that it needs to reference to that contains the biggest number
        }
    }
    return max_ptr; // Return max_ptr as an address
}