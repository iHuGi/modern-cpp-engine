#include <iostream>

using namespace std;

// Functions Prototypes
void print(const int *const arr, size_t size);
int* apply_all(const int arr_v1[], size_t array_size_v1, const int arr_v2[], size_t array_size_v2);

int main() {
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    size_t array1_size = sizeof(array1) / sizeof(array1[0]);
    size_t array2_size = sizeof(array2) / sizeof(array2[0]);
    
    cout << "Array 1: \n";
    print(array1, array1_size);
    
    cout << "\nArray 2: \n";
    print(array2, array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {5 * 3};

    cout << "\nResult: \n";
    print(results, results_size);
    
    delete [] results;
    
    cout << endl;

    return 0;
}

// Functions Definitions
void print(const int *const arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << "Array value at position " << i << " is : " << arr[i] << endl;
    }
}

// Return a memory address to an integer
int* apply_all(const int arr_v1[], size_t array_size_v1, const int arr_v2[], size_t array_size_v2) {

    int *new_array = new int[array_size_v1 * array_size_v2];
    
    int index = 0;
    
    for (size_t i = 0; i < array_size_v2; ++i) {
        for (size_t j = 0; j < array_size_v1; ++j) {
            
            new_array[index] = arr_v2[i] * arr_v1[j];
            
            index++;
        }
    }
    return new_array;
}