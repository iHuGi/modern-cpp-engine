#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator> // Required for std::advance and std::distance
#include <string>

// ============================================================================
// Custom Class for STL Container Testing
// ============================================================================
class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) : name{name}, age{age} {}

    // Required by std::list::sort()
    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }

    // Required by std::find() and std::list::remove()
    bool operator==(const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << ":" << p.age;
    return os;
}

// ============================================================================
// Generic Template Helper to Display Any Sequence Container
// Works seamlessly for both std::list and std::forward_list
// ============================================================================
template <typename Container>
void display(const Container& c) {
    std::cout << "[ ";
    for (const auto& elem : c) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

// ============================================================================
// Test 1: Basic std::list Operations (push_back, push_front, front, back)
// ============================================================================
void test1() {
    std::cout << "\n--- Test 1: Basic std::list Operations -----------------------" << std::endl;

    std::list<int> l1{1, 2, 3, 4, 5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l3);

    std::list<int> l4(10, 100); // 10 elements initialized to 100
    display(l4);
}

// ============================================================================
// Test 2: Sizing and Resizing (size, front, back, clear, resize)
// ============================================================================
void test2() {
    std::cout << "\n--- Test 2: Size, Clear, and Resize --------------------------" << std::endl;

    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
    std::cout << "Front: " << l.front() << std::endl;
    std::cout << "Back: " << l.back() << std::endl;

    l.clear();
    display(l);
    std::cout << "Size after clear: " << l.size() << std::endl;

    l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l.resize(5); // Truncates remaining nodes (deallocates them)
    display(l);

    l.resize(10); // Appends 5 default-initialized (0) nodes
    display(l);

    std::list<Person> persons;
    persons.resize(5); // Uses Person default constructor ("Unknown":0)
    display(persons);
}

// ============================================================================
// Test 3: O(1) Node Insertion & Bidirectional Iterator Navigation
// ============================================================================
void test3() {
    std::cout << "\n--- Test 3: Insert, Erase, and Iterator Navigation -----------" << std::endl;

    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    // Find '5' in O(N) time, then insert '100' before it in O(1) time
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end()) {
        l.insert(it, 100);
    }
    display(l);

    // Insert an entire secondary list before '5' (note: 'it' is still valid!)
    std::list<int> l2{1000, 2000, 3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);

    // Move iterator 4 positions backward using std::advance (Bidirectional Iterator)
    std::advance(it, -4); // Now points to 100
    std::cout << "Iterator after std::advance(it, -4): " << *it << std::endl;

    // Erase node '100' in O(1) time (invalidates only 'it', other iterators remain intact)
    l.erase(it);
    display(l);
}

// ============================================================================
// Test 4: Custom Objects & In-Place Node Construction (emplace)
// ============================================================================
void test4() {
    std::cout << "\n--- Test 4: In-Place Node Construction (emplace) -------------" << std::endl;

    std::list<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    display(stooges);

    std::string name{"Frank"};
    int age{42};
    stooges.emplace_back(name, age); // Constructs Person directly inside the new heap node
    display(stooges);

    // Find "Moe" and emplace "Darth" directly before him
    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end()) {
        stooges.emplace(it, "Darth", 50);
    }
    display(stooges);
}

// ============================================================================
// Test 5: Container-Specific Sorting (l.sort() relinks pointers in-place)
// ============================================================================
void test5() {
    std::cout << "\n--- Test 5: Member Function .sort() --------------------------" << std::endl;

    std::list<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };

    display(stooges);
    // std::sort(stooges.begin(), stooges.end()); // ERROR: Requires Random Access Iterators!
    stooges.sort(); // Uses Person::operator< and relinks node pointers directly
    display(stooges);
}

// ============================================================================
// Test 6: std::forward_list (Singly-Linked List - Forward Iterators Only)
// ============================================================================
void test6() {
    std::cout << "\n--- Test 6: std::forward_list (Singly-Linked List) -----------" << std::endl;

    std::forward_list<int> fl{1, 2, 3, 4, 5};
    display(fl);

    // Note: fl.size() does NOT exist in std::forward_list to minimize memory overhead.
    // Use std::distance() if element count is strictly required:
    std::cout << "Calculated size via std::distance: " << std::distance(fl.begin(), fl.end()) << std::endl;
    std::cout << "Front element: " << fl.front() << std::endl;

    fl.push_front(0);
    fl.emplace_front(-1);
    display(fl);

    fl.pop_front();
    display(fl);

    // Insertions and deletions happen AFTER the target iterator
    auto it = std::find(fl.begin(), fl.end(), 3);
    if (it != fl.end()) {
        fl.insert_after(it, 100);          // Inserts 100 after 3
        fl.emplace_after(it, 200);         // Inserts 200 after 3 (before 100)
        fl.erase_after(it);                // Erases the node immediately after 3 (which is 200)
    }
    display(fl);

    fl.resize(3);
    display(fl);

    fl.resize(6, 99); // Appends 99 for new nodes
    display(fl);
}

// ============================================================================
// Main Execution
// ============================================================================
int main() {
    std::cout << "\n>>> SECTION 20: STD::LIST & STD::FORWARD_LIST <<<" << std::endl;

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}