#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cctype>   // Required for std::isalpha and std::toupper
#include <iomanip>  // Required for std::setw and std::left

// ============================================================================
// Palindrome Checker using std::deque
// Ignores non-alphabetic characters and case sensitivity.
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================
bool is_palindrome(const std::string& str) {
    std::deque<char> dq;

    // 1. Filter only alphabetic characters and normalize to uppercase (O(1) per push)
    for (char c : str) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            dq.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
        }
    }

    // 2. Compare front and back characters moving inward (O(1) per pop/access)
    while (dq.size() > 1) {
        char front = dq.front();
        char back = dq.back();
        dq.pop_front();
        dq.pop_back();

        if (front != back) {
            return false; // Early exit on first mismatch
        }
    }

    return true;
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: CHALLENGE 1 (PALINDROME) <<<\n" << std::endl;

    std::vector<std::string> test_strings{
        "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "This is a palindrome", "palindrome"
    };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}