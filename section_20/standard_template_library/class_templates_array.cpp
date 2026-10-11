#include <iostream>
#include <string>
#include <string_view>

// ============================================================================
// Custom Array Class Template (Non-Type Template Parameter)
// NOTE: Educational implementation only! Always prefer std::array in production
// as it provides full STL iterator support, bounds checking, and optimizations.
// ============================================================================
template <typename T, int N>
class Array {
private:
    int size{N};
    T values[N]; // Raw internal array of size N allocated on stack memory

    // Friend stream insertion operator for clean printing
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";
        for (const auto &val : arr.values) {
            os << val << " ";
        }
        os << "]";
        return os;
    }

public:
    // Default constructor
    Array() = default;

    // Value-initialization constructor (fills all elements with init_val)
    explicit Array(T init_val) {
        fill(init_val);
    }

    // Fills every element in the array with specified value
    void fill(T val) {
        for (auto &item : values) {
            item = val;
        }
    }

    // Returns array capacity/size
    [[nodiscard]] constexpr int get_size() const {
        return size;
    }

    // Subscript operator for non-const access (allows writing/modifying)
    T &operator[](int index) {
        return values[index];
    }

    // Subscript operator for const access (read-only protection)
    const T &operator[](int index) const {
        return values[index];
    }
};

// =====================================
// Main Execution
// =====================================
int main() {
    std::cout << "\n>>> SECTION 20: CLASS TEMPLATES ARRAY DEMO <<<\n" << std::endl;

    // --- 1. Integer Array with Initial Fill ---
    std::cout << "--- 1. Integer Custom Array (Size 5) ---" << std::endl;
    Array<int, 5> nums{10}; // Fills all 5 elements with 10
    std::cout << "Initial nums: " << nums << std::endl;
    std::cout << "Array Size:   " << nums.get_size() << std::endl;

    // Modifying elements using non-const operator[]
    nums[0] = 99;
    nums[4] = 55;
    std::cout << "Modified nums: " << nums << "\n" << std::endl;

    // --- 2. String Array with Manual Assignment ---
    std::cout << "--- 2. String Custom Array (Size 3) ---" << std::endl;
    Array<std::string, 3> languages{"C++"};
    std::cout << "Initial languages: " << languages << std::endl;

    languages[1] = "Rust";
    languages[2] = "SQL";
    std::cout << "Updated languages: " << languages << "\n" << std::endl;

    // --- 3. Refilling the Array ---
    std::cout << "--- 3. Refill Demonstration ---" << std::endl;
    languages.fill("Modern C++");
    std::cout << "Refilled languages: " << languages << "\n" << std::endl;

    // --- 4. Const Array Read-Only Access ---
    std::cout << "--- 4. Const Correctness Verification ---" << std::endl;
    const Array<double, 4> constants(3.14159);
    std::cout << "Const Array: " << constants << std::endl;
    std::cout << "Element at index 2: " << constants[2] << std::endl; // Uses const operator[]

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}