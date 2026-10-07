#include <iostream>
#include <utility> // For std::move
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"

using namespace std;

int main() {
    
    // =========================================================================
    // 1. Regular Account Test (Stack) - Hugo
    // =========================================================================
    cout << "\n=== 1. Regular Account (Stack) ===" << endl;
    Account hugo_acc {1000.0, "Hugo Checking"};
    hugo_acc.deposit(500.0);
    hugo_acc.withdraw(200.0);
    
    // =========================================================================
    // 2. Regular Account Test (Heap / Pointers) - Hugo Secondary
    // =========================================================================
    cout << "\n=== 2. Regular Account (Pointers) ===" << endl;
    Account *p_hugo_acc {nullptr};
    p_hugo_acc = new Account(2500.0, "Hugo Investment");
    p_hugo_acc->deposit(1000.0);
    p_hugo_acc->withdraw(500.0);
    delete p_hugo_acc; // Clean up heap memory
    
    // =========================================================================
    // 3. Savings Account Test (Stack) - Pedro (with Interest Rate)
    // =========================================================================
    cout << "\n=== 3. Savings Account (Stack) ===" << endl;
    Savings_Account pedro_sav {2000.0, "Pedro Savings", 5.0};
    pedro_sav.deposit(1000.0); 
    pedro_sav.withdraw(400.0);
    
    // =========================================================================
    // 4. Savings Account Test (Heap / Pointers) - Pedro Secondary
    // =========================================================================
    cout << "\n=== 4. Savings Account (Pointers) ===" << endl;
    Savings_Account *p_pedro_sav {nullptr};
    p_pedro_sav = new Savings_Account{5000.0, "Pedro VIP Savings", 3.5};
    p_pedro_sav->deposit(2000.0); 
    p_pedro_sav->withdraw(1000.0);
    delete p_pedro_sav; // Clean up heap memory

    // =========================================================================
    // 5. Copy Control Test (Copy Constructor & Assignment)
    // =========================================================================
    cout << "\n=== 5. Copy Control Test ===" << endl;
    
    cout << "--> Testing Copy Constructor:" << endl;
    // Creates a new account by cloning pedro_sav
    Savings_Account pedro_clone {pedro_sav}; 
    
    cout << "\n--> Testing Copy Assignment:" << endl;
    // Creates an empty account first, then overrides it with the clone
    Savings_Account pedro_backup {0.0, "Empty Backup", 0.0}; 
    pedro_backup = pedro_clone; 

    // =========================================================================
    // 6. Move Control Test (Move Constructor & Assignment)
    // =========================================================================
    cout << "\n=== 6. Move Control Test ===" << endl;
    
    cout << "--> Testing Move Constructor:" << endl;
    // Steals data from the clone to create a new moved account
    Savings_Account pedro_moved {std::move(pedro_clone)};
    
    cout << "\n--> Testing Move Assignment:" << endl;
    // Steals data from an anonymous temporary object and assigns it to the backup
    pedro_backup = Savings_Account{999.0, "Temporary Account", 9.9};

    // =========================================================================
    // 7. Checking Account Test (Flat Fee)
    // =========================================================================
    cout << "\n=== 7. Checking Account (Flat Fee) ===" << endl;
    Checking_Account my_checking{100.0, "Hugo Checking"};
    cout << "Initial Balance: " << my_checking.get_balance() << endl;
    
    my_checking.deposit(50.0);
    my_checking.withdraw(50.0); // Should deduct 50 + 1.50 fee
    cout << "Balance after transactions: " << my_checking.get_balance() << endl;

    // =========================================================================
    // 8. Trust Account Test (Bonus & Limits)
    // =========================================================================
    cout << "\n=== 8. Trust Account (Bonus & Limits) ===" << endl;
    Trust_Account my_trust{0.0, "Hugo Trust", 5.0};
    
    // Normal deposit (No bonus)
    my_trust.deposit(1000.0); 
    
    // Large deposit ($50 bonus triggered BEFORE interest)
    my_trust.deposit(5000.0); 
    cout << "Balance after deposits: " << my_trust.get_balance() << endl;

    cout << "\n--- Testing 20% withdrawal limit ---" << endl;
    my_trust.withdraw(2000.0); // Should fail for exceeding 20% of current balance

    cout << "\n--- Testing 3 withdrawals limit ---" << endl;
    my_trust.withdraw(100.0); // 1st withdrawal
    my_trust.withdraw(100.0); // 2nd withdrawal
    my_trust.withdraw(100.0); // 3rd withdrawal
    cout << "Balance after 3 valid withdrawals: " << my_trust.get_balance() << endl;
    
    cout << "\n--- Attempting 4th withdrawal ---" << endl;
    my_trust.withdraw(100.0); // 4th - System must block this transaction!

    cout << "\n===========================================" << endl;
    cout << "=== Program ending, destructors will fire ===" << endl;
    return 0;
}