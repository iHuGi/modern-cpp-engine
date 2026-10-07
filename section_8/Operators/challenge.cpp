#include <iostream>

using namespace std;

int main() {
    // Constant values defined for maintainability (best practice)
    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value {10};
    const int nickel_value {5};

    int change_amount {};

    cout << "Enter change amount in cents: ";
    cin >> change_amount;

    int balance {change_amount};
    
    // Calculate Dollars
    int dollars = balance / dollar_value;
    balance %= dollar_value; // Update balance to the remainder

    // Calculate Quarters
    int quarters = balance / quarter_value;
    balance %= quarter_value;

    // Calculate Dimes
    int dimes = balance / dime_value;
    balance %= dime_value;

    // Calculate Nickels
    int nickels = balance / nickel_value;
    balance %= nickel_value;

    // Calculate Pennies (the remaining balance)
    int pennies = balance;

    // Output results in a professional, readable format
    cout << "\nYou can provide this change as follows:" << endl;
    cout << "dollars : " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes   : " << dimes << endl;
    cout << "nickels : " << nickels << endl;
    cout << "pennies : " << pennies << endl;

    return 0;
}