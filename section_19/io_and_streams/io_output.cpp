#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <iomanip>

// =====================================
// Function Prototypes
// =====================================
void write_basic_output(std::string_view filename);
void append_loop_output(std::string_view filename);

int main() {
    constexpr std::string_view output_file = "output_test.txt";

    std::cout << "\n>>> FILE I/O LAB: WRITING TEXT FILES <<<\n" << std::endl;

    // 1. Overwrite/Create new file with structured data
    write_basic_output(output_file);

    // 2. Append lines using a loop without destroying existing data
    append_loop_output(output_file);

    std::cout << ">>> FILE I/O LAB FINISHED <<<\n" << std::endl;
    return 0;
}

// =====================================
// Implementations
// =====================================

// 1. Basic writing using operator<< (Creates file or truncates existing one)
void write_basic_output(std::string_view filename) {
    std::cout << ">>> Writing basic formatted data to " << filename << " <<<\n" << std::endl;

    // Default mode is std::ios::out (Truncates/Overwrites if exists)
    std::ofstream output_file{std::string(filename)};

    if (!output_file) {
        std::cerr << "Error: Could not create/open " << filename << std::endl;
        return;
    }

    output_file << "Header: Section 19 File Output Test\n";
    output_file << "------------------------------------\n";
    output_file << std::fixed << std::setprecision(2);
    output_file << "Item 1 Score: " << std::setw(8) << 98.45 << "\n";
    output_file << "Item 2 Score: " << std::setw(8) << 100.00 << "\n\n";

    // RAII closes output_file safely here
}

// 2. Appending data in a loop using std::ios::app
void append_loop_output(std::string_view filename) {
    std::cout << ">>> Appending loop data to " << filename << " <<<\n" << std::endl;

    // std::ios::app preserves old content and writes strictly at the end
    std::ofstream output_file{std::string(filename), std::ios::app};

    if (!output_file) {
        std::cerr << "Error: Could not open " << filename << " for appending" << std::endl;
        return;
    }

    output_file << "=== Appended Loop Logs ===\n";
    for (int i = 1; i <= 5; ++i) {
        output_file << "Log Entry #" << i << ": System status OK [Value: " << (i * 42) << "]\n";
    }
    output_file << "\n";

    // RAII closes output_file safely here
}