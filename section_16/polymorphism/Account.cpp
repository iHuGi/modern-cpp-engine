#include <iostream>
#include "Account.hpp"

// Default Constructor
Account::Account() : balance{0.0}, name{"An Account"} {
    std::cout << "Account default constructor called!" << std::endl;
}

// Overloaded Constructor
Account::Account(double balance, std::string name) : balance{balance}, name{name} {
    std::cout << "Account overloaded constructor called for " << name << std::endl;
}

// Destructor
Account::~Account() {
    std::cout << "Account destructor called!" << std::endl;
}

// Copy Constructor: Copies data from another Account object
Account::Account(const Account &other) : balance{other.balance}, name{other.name} {
    std::cout << "Account Copy Constructor" << std::endl;
}

// Copy Assignment Operator: Replaces current object's data with another's
Account &Account::operator=(const Account &other) {
    if (this == &other) return *this; // Guard against self-assignment
    
    balance = other.balance;
    name = other.name;
    std::cout << "Account Copy Assignment" << std::endl;
    
    return *this; 
}

// Move Constructor: Steals resources from a temporary Account object
Account::Account(Account &&other) noexcept : balance{std::move(other.balance)}, name{std::move(other.name)} {
    other.balance = 0.0;
    other.name = ""; // Nullify stolen object's pointers/data
    std::cout << "Account Move Constructor" << std::endl;
}

// Move Assignment Operator: Steals resources and replaces current data
Account &Account::operator=(Account &&other) noexcept { // Fixed: Added missing 'noexcept'
    if (this == &other) return *this;
    
    balance = std::move(other.balance);
    name = std::move(other.name);
    
    other.balance = 0.0;
    other.name = "";
    
    std::cout << "Account Move Assignment" << std::endl;
    return *this; 
}

// --- Core Methods ---

void Account::deposit(double amount) {
    // Increment the core balance with the incoming funds
    balance += amount;
    std::cout << "Account deposit called for " << amount << std::endl;
}

void Account::withdraw(double amount) {
    // Basic overdraft protection: ensures we only deduct what we actually have
    if (balance - amount >= 0) {
        balance -= amount;
        std::cout << "Account withdraw called for " << amount << std::endl;
    } else {
        // Transaction blocked to prevent negative balances
        std::cout << "Insufficient funds in base Account." << std::endl;
    }
}

void Account::print(std::ostream &os) const {
    // Writes details to the provided output stream (os) rather than hardcoding std::cout.
    // This perfectly hooks into the overloaded operator<< from I_Printable.
    os << "[Account Holder: " << name << "] - [Balance: $" << balance << "]";
}

double Account::get_balance() const {
    // Read-only access to the current vault balance
    return balance;
}