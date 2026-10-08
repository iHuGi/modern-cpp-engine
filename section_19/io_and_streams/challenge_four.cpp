#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <iomanip>

// =====================================
// Function Prototypes
// =====================================
void write_loop_output(std::string_view in_file, std::string_view out_file);

int main() {
    constexpr std::string_view in_file = "romeoandjuliet.txt";
    constexpr std::string_view out_file = "romeoandjuliet_new.txt";

    std::cout << "\n>>> CHALLENGE 4 - Copy one file to another <<<\n" << std::endl;

    write_loop_output(in_file, out_file);

    std::cout << "\n>>> CHALLENGE 4 - Copy one file to another finished <<<\n" << std::endl;
    return 0;
}

// =====================================
// Implementations
// =====================================
void write_loop_output(std::string_view in_file, std::string_view out_file) {
    std::cout << ">>> Reading data from " << in_file << " <<<\n";
    std::cout << ">>> Writing data to " << out_file << " <<<\n" << std::endl;

    // Open input stream for reading and output stream for writing
    std::ifstream input_file{std::string(in_file)};
    std::ofstream output_file{std::string(out_file)};

    // Validate if streams opened successfully
    if (!input_file) {
        std::cerr << "Error: Could not open " << in_file << " for reading" << std::endl;
        return;
    }

    if (!output_file) {
        std::cerr << "Error: Could not create/open " << out_file << " for writing" << std::endl;
        return;
    }

    std::string line;
    int line_number{0};

    // Read line by line from input stream and output formatted lines with line numbers
    while (std::getline(input_file, line)) {
        if (line.empty()) {
            output_file << "\n"; // Preserve empty lines without adding line numbers
        } else {
            ++line_number;
            output_file << std::setw(7) << std::left << line_number << line << "\n";
        }
    }

    std::cout << "Copy complete." << std::endl;

    // Streams close automatically via RAII upon exiting scope
}