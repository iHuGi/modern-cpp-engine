#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cctype>

// ============================================================================
// Helper: Strip punctuation characters safely (prevents "Oz." != "Oz")
// ============================================================================
std::string clean_string(const std::string& s) {
    std::string result;
    for (char c : s) {
        if (!std::ispunct(static_cast<unsigned char>(c))) {
            result += c;
        }
    }
    return result;
}

// ============================================================================
// Display Helpers
// ============================================================================
void display_word_counts(const std::map<std::string, int>& words) {
    std::cout << "\n========================================\n"
              << std::setw(22) << std::left << "Word"
              << std::setw(10) << std::right << "Count\n"
              << "========================================\n";

    for (const auto& [word, count] : words) {
        std::cout << std::setw(22) << std::left << word
                  << std::setw(10) << std::right << count << '\n';
    }
    std::cout << "========================================\n";
}

void display_word_occurrences(const std::map<std::string, std::set<int>>& words) {
    std::cout << "\n========================================================\n"
              << std::setw(22) << std::left << "Word"
              << "Occurrences (Line Numbers)\n"
              << "========================================================\n";

    for (const auto& [word, lines] : words) {
        std::cout << std::setw(22) << std::left << word << "[ ";
        for (int line_num : lines) {
            std::cout << line_num << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "========================================================\n";
}

// ============================================================================
// Part 1: Count total occurrences of each unique word
// ============================================================================
void part1(const std::string& filename) {
    std::ifstream in_file{filename};
    if (!in_file) {
        std::cerr << "[!] Error: Could not open '" << filename << "'.\n";
        return;
    }

    std::map<std::string, int> words;
    std::string raw_word;

    while (in_file >> raw_word) {
        std::string word = clean_string(raw_word);
        if (!word.empty()) {
            words[word]++; // Auto-inserts with 0 if new, then increments
        }
    }

    display_word_counts(words);
}

// ============================================================================
// Part 2: Track exact line numbers where each word appears (std::set<int>)
// ============================================================================
void part2(const std::string& filename) {
    std::ifstream in_file{filename};
    if (!in_file) {
        std::cerr << "[!] Error: Could not open '" << filename << "'.\n";
        return;
    }

    std::map<std::string, std::set<int>> words;
    std::string line;
    int line_number{0};

    // Read line-by-line so we know the exact line index
    while (std::getline(in_file, line)) {
        ++line_number;
        std::istringstream iss{line};
        std::string raw_word;

        // Extract individual words from the current line
        while (iss >> raw_word) {
            std::string word = clean_string(raw_word);
            if (!word.empty()) {
                // operator[] returns a reference to the word's std::set<int>
                words[word].insert(line_number);
            }
        }
    }

    display_word_occurrences(words);
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    const std::string filename{"words.txt"};

    std::cout << "\n>>> SECTION 20: CHALLENGE 3 (WORD COUNT & LINE INDEXER) <<<\n";
    part1(filename);
    part2(filename);

    return 0;
}