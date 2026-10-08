#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>
#include <limits>

// =====================================
// Function Prototypes
// =====================================
std::string to_lower(std::string_view str);
std::string get_valid_user_word();
int count_word_occurrences(std::string_view filename, std::string_view target_word);

// =====================================
// Main Execution
// =====================================
int main() {
    constexpr std::string_view target_file = "romeoandjuliet.txt";

    std::cout << "\n>>> CHALLENGE 3 - WORD SEARCH <<<\n" << std::endl;

    // 1. Get user input
    std::string user_word = get_valid_user_word();

    // 2. Process file search
    int occurrences = count_word_occurrences(target_file, user_word);

    // 3. Display result
    std::cout << "\nThe word \"" << user_word << "\" was found " 
              << occurrences << " times in " << target_file << "." << std::endl;

    std::cout << "\n>>> CHALLENGE FINISHED <<<\n" << std::endl;
    return 0;
}

// =====================================
// Function Definitions
// =====================================

// Helper to convert strings to lowercase for case-insensitive search
std::string to_lower(std::string_view str) {
    std::string result{str};
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

// Prompts user for a word and validates input
std::string get_valid_user_word() {
    std::string word;
    while (true) {
        std::cout << "Enter a word to search for in Romeo and Juliet (e.g., love, Romeo, death): ";
        if (std::cin >> word && !word.empty()) {
            break;
        }
        
        // Handle bad input / clear buffer garbage
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return word;
}

// Opens the file and counts how many times target_word appears
int count_word_occurrences(std::string_view filename, std::string_view target_word) {
    std::ifstream input_file{std::string(filename)};

    if (!input_file) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return 0;
    }

    std::string clean_target = to_lower(target_word);
    std::string word;
    int count{0};

    // Read word by word (operator>> strips whitespace automatically)
    while (input_file >> word) {
        std::string clean_word = to_lower(word);

        // Check if target substring exists within the current file word
        if (clean_word.find(clean_target) != std::string::npos) {
            count++;
        }
    }

    return count;
}