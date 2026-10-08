#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::cout << "\n>>> SECTION 19: STRING STREAMS DEMO <<<\n" << std::endl;

    // 1. Formatting data into a string (ostringstream)
    std::ostringstream oss;
    std::string name{"Hugo"};
    int id{42};
    double balance{1250.758};

    // Format output with manipulators directly into memory stream
    oss << "User: " << name
        << " | ID: " << std::setw(5) << std::setfill('0') << id
        << " | Balance: $" << std::fixed << std::setprecision(2) << balance;

    // Convert the stream buffer to an actual std::string
    std::string formatted_str = oss.str();
    std::cout << "Formatted Stream Output:\n" << formatted_str << "\n\n";

    // 2. Parsing typed data from a string (istringstream)
    std::string raw_csv_line{"101 Admin 999.99"};
    std::istringstream iss{raw_csv_line};

    int user_id;
    std::string role;
    double salary;

    // Operator>> automatically extracts tokens, skips whitespace, and converts types
    if (iss >> user_id >> role >> salary) {
        std::cout << "Parsed Data from String:\n";
        std::cout << "ID: " << user_id << "\n";
        std::cout << "Role: " << role << "\n";
        std::cout << "Salary: " << salary << "\n";
    }

    std::cout << "\n>>> DEMO FINISHED <<<\n" << std::endl;
    return 0;
}