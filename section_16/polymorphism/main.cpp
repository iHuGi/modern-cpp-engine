#include <iostream>
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"

using namespace std;

// Prototype
void process_withdrawal(Account &account, double amount);

int main() {
    
    cout << "\n=== 1. POLYMORPHISM WITH BASE CLASS POINTERS ===" << endl;
    
    // IMPORTANT: These are completely separate accounts in memory!
    // They do NOT share balances. Each has its own private vault.
    // Note: 'Account' is now an abstract class, so we can only instantiate its children.
    Account *p2 = new Savings_Account(2000.0, "Pedro Savings", 5.0);
    Account *p3 = new Checking_Account(3000.0, "Hugo Checking");
    Account *p4 = new Trust_Account(4000.0, "Hugo Trust", 5.0);

    // =========================================================================
    // 2. THE TRUE POWER OF POLYMORPHISM: GENERIC VECTORS
    // =========================================================================
    cout << "\n=== 2. BATCH PROCESSING (VECTOR) ===" << endl;
    
    vector<Account*> accounts {p2, p3, p4};

    cout << "\n--- Applying Generic Deposit (Dynamic Binding) ---" << endl;
    for (auto acc_ptr : accounts) {
        // The compiler sees 'Account*', but executes the specific logic at runtime:
        // - Trust_Account: Applies $50 bonus if deposit >= $5000.
        // - Savings_Account: Applies interest rate before deposit.
        // - Checking_Account: Overrides deposit, logs transaction, delegates to base.
        acc_ptr->deposit(5000.0);
    }

    cout << "\n--- Applying Generic Withdrawal (Dynamic Binding) ---" << endl;
    for (auto acc_ptr : accounts) {
        // - Checking_Account: Applies flat fee of $1.50.
        // - Savings_Account: Applies percentage fee.
        // - Trust_Account: Validates 20% limit and max 3 withdrawals.
        acc_ptr->withdraw(500.0);
    }

    // =========================================================================
    // 3. TESTING TRUST ACCOUNT LIMITS VIA BASE POINTER
    // =========================================================================
    cout << "\n=== 3. TESTING TRUST LIMITS (Via Account*) ===" << endl;
    // The base pointer p4 can still trigger the 3 withdrawals rule for Hugo's Trust Account
    p4->withdraw(100.0); // 2nd withdrawal
    p4->withdraw(100.0); // 3rd withdrawal
    p4->withdraw(100.0); // 4th withdrawal - Should be blocked!

    // =========================================================================
    // 4. TESTING I_PRINTABLE INTERFACE (POLYMORPHIC PRINTING)
    // =========================================================================
    cout << "\n=== 4. TESTING I_PRINTABLE INTERFACE ===" << endl;
    for (auto acc_ptr : accounts) {
        // Dereferencing the pointer gives us an Account&.
        // The overloaded operator<< in I_Printable intercepts this and dynamically 
        // calls the correct print() method for Savings, Checking, or Trust!
        cout << *acc_ptr << endl; 
    }

    // =========================================================================
    // 5. CLEANUP - VIRTUAL DESTRUCTORS IN ACTION
    // =========================================================================
    cout << "\n=== 5. CLEANING THE HEAP (Testing Virtual Destructors) ===" << endl;
    for (auto acc_ptr : accounts) {
        // Thanks to 'virtual ~Account()' in the base class, this will first destroy
        // the derived part (e.g., ~Trust_Account) and then the base part (~Account).
        // Prevents Memory Leaks!
        delete acc_ptr;
    }

    // =========================================================================
    // 6. TESTING BASE CLASS REFERENCES
    // =========================================================================
    cout << "\n=== 6. TESTING BASE CLASS REFERENCES ===" << endl;
    
    Checking_Account my_checking(1000.0, "Hugo Azevedo"); // Initial balance
    Trust_Account my_trust(5000.0, "Pedro Relvas");       // Initial balance

    // Calls base Account withdrawal but applies the $1.50 fee specific to Checking_Account
    process_withdrawal(my_checking, 300.0);
    
    // Executes Trust rules first, delegates to Savings for interest/fees, 
    // then finally delegates to Account for the actual withdrawal
    process_withdrawal(my_trust, 500.0);

    cout << "\n=== End of Program ===" << endl;
    return 0;
}

// Definition
void process_withdrawal(Account &account, double amount) {
    std::cout << "\n[System]: Initializing withdrawal request of: $" << amount << std::endl;

    // Dynamic binding works with references just like it does with pointers!
    account.withdraw(amount);

    std::cout << "[System]: Transaction completed with success.\n" << std::endl;
}