#include <iostream>
#include <map>
#include <set>
#include <string>

// ============================================================================
// Display Helpers for std::map and Nested std::map<Key, std::set<T>>
// ============================================================================
template <typename K, typename V>
void display(const std::map<K, V>& m) {
    std::cout << "[ ";
    // C++17/20 structured binding unpacks pair.first and pair.second cleanly
    for (const auto& [key, value] : m) {
        std::cout << key << ":" << value << " ";
    }
    std::cout << "]" << std::endl;
}

void display(const std::map<std::string, std::set<int>>& m) {
    std::cout << "[ ";
    for (const auto& [student, grades] : m) {
        std::cout << student << ": [ ";
        for (const auto& grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Basic std::map Operations, Subscript Trap & O(log N) Lookups
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Basic std::map Operations ------------------------" << std::endl;

    std::map<std::string, int> m{
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m); // Automatically sorted by key: Curly:2, Larry:3, Moe:1

    // Different ways to insert key-value pairs
    m.insert(std::pair<std::string, int>("Anna", 10));
    m.insert(std::make_pair("Joe", 5));
    m.emplace("Groucho", 7);

    // Subscript operator []: inserts if missing, updates if present
    m["Frank"] = 18;
    display(m);

    m["Frank"] += 10; // Updates Frank to 28
    display(m);

    m.erase("Frank");
    display(m);

    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    // C++20 .contains() provides clean boolean membership check without iterator boilerplate
    if (m.contains("Larry")) {
        std::cout << "C++20 check: Larry is in the map" << std::endl;
    }

    // Prefer .find() over [] when reading unknown keys to avoid accidental default-insertion
    auto it = m.find("Larry");
    if (it != m.end()) {
        std::cout << "Found via iterator: " << it->first << " : " << it->second << std::endl;
    }

    m.clear();
    display(m);
}

// ============================================================================
// Test 2: Nested Associative Containers (std::map + std::set)
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: Nested std::map<std::string, std::set<int>> ------" << std::endl;

    std::map<std::string, std::set<int>> grades{
        {"Larry", {100, 90}},
        {"Moe",   {94}},
        {"Curly", {80, 90, 100}}
    };
    display(grades);

    // Operator [] returns a reference to Larry's std::set<int>, allowing direct .insert()
    grades["Larry"].insert(95);
    display(grades);

    // Safe lookup before mutating an existing entry
    auto it = grades.find("Moe");
    if (it != grades.end()) {
        it->second.insert(1000); // it->first is "Moe", it->second is Moe's std::set<int>
    }
    display(grades);
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: STD::MAP <<<" << std::endl;

    test1();
    test2();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}