#include <iostream>
#include <memory>
#include <vector>
#include <limits>

class Test {
    int data;

public:
    // Default constructor
    Test() : data{0} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }

    // Overloaded constructor
    Test(int data) : data{data} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }

    // Getter
    int get_data() const {
        return data;
    }

    // Destructor
    ~Test() {
        std::cout << "\tTest destructor (" << data << ")" << std::endl;
    }
};

// Function Prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

int main() {
    // 1. Create a unique_ptr to a vector of shared_ptrs
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    std::cout << "How many data points do you want to enter: ";
    int num{0};

    // Input validation for the number of elements
    while (!(std::cin >> num) || num <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // 2. Populate and display vector contents
    fill(*vec_ptr, num);
    display(*vec_ptr);

    // Memory cleanup triggers automatically when vec_ptr goes out of scope
    return 0;
}

// Function Definitions

// Factory function allocating the vector on the heap via std::make_unique
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

// Fills the vector with shared_ptrs pointing to Test objects
void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int user_input{0};
    for (int i = 1; i <= num; ++i) {
        std::cout << "Enter data point [" << i << "] : ";

        // Validates input stream against non-integer characters
        while (!(std::cin >> user_input)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        vec.push_back(std::make_shared<Test>(user_input));
    }
}

// Displays vector element values with clean output formatting
void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "\nDisplaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (const auto &ptr : vec) {
        std::cout << ptr->get_data() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}