#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

// =====================================
// Function Prototypes
// =====================================
void read_word_by_word(std::string_view filename);
void read_line_by_line(std::string_view filename);

int main() {
    constexpr std::string_view target_file = "test.txt";

    std::cout << "\n>>> FILE I/O LAB: READING TEXT FILES <<<\n" << std::endl;

    read_word_by_word(target_file);
    read_line_by_line(target_file);

    std::cout << ">>> FILE I/O LAB FINISHED <<<\n" << std::endl;
    return 0;
}

// =====================================
// Implementations
// =====================================

// 1. Reading formatted data (word by word / token by token)
void read_word_by_word(std::string_view filename) {
    std::cout << ">>> Reading file word by word <<<\n" << std::endl;

    std::ifstream input_file{filename.data()};

    // Check if opened correctly
    if (!input_file) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return;
    }

    std::string word;
    while (input_file >> word) {
        std::cout << "Word: " << word << std::endl;
    }

    std::cout << "\n";
    // RAII automatically closes input_file when it goes out of scope
}

// 2. Reading unformatted data (line by line)
void read_line_by_line(std::string_view filename) {
    std::cout << ">>> Reading file line by line <<<\n" << std::endl;

    std::ifstream input_file{filename.data()};

    // Check if opened correctly
    if (!input_file) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        std::cout << "Line: " << line << std::endl;
    }

    std::cout << "\n";
    // RAII automatically closes input_file when it goes out of scope
}