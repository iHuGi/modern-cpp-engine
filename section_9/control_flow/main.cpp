#include <iostream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    // =======================================================
    // 1. IF STATEMENTS & INPUT VALIDATION
    // =======================================================
    cout << "--- 1. SECURE INPUT VALIDATION (IF ONLY) ---" << endl;

    int num {};
    const int min {10};
    const int max {100};

    while (true) {
        cout << "Enter a number between " << min << " and " << max << ": ";
        cin >> num;

        if (cin.fail()) {
            cout << ">> ERROR: Invalid data type. Please enter numerical digits only.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (num < min || num > max) {
            cout << ">> ERROR: " << num << " is out of bounds. Try again.\n" << endl;
            continue;
        }
        
        cout << "\n>> SUCCESS: Your number (" << num << ") has been accepted.\n" << endl;
        break;
    }

    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 2. CONDITIONAL BRANCHING (IF-ELSE)
    // =======================================================
    cout << "--- 2. CONDITIONAL BRANCHING (IF-ELSE) ---" << endl;

    int num_v2 {};
    const int min_v2 {50};
    const int max_v2 {500};

    while (true) {
        cout << "Enter a number to check if it is within [" << min_v2 << " - " << max_v2 << "]: ";
        cin >> num_v2;

        if (cin.fail()) {
            cout << ">> ERROR: Invalid data type. Please enter numerical digits only.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (num_v2 >= min_v2 && num_v2 <= max_v2) {
            cout << ">> STATUS: VALID. Your number (" << num_v2 << ") is within the acceptable range.\n";
        } else {
            cout << ">> STATUS: OUT OF BOUNDS. Your number (" << num_v2 << ") is NOT in the acceptable range.\n";
        }

        cout << "\n>> SYSTEM: Program executed successfully. Exiting loop...\n";
        break;
    }
    
    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 3. STRICT NESTED IF STATEMENTS (WITH ESCAPE LOGIC)
    // =======================================================

    cout << "--- 3. COMBAT SIMULATOR (STRICT NESTED IF) ---" << endl;
    
    int player_health {100};
    int damage_done {0};
    bool player_hit {false};
    
    vector<string> hit_types {"snake", "rat", "dog", "lion", "gorilla"};

    for (string enemy : hit_types) {
        cout << "\n>> A wild " << enemy << " appears!" << endl;

        if (enemy == "snake" || enemy == "rat" || enemy == "lion") {
            player_hit = true;

            if (enemy == "snake") {
                damage_done = 50;
            }
            if (enemy == "rat") {
                damage_done = 10;
            }
            if (enemy == "lion") {
                damage_done = 80;
            }

            player_health -= damage_done;
            cout << "The " << enemy << " attacks! You took " << damage_done << " damage.\n";

            if (player_health > 0) {
                cout << "Current Health: " << player_health << "\n";
            }

            if (player_health <= 0) {
                cout << "Current Health: 0\n";
                cout << "\n>> SYSTEM: PLAYER DIED. GAME OVER.\n";
                break;
            }
        }

        if (enemy == "dog" || enemy == "gorilla") {
            player_hit = false;
            cout << "The " << enemy << " stares at you and walks away.\n";
            
            cout << "\n>> SYSTEM: You took the opportunity to flee the jungle. YOU SURVIVED!\n";
            break;
        }

        if (player_hit) {
            cout << ">> ADVICE: Be careful next time.\n";
        }
    }

    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 4. SWITCH CASE STATEMENT
    // =======================================================
    
   cout << "--- 4. SWITCH CASE STATEMENT ---" << endl;
    
    char letter_grade {};
    bool is_valid_grade {false};

    while (!is_valid_grade) {
        
        cout << "Enter a letter grade (A, B, C, D, F): ";
        cin >> letter_grade;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!isalpha(letter_grade)) {
            cout << ">> ERROR: Invalid data type. Please enter alphabetic characters only.\n" << endl;
            continue;
        }

        switch (letter_grade) {
            case 'a':
            case 'A':
                cout << ">> You need 90-100 points to get an A." << endl;
                is_valid_grade = true;
                break;
                
            case 'b':
            case 'B':
                cout << ">> You need 80-89 points to get a B." << endl;
                is_valid_grade = true;
                break;
                
            case 'c':
            case 'C':
                cout << ">> You need 70-79 points to get a C." << endl;
                is_valid_grade = true;
                break;
                
            case 'd':
            case 'D':
                cout << ">> You need 60-69 points to get a D, please study more." << endl;
                is_valid_grade = true;
                break;
                
            case 'f':
            case 'F': {
                char confirm {};
                cout << ">> Are you sure you want to get an F? (Y/N): ";
                cin >> confirm;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (confirm == 'y' || confirm == 'Y') {
                    cout << ">> OK, maybe I will need to talk with your parents.\n" << endl;
                    is_valid_grade = true;
                } else if (confirm == 'n' || confirm == 'N') {
                    cout << ">> Good! You would need 0-59 points to get an F, please avoid this grade." << endl;
                    is_valid_grade = true;
                } else {
                    cout << ">> ERROR: Invalid confirmation input. Please enter Y or N.\n" << endl;
                }
                break;
            }
                
            default:
                cout << ">> ERROR: Unrecognized grade. Please enter A, B, C, D, or F.\n" << endl;
                break;
        }
    }

    cout << "\n=======================================" << endl;

    // =======================================================
    // 5. CONDITIONAL OPERATOR (TERNARY)
    // =======================================================

    cout << "--- 5. CONDITIONAL OPERATOR (TERNARY) ---" << endl;

    int num1 {10};
    int num2 {25};

    int max_val = (num1 > num2) ? num1 : num2;

    cout << "The maximum value is: " << max_val << endl;
    cout << "Are the numbers equal? " << ((num1 == num2) ? "YES" : "NO") << endl;

    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 6. FOR LOOP
    // =======================================================

    cout << "--- 6. FOR LOOP ---" << endl;

    int total_iterations {100}; 
    vector<int> odds {};
    vector<int> evens {};

    for (int i = 1; i <= total_iterations; ++i) {
        if (i % 2 == 0) {
            evens.push_back(i);
        } else {
            odds.push_back(i);
        }
    }

    cout << ">> STATS: Found " << evens.size() << " Even numbers and " << odds.size() << " Odd numbers.\n" << endl;

    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 7. RANGE-BASED FOR LOOP
    // =======================================================

    cout << "--- 7. RANGE-BASED FOR LOOP ---" << endl;

    cout << ">> EVENS: ";
    for (int even : evens) {
        cout << even << " ";
    }
    
    cout << "\n\n>> ODDS:  ";
    for (int odd : odds) {
        cout << odd << " ";
    }
    
    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 8. WHILE LOOP
    // =======================================================

    cout << "--- 8. WHILE LOOP ---" << endl;

    bool is_done {false};
    char command {};

    while(!is_done) {
        cout << "\n>> SYSTEM RUNNING. Enter a command ('R' to report, 'Q' to quit): ";
        cin >> command;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (command == 'r' || command == 'R') {
            cout << ">> SYSTEM REPORT: All processes operational." << endl;
            
        } else if (command == 'q' || command == 'Q') {
            cout << ">> SYSTEM: Shutting down safely..." << endl;
            is_done = true;
            
        } else {
            cout << ">> ERROR: Unknown command. System remains active." << endl;
        }
    }

    cout << "\n>> SYSTEM OFFLINE." << endl;
    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 9. DO-WHILE LOOP
    // =======================================================

    cout << "--- 9. DO-WHILE LOOP ---" << endl;

    char selection {};

    do {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Print Hello" << endl;
        cout << "2. Print Goodbye" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your selection: ";
        cin >> selection;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (selection == '1') {
            cout << ">> Hello there!" << endl;
        } else if (selection == '2') {
            cout << ">> Catch you later!" << endl;
        } else if (selection != '3') {
            cout << ">> ERROR: Unknown option. Please try again." << endl;
        }

    } while (selection != '3');

    cout << "\n>> SYSTEM: Menu exited successfully." << endl;
    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 10. CONTINUE AND BREAK STATEMENTS
    // =======================================================

    cout << "--- 10. CONTINUE AND BREAK STATEMENTS ---" << endl;

    vector<int> numbers {1, 2, 3, 4, 5, -99, 7, 8, 9, 10};

    for (int num : numbers) {
        if (num == -99) {
            cout << ">> CRITICAL ERROR: Corrupted data (-99) detected. Aborting loop..." << endl;
            break;
        }

        if (num % 2 == 0) {
            cout << ">> INFO: Skipping even number: " << num << endl;
            continue;
        }

        cout << ">> SUCCESS: Processing odd number: " << num << endl;
    }

        cout << "\n\n=======================================" << endl;

    // =======================================================
    // 11. INFINITE LOOPS
    // =======================================================

    cout << "--- 11. INFINITE LOOPS ---" << endl;

    cout << ">> WARNING: Initiating infinite loop..." << endl;
    cout << ">> (In C++, 'for (;;)' is the classic way to run a process forever!)" << endl;

    char kill_switch {};

    for (;;) {
        cout << "\n>> [BACKGROUND PROCESS ACTIVE] ... Press 'K' to kill: ";
        cin >> kill_switch;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (kill_switch == 'k' || kill_switch == 'K') {
            cout << ">> SYSTEM: Kill switch engaged. Shattering the infinite loop..." << endl;
            break;
        }
        
        cout << ">> SYSTEM: Invalid input. Process continues to run..." << endl;
    }

    cout << "\n\n=======================================" << endl;

    // =======================================================
    // 12. NESTED LOOPS
    // =======================================================

    cout << "--- 12. NESTED LOOPS ---" << endl;

    vector<vector<string>> primeira_liga_database {
        // Season | Position | Team | Cash/Revenue (EUR) | Prior Year Position
        {"2023/24", "1st", "Sporting CP", "101,500,000", "4th"},
        {"2023/24", "2nd", "SL Benfica",  "179,000,000", "1st"},
        {"2023/24", "3rd", "FC Porto",    "174,500,000", "2nd"},
        
        {"2022/23", "1st", "SL Benfica",  "195,000,000", "3rd"},
        {"2022/23", "2nd", "FC Porto",    "165,000,000", "1st"},
        {"2022/23", "3rd", "SC Braga",    "53,200,000",  "4th"},
        
        {"2021/22", "1st", "FC Porto",    "144,000,000", "2nd"},
        {"2021/22", "2nd", "Sporting CP", "120,000,000", "1st"},
        {"2021/22", "3rd", "SL Benfica",  "105,000,000", "3rd"},
        
        {"2020/21", "1st", "Sporting CP", "85,000,000",  "4th"},
        {"2020/21", "2nd", "FC Porto",    "153,000,000", "1st"},
        {"2020/21", "3rd", "SL Benfica",  "98,000,000",  "2nd"}
    };

    cout << "Season  | Pos | Team        | Est. Revenue  | Prior Year\n";
    cout << "---------------------------------------------------------\n";

    for (size_t row = 0; row < primeira_liga_database.size(); ++row) {
        for (size_t col = 0; col < primeira_liga_database.at(row).size(); ++col) {
            cout << primeira_liga_database.at(row).at(col) << " | ";
        }
        
        cout << endl;
    }

    cout << "\n\n=======================================" << endl;

    return 0;
}