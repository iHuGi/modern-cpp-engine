#include <iostream>
#include <string>
#include <cmath>    // Required for math functions (sqrt, pow, round, sin, etc.)
#include <numbers>  // Required for C++20 math constants like std::numbers::pi
#include <cstdlib>  // Required for random number generation (rand, srand)
#include <ctime>    // Required for time() to seed the random generator
#include <vector>   // Required for using std::vector

using namespace std;

const double pi = std::numbers::pi; // C++20 constant for Pi
int global_counter = 100; // Global Variable for SCOPE RULES lesson

// FUNCTION PROTOTYPES
double calculate_circle_area_v2(double radius);
double calculate_cylinder_volume_v2(double radius, double height);
void circle_area();
void cylinder_volume();
void run_market_simulation(double savings_balance, double property_cost); // PART OF FUNCTION PARAMETERS LESSON
double calc_cost(double base_cost, double tax_rate = 0.05, double shipping = 5.00); // PART OF DEFAULT ARGUMENT VALUES LESSON
void run_market_simulation(double savings_balance, double monthly_savings, int months_to_save); // PART OF FUNCTION OVERLOADING LESSON
void print_guest_list(vector<string> guest_list); // PART OF PASSING ARRAYS TO FUNCTIONS LESSON
void print_guest_list(string guest_array[], size_t size); // PART OF PASSING ARRAYS TO FUNCTIONS LESSON
void print_guest_list_ref(const vector<string>& guest_list); // PART OF PASSING BY REFERENCE LESSON
void demo_global(); // PART OF SCOPE RULES LESSON
void demo_static(); // PART OF SCOPE RULES LESSON
void demo_local(int local_val); // PART OF SCOPE RULES LESSON
void recursive_counter(int current, int max_limit); // PART OF RECURSIVE FUNCTIONS LESSON
// END OF FUNCTRION PROTOTYPES

double calculate_circle_area(double radius) {
        return pi * pow(radius, 2);
    }

double calculate_cylinder_volume(double radius, double height) {
        return pi * pow(radius, 2) * height;
}

void circle_area() {
    double radius;

    while (true) {
        cout << "Enter the radius of the circle: ";
        
        if (!(cin >> radius)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid radius. Please enter a number." << endl;
            continue;
        }

        if (radius > 0) {
            break;
        } else {
            cout << "Radius must be positive!" << endl;
        }
    }

    double area = calculate_circle_area(radius);
    cout << "The area of the circle with radius " << radius << " is: " << area << endl;
}

void cylinder_volume() {
    double radius, height;
    
    while (true) {
        cout << "Enter the radius of the cylinder: ";
        if (!(cin >> radius)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid radius. Please enter a number." << endl;
            continue;
        }
        
        cout << "Enter the height of the cylinder: ";
        if (!(cin >> height)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid height. Please enter a number." << endl;
            continue;
        }

        if (radius > 0 && height > 0) {
            break;
        } else {
            cout << "Dimensions must be positive!" << endl;
        }
    }

    double volume = calculate_cylinder_volume(radius, height);
    cout << "The volume of the cylinder with radius " << radius << " and height " << height << " is: " << volume << endl;
}

