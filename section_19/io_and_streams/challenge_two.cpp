#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <iomanip>

// =====================================
// Function Prototypes
// =====================================
void read_file(std::string_view filename);
void print_header();
void print_footer(double average);
void print_student(const std::string &student, int score);
int process_response(const std::string &response, const std::string &answer_key);

int main() {
    constexpr std::string_view target_file = "responses.txt";

    std::cout << "\n>>> CHALLENGE 2 - AUTOMATED QUIZ GRADER <<<\n" << std::endl;

    read_file(target_file);

    std::cout << "\n>>> QUIZ GRADING COMPLETE <<<\n" << std::endl;
    return 0;
}

// =====================================
// Function Definitions
// =====================================
void read_file(std::string_view filename) {
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};

    std::ifstream input_file{std::string(filename)};

    // Check if opened correctly
    if (!input_file) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return;
    }

    std::string answer_key;
    if (!(input_file >> answer_key)) {
        std::cerr << "Error: File is empty or answer key missing." << std::endl;
        return;
    }

    print_header();

    std::string name;
    std::string response;

    while (input_file >> name >> response) {
        ++total_students;
        int score = process_response(response, answer_key);
        running_sum += score;
        print_student(name, score);
    }

    if (total_students != 0) {
        average_score = static_cast<double>(running_sum) / total_students;
    }

    print_footer(average_score);
}

void print_header() {
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(5) << std::right << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average) {
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << "Average score"
              << std::setw(5) << std::right << average << std::endl;

    // Reset streams state (Best Practice)
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);
}

void print_student(const std::string &student, int score) {
    std::cout << std::setw(15) << std::left << student
              << std::setw(5) << std::right << score << std::endl;
}

// Return the number of correct responses
int process_response(const std::string &response, const std::string &answer_key) {
    int score {0};
    for (size_t i = 0; i < answer_key.size() && i < response.size(); ++i) {
        if (response.at(i) == answer_key.at(i))
            score++;
    }
    return score;
}