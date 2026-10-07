#include "Checking_Account.hpp"
#include <iostream>

// Constructor delegates initialization to the base Account class
Checking_Account::Checking_Account(double balance, std::string name) : 
    Account{balance, name} {}

Checking_Account::~Checking_Account() {}

// --- Copy control ---

// Uses the base class copy constructor to handle the balance and name
Checking_Account::Checking_Account(const Checking_Account &other) : Account{other} {}

Checking_Account &Checking_Account::operator=(const Checking_Account &other) {
    // Prevent self-assignment (e.g., acc1 = acc1)
    if (this == &other) return *this;
    
    // Call base class assignment operator to copy inherited members
    Account::operator=(other);
    return *this;
}

// --- Move control ---

// Steals resources using std::move on the base class move constructor
Checking_Account::Checking_Account(Checking_Account &&other) noexcept : Account(std::move(other)) {}

Checking_Account &Checking_Account::operator=(Checking_Account &&other) noexcept {
    // Prevent self-assignment
    if (this == &other) return *this;
    
    // Call base class move assignment to transfer ownership of inherited members
    Account::operator=(std::move(other));
    return *this;
}

// --- Core method ---

void Checking_Account::withdraw(double amount) {
    // Add the flat fee to the requested withdrawal amount
    amount += fee;
    
    // Log the transaction via the Auditable interface
    log_transaction("Checking Withdrawal (+ $1.50 fee)", amount);
    
    // Delegate the actual balance deduction to the base class
    Account::withdraw(amount);
}