int main() {
    cout << "========================================\n";
    cout << "      C++ BUILT-IN FUNCTIONS STUDY      \n";
    cout << "========================================\n\n";

    // ----------------------------------------
    // 1. MATH FUNCTIONS
    // ----------------------------------------
    cout << "--- 1. MATH FUNCTIONS ---\n";
    double num = 125.5;
    
    cout << "The square root of " << num << " is: " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;

    // pow(base, exponent) -> Useful for calculations where we need an exact power
    cout << "2 to the power of 3 (2^3) using pow() is: " << pow(2, 3) << endl;

    // ----------------------------------------
    // 2. ROUNDING FUNCTIONS
    // ----------------------------------------
    cout << "\n--- 2. ROUNDING ---\n";
    double decimal_num = 7.7;
    cout << "Original number: " << decimal_num << endl;
    
    // round(): Standard rounding. .5 and up goes up, .4 and down goes down.
    cout << "round() (Nearest whole): " << round(decimal_num) << endl;
    
    // ceil(): "Ceiling". ALWAYS forces the decimal up to the next whole number.
    cout << "ceil()  (Forces UP)    : " << ceil(decimal_num) << endl;
    
    // floor(): "Floor". ALWAYS chops off the decimal and forces it down.
    cout << "floor() (Forces DOWN)  : " << floor(decimal_num) << endl;

    // ----------------------------------------
    // 3. TRIGONOMETRY (Requires Radians)
    // ----------------------------------------
    cout << "\n--- 3. TRIGONOMETRY ---\n";
    double degrees = 90.0;
    
    // TRAP WARNING: C++ trig functions do NOT accept degrees. They take radians.
    // Formula to convert Degrees to Radians: degrees * (Pi / 180)
    double radians = degrees * (std::numbers::pi / 180.0);

    cout << "Angle in degrees: " << degrees << endl;
    cout << "sin() of 90 degrees: " << sin(radians) << endl;
    cout << "cos() of 90 degrees: " << cos(radians) << endl;

    // ----------------------------------------
    // 4. RANDOM NUMBERS
    // ----------------------------------------
    cout << "\n--- 4. RANDOM NUMBERS ---\n";
    
    // Step 1: "Seed" the generator with the current system time. 
    // If we forget this, rand() will generate the exact same numbers every time we run the program!
    srand(time(nullptr));

    // Step 2: Use modulo (%) to set a specific range.
    // Example: Dice roll (1 to 6)
    // rand() % 6 gives a remainder of 0, 1, 2, 3, 4, or 5. 
    // Adding 1 shifts that range to exactly 1, 2, 3, 4, 5, or 6.
    int dice_roll = (rand() % 6) + 1;
    cout << "You rolled a dice and got: " << dice_roll << endl;

    // Example: Coin Flip (0 or 1)
    // rand() % 2 gives a remainder of exactly 0 or 1.
    int coin_flip = rand() % 2;
    
    if (coin_flip == 0) {
        cout << "Coin toss: Heads!" << endl;
    } else {
        cout << "Coin toss: Tails!" << endl;
    }

    // ----------------------------------------
    // 5. FUNCTION DEFINITION
    // ----------------------------------------
    cout << "\n--- 5. FUNCTION DEFINITION ---\n";

    cout << "Calculating the area of a circle using a function...\n";
    circle_area();

    cout << "\nCalculating the volume of a cylinder using a function...\n";
    cylinder_volume();

    // ----------------------------------------
    // 6. FUNCTION PROTOTYPES
    // ----------------------------------------
    cout << "\n--- 6. FUNCTION PROTOTYPES ---\n";
   
    cout << "Calculating the area of a circle using a function...\n";
    circle_area();

    cout << "\nCalculating the volume of a cylinder using a function...\n";
    cylinder_volume();

    // ----------------------------------------
    // 7. FUNCTION PARAMETERS
    // ----------------------------------------
    cout << "\n--- 7. FUNCTION PARAMETERS ---\n";
    
    // The Source of Truth
    double actual_savings = 65000.00;
    double target_property_cost = 45000.00; // Just the down payment/entry cost

    cout << "[MAIN] Current actual savings: " << actual_savings << " EUR\n" << endl;

    // We pass the variable BY VALUE.
    // C++ takes a photocopy of 'actual_savings' and hands it to the function.
    run_market_simulation(actual_savings, target_property_cost);

    // Proving the original variable is completely safe
    cout << "\n[MAIN] Simulation complete." << endl;
    cout << "[MAIN] Actual savings remaining: " << actual_savings << " EUR" << endl;
    cout << "[MAIN] The original value was never touched!" << endl;

    // ----------------------------------------
    // 8. DEFAULT ARGUMENT VALUES
    // ----------------------------------------
    cout << "\n--- 8. DEFAULT ARGUMENT VALUES ---\n";

    double cost1 = calc_cost(100.00); // Uses default values for tax_rate and shipping
    cout << "Total cost with default tax and shipping: " << cost1 << " EUR" << endl;

    double cost2 = calc_cost(100.00, 0.10); // Uses default value for shipping
    cout << "Total cost with 10% tax and default shipping: " << cost2 << " EUR" << endl;

    double cost3 = calc_cost(100.00, 0.10, 7.50); // Provides all parameter values
    cout << "Total cost with 10% tax and 7.50 EUR shipping: " << cost3 << " EUR" << endl;

    // ----------------------------------------
    // 9. FUNCTION OVERLOADING
    // ----------------------------------------
    cout << "\n--- 9. FUNCTION OVERLOADING ---\n";
    run_market_simulation(66000.50, 1250.50, 12);

    // ----------------------------------------
    // 10. PASSING ARRAYS TI FUNCTIONS
    // ----------------------------------------
    cout << "\n--- 10. PASSING ARRAYS/VECTORS TO FUNCTIONS ---\n";
    vector<string> guests_val = {"Hugo", "Pedro", "André", "Luís", "Rúben", "Filipe"}; // Passing a vector to a function
    print_guest_list(guests_val);

    string guests_array[] = {"Hugo", "Pedro", "André", "Luís", "Rúben", "Filipe"}; // Passing a C-style array to a function
    print_guest_list(guests_array, 6);

    // ----------------------------------------
    // 11. PASSING VALUES BY REFERENCE
    // ----------------------------------------
    cout << "\n--- 11. PASSING VALUES BY REFERENCE ---\n";
    vector<string> guests_ref = {"Hugo", "Pedro", "André", "Luís", "Rúben", "Filipe"}; // Passing a vector to a function by reference
    print_guest_list_ref(guests_ref);

    // ----------------------------------------
    // 12. SCOPE RULES
    // ----------------------------------------
    cout << "\n--- 12. SCOPE RULES ---\n";

    cout << "--- 1. GLOBAL SCOPE ---" << endl;
    // Modifies the exact same global variable in memory both times
    demo_global();
    demo_global();

    cout << "\n--- 2. STATIC SCOPE ---" << endl;
    // Remembers its value between calls, but is completely hidden from main()
    demo_static();
    demo_static();

    cout << "\n--- 3. LOCAL SCOPE (PARAMETER) ---" << endl;
    // Starts completely fresh every single time it is called
    int my_starting_value = 50;
    demo_local(my_starting_value);
    demo_local(my_starting_value);

    // ----------------------------------------
    // 13. FUNCTION CALLS (THE CALL STACK)
    // ----------------------------------------
    cout << "\n--- 13. FUNCTION CALLS ---\n";
    cout << "Read the commented out section in the source code to understand the Stack." << endl;

    /*
        ========================================================================
        [THEORY: THE CALL STACK & MEMORY]
        ========================================================================
        - The Mechanism: When main() calls a function, the OS pauses main() and
          "pushes" the new function's data (parameters, local variables, and the
          exact address to return to) onto a memory structure called the Call Stack.
          This block of data is called a "Stack Frame" or "Activation Record".
        
        - LIFO (Last-In, First-Out): The stack operates like a stack of plates.
          The last function called must be the first one to finish. If main()
          calls funcA(), and funcA() calls funcB(), funcB() must finish and be
          "popped" off the stack before funcA() can resume.
        
        - The Wipe: The millisecond a function hits its 'return' statement, its
          entire Stack Frame is instantly destroyed. All local variables vanish
          forever to free up that memory.
        
        - The Danger: The Stack is incredibly fast, but it is small (usually just
          a few megabytes). If you write a function that calls itself infinitely
          (runaway recursion), it will keep pushing frames until the memory runs
          out, causing a fatal crash. This is literally a "Stack Overflow".
        ========================================================================
    */

    // ----------------------------------------
    // 14. INLINE FUNCTIONS
    // ----------------------------------------
    cout << "\n--- 14. INLINE FUNCTIONS ---\n";
    cout << "Read the commented out section in the source code to understand Inlining." << endl;

    /*
        ========================================================================
        [THEORY: INLINE FUNCTIONS & COMPILER OPTIMIZATION]
        ========================================================================
        - The Problem: Jumping to a new function via the Call Stack takes a tiny
          fraction of CPU time (overhead). If you have a 'for' loop calling a
          very small function 10,000,000 times, that stack overhead ruins performance.
        
        - The 'inline' Keyword: You can suggest the compiler optimize this by
          declaring a function with the keyword: `inline int add(int a, int b);`
        
        - What it does: Instead of using the Call Stack, the compiler literally
          replaces the function call with the actual code from the function body
          during compilation. It's like a high-speed copy-paste. Zero stack overhead!
        
        - The Trade-off: It makes the program incredibly fast, but it increases the
          compiled binary (.exe) file size (code bloat).
        
        - Modern Reality: C++ compilers today (GCC, Clang, MSVC) are ruthlessly
          smart. They will often completely ignore your 'inline' keyword if they
          think it will hurt performance. Conversely, they will automatically inline
          regular functions on their own if they mathematically prove it is faster.
          Today, 'inline' is mostly used in Header (.h) files to prevent "Multiple
          Definition" linker errors, rather than strictly for performance.
        ========================================================================
    */

    // ----------------------------------------
    // 15. RECURSIVE FUNCTIONS
    // ----------------------------------------
    cout << "\n--- 15. RECURSIVE FUNCTIONS ---\n";
    cout << "Starting the recursive CTE... I mean, function!\n\n";
    // We start at 1, and our max limit is 10 (keeping it small for the console)
    recursive_counter(1, 10);

    return 0;
}

    // FUNCTION DEFINITIONS
    double calculate_circle_area_v2(double radius) {
        return pi * pow(radius, 2);
    }

    double calculate_cylinder_volume_v2(double radius, double height) {
        return pi * pow(radius, 2) * height;
    }

    void run_market_simulation(double savings_balance, double property_cost) {
        cout << "   -> [SIMULATION] Starting evaluation..." << endl;
    
        // This ONLY modifies the local photocopy inside this function's memory stack
        savings_balance -= property_cost;
    
        cout << "   -> [SIMULATION] If you execute this purchase, your new balance will drop to: "
            << savings_balance << " EUR" << endl;
    }

    // Default argument values allow us to call a function without providing all the parameters.
    double calc_cost(double base_cost, double tax_rate, double shipping) {
        return base_cost += (base_cost * tax_rate) + shipping;
    }

    // Function overloading allows us to define multiple functions with the same name but different parameter lists.
    void run_market_simulation(double savings_balance, double monthly_savings, int months_to_save) {
        double projected_savings = savings_balance + (monthly_savings * months_to_save);
        cout << "   -> [SIMULATION] Projected savings after " << months_to_save << " months: " << projected_savings << " EUR" << endl;
    }

    // Passing by value to follow tutorial structure. 
    // Note: This triggers a deep copy of the vector. Refactor to const reference later.
    void print_guest_list(vector<string> guest_list) {
        cout << "--- VIP GUEST LIST (VECTOR VERSION) ---" << endl;

        for (string guest : guest_list) {
            cout << "- " << guest << endl;
        }
    }

    // Overloaded definition
    void print_guest_list(string guest_array[], size_t size) {
        cout << "--- VIP GUEST LIST (ARRAY VERSION) ---" << endl;

        // Since we don't have a size method, we use an index-based loop
        for (size_t i = 0; i < size; ++i) {
            cout << "- " << guest_array[i] << endl;
        }
    }

    // Pass by reference (best way) && Overload Definition
    void print_guest_list_ref(const vector<string>& guest_list) {
        cout << "--- VIP GUEST LIST (VECTOR VERSION) ---" << endl;

        // Since we don't have a size method, we use an index-based loop
        for (size_t i = 0; i < guest_list.size(); ++i) {
            cout << "- " << guest_list[i] << endl;
        }
    }

    void demo_global() {
        // Has full access to the global variable at the top of the file
        global_counter += 1;
        cout << "Global counter is now: " << global_counter << endl;
    }

    void demo_static() {
        // The 'static' keyword tells C++: "Only initialize this ONCE. Do not destroy it when the function ends."
        static int static_counter = 10;
    
        static_counter += 1;
        cout << "Static counter is now: " << static_counter << endl;
    }

    void demo_local(int local_val) {
        // This local_val is just a temporary photocopy of the parameter passed in.
        // It gets modified once, prints, and is instantly destroyed when the function ends.
        local_val += 1;
        cout << "Local parameter is now: " << local_val << endl;
    }

    void recursive_counter(int current, int max_limit) {
    
        // 1. THE BASE CASE (The Anchor / Stop Condition)
        // If we exceed our limit, we hit 'return'.
        // This stops the function from calling itself and begins collapsing the Call Stack.
        if (current > max_limit) {
            return;
        }

        // 2. THE WORK
        // Do whatever the function is supposed to do for this single execution.
        cout << "Current count: " << current << endl;

        // 3. THE RECURSIVE CASE (The 'UNION ALL')
        // The function calls ITSELF, but we pass in 'current + 1'.
        // This ensures we are always moving one step closer to the Base Case.
        recursive_counter(current + 1, max_limit);
    }
    // END OF FUNCTION DEFINITIONS