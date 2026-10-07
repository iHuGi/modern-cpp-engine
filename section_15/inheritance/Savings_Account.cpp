#include <iostream>
#include "Savings_Account.hpp"

// Overloaded Constructor: Initializes base class members and specific child members
Savings_Account::Savings_Account(double balance, std::string name, double interest_rate) 
    : Account{balance, name}, interest_rate{interest_rate} {
    std::cout << "Savings Account overloaded constructor called for: " << name << std::endl;
}

// Destructor
Savings_Account::~Savings_Account() {
    std::cout << "Savings Account destructor called for: " << name << std::endl;
}

// Copy Constructor: Delegates base slicing to Account, handles its own interest_rate
Savings_Account::Savings_Account(const Savings_Account &other) 
    : Account{other}, interest_rate{other.interest_rate} {
    std::cout << "Savings Account Copy Constructor" << std::endl;
}

// Copy Assignment Operator: Delegates base assignment to Account
Savings_Account &Savings_Account::operator=(const Savings_Account &other) {
    if (this == &other) return *this; // Guard against self-assignment
    
    Account::operator=(other); // Call base class assignment operator
    interest_rate = other.interest_rate;
    
    std::cout << "Savings Account Copy Assignment" << std::endl;
    return *this;
}

// Move Constructor: Delegates base move to Account, steals child data
Savings_Account::Savings_Account(Savings_Account &&other) noexcept 
    : Account{std::move(other)}, interest_rate{std::move(other.interest_rate)} {
    other.interest_rate = 0.0; // Nullify stolen data
    std::cout << "Savings Account Move Constructor" << std::endl; // Fixed: Was saying "Copy"
}

// Move Assignment Operator: Delegates base move assignment, steals child data
Savings_Account &Savings_Account::operator=(Savings_Account &&other) noexcept {
    if (this == &other) return *this;
    
    Account::operator=(std::move(other)); // Call base class move assignment
    interest_rate = std::move(other.interest_rate);
    
    other.interest_rate = 0.0;
    
    std::cout << "Savings Account Move Assignment" << std::endl;
    return *this;
}

// Overridden deposit method: Calculates interest before delegating the deposit to base
void Savings_Account::deposit(double amount) {
    double interest_bonus = amount * (interest_rate / 100.0);
    double total_deposit = amount + interest_bonus;

    log_transaction("Deposit (with interest)", total_deposit);
    
    std::cout << "[Interest Applied] Depositing " << amount << " + " << interest_bonus 
              << " interest (" << interest_rate << "%) = Total: " << total_deposit << std::endl;
              
    Account::deposit(total_deposit);
}

// Overridden withdraw method: Applies a standard fee before delegating the total deduction to base
void Savings_Account::withdraw(double amount) {
    double withdrawl_rate =  0.02;
    double fee = amount * withdrawl_rate;
    double total_deduction = amount + fee;

    log_transaction("Withdrawal (with fee)", total_deduction);

    std::cout << "[Fee Applied] Withdrawing " << amount 
              << " + " << fee << " fee = Total deduction: " << (amount + fee) << std::endl;

    Account::withdraw(amount + fee);
}