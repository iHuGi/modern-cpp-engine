#include <iostream>
#include <compare> // Required for the C++20 Spaceship operator (<=>)

using namespace std;

int main() {
    // Enables boolean values to print as "true" or "false" instead of "1" or "0"
    cout << boolalpha; 

    // =======================================================
    // 1. ASSIGNMENT OPERATORS
    // =======================================================
    cout << "--- 1. ASSIGNMENT OPERATIONS ---" << endl;
    
    int active_users {10};
    int max_capacity {20};

    active_users = 100;
    max_capacity = 200;
    
    // The compiler evaluates this from right to left. 
    // First, max_capacity becomes 300, then active_users adopts that same value.
    active_users = max_capacity = 300; 

    cout << "Active Users: " << active_users << endl;
    cout << "Max Capacity: " << max_capacity << "\n\n";

    // =======================================================
    // 2. ARITHMETIC & COMPOUND OPERATORS
    // =======================================================
    cout << "--- 2. ARITHMETIC OPERATIONS ---" << endl;
    
    int base_score = 150;
    int bonus_points = 25;

    // Standard arithmetic operations using [[maybe_unused]]
    // This C++17/20 attribute explicitly tells the compiler: "I know I am not printing
    // or using this variable right now. Keep the terminal warnings silent."
    [[maybe_unused]] int total_score = base_score + bonus_points;
    [[maybe_unused]] int score_difference = base_score - bonus_points;
    [[maybe_unused]] int point_multiplier = base_score * 2;
    [[maybe_unused]] int level_division = base_score / 10;
    [[maybe_unused]] int leftover_points = base_score % 7; 

    cout << "Math operations processed silently in memory.\n" << endl;

    // Compound assignment operators (Cleaner and more standard in production code)
    int player_health = 100;
    player_health += 50;  // Equivalent to: player_health = player_health + 50
    player_health -= 20;  // Takes damage
    player_health *= 2;   // Health boost
    player_health /= 5;   // Poison debuff

    cout << "Final Player Health: " << player_health << "\n\n";

    // =======================================================
    // 3. INCREMENT & DECREMENT OPERATORS
    // =======================================================
    // Engineering Note: Prefix (++var) is generally preferred over Postfix (var++) 
    // in loops. Postfix requires the system to create a temporary copy of the 
    // variable in memory before incrementing, which adds unnecessary overhead.
    // Prefix increments the variable directly in place.
    // =======================================================
    cout << "--- 3. INCREMENT / DECREMENT ---" << endl;

    cout << "System Boot Sequence (Prefix Increment):" << endl;
    for (int boot_step = 0; boot_step <= 5; ++boot_step) { 
        cout << "Step " << boot_step << "... ";
    }
    cout << "\n\n";

    // =======================================================
    // 4. MIXED EXPRESSIONS & CASTING
    // =======================================================
    cout << "--- 4. DATA CONVERSION (CASTING) ---" << endl;
    
    int data_point_1, data_point_2, data_point_3;
    const int total_sensors {3};

    cout << "Enter three integer data points separated by spaces: ";
    cin >> data_point_1 >> data_point_2 >> data_point_3;

    int total_data_sum = data_point_1 + data_point_2 + data_point_3;
    
    // static_cast forces the integer sum into a double before division occurs.
    // Without this, the compiler would perform integer division and lose the decimals.
    double data_average = static_cast<double>(total_data_sum) / total_sensors;

    cout << "Sum of inputs: " << total_data_sum << endl;
    cout << "Precise Average: " << data_average << "\n\n";

    // =======================================================
    // 5. EQUALITY & RELATIONAL OPERATORS
    // =======================================================
    cout << "--- 5. RELATIONAL CHECKS ---" << endl;

    int system_limit {100};
    int current_load {0};

    cout << "Enter current system load (integer): ";
    cin >> current_load;

    // Equality checks
    cout << "Is system load exactly at limit? " << (current_load == system_limit) << endl;
    cout << "Is system load different from limit? " << (current_load != system_limit) << endl;

    // Relational checks
    cout << "Is load strictly greater than limit? " << (current_load > system_limit) << endl;
    cout << "Is load greater or equal to limit? " << (current_load >= system_limit) << endl;
    cout << "Is load strictly less than limit? " << (current_load < system_limit) << endl;
    cout << "Is load less or equal to limit? " << (current_load <= system_limit) << endl;

    // The C++20 "Spaceship" Operator (<=>)
    // Returns < 0 if left is smaller, 0 if equal, and > 0 if left is larger.
    auto comparison_result = (current_load <=> system_limit);
    if (comparison_result < 0) cout << "Status: Load is under capacity." << endl;
    if (comparison_result == 0) cout << "Status: Load is exactly at maximum capacity." << endl;
    if (comparison_result > 0) cout << "Status: WARNING - Capacity Exceeded!" << endl;
    cout << "\n";

    // =======================================================
    // 6. LOGICAL OPERATORS
    // =======================================================
    cout << "--- 6. LOGICAL GATES (AND, OR, NOT) ---" << endl;

    bool has_admin_rights = true;
    bool has_valid_token = false;
    bool is_banned = false;

    // Logical AND (&&) - Both sides must be true
    bool can_access_server = (has_admin_rights && has_valid_token);
    cout << "Access requested (AND constraint): " << can_access_server << endl;

    // Logical OR (||) - At least one side must be true
    bool bypass_active = (has_admin_rights || has_valid_token);
    cout << "Bypass requested (OR constraint): " << bypass_active << endl;

    // Logical NOT (!) - Inverts the boolean value
    bool is_account_active = !is_banned;
    cout << "Is account safe from ban? (NOT constraint): " << is_account_active << endl;

    cout << "\n=========================================" << endl;

    // =======================================================
    // 7. COMPOUND ASSIGNMENT & PRECEDENCE OVERVIEW
    // =======================================================
    cout << "--- 7. COMPOUND ASSIGNMENT & PRECEDENCE ---" << endl;

    // Compound assignments are shorthand for arithmetic operations.
    int buffer_size {0};
    buffer_size += 100; 
    cout << "Buffer size after compound addition: " << buffer_size << endl;

    // Precedence: C++ follows standard mathematical rules (PEMDAS).
    // Multiplication (*) is always evaluated before Addition (+).
    int x = 10, y = 5, z = 2;
    
    int standard_result = x + y * z;         // 10 + (5 * 2) = 20
    int parenthesized_result = (x + y) * z;  // (10 + 5) * 2 = 30

    cout << "Standard Precedence (10 + 5 * 2): " << standard_result << endl;
    cout << "Explicit Precedence ((10 + 5) * 2): " << parenthesized_result << endl;
    
    // Engineering Tip: When in doubt, always use parentheses.

    cout << "\n=========================================" << endl;

    return 0;
}