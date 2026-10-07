#include "Trust_Account.hpp"
#include <iostream>

// Constructor delegates to Savings_Account and initializes withdrawal counter
Trust_Account::Trust_Account(double balance, std::string name, double int_rate) :
    Savings_Account{balance, name, int_rate}, num_withdrawals{0} {}

Trust_Account::~Trust_Account() {}

// --- Copy control ---

Trust_Account::Trust_Account(const Trust_Account &other) : 
    Savings_Account{other}, num_withdrawals{other.num_withdrawals} {}

Trust_Account &Trust_Account::operator=(const Trust_Account &other) {
    if (this == &other) return *this;

    Savings_Account::operator=(other);
    num_withdrawals = other.num_withdrawals;

    return *this;
}

// --- Move control ---

Trust_Account::Trust_Account(Trust_Account &&other) noexcept : 
    Savings_Account{std::move(other)}, num_withdrawals{other.num_withdrawals} {}

Trust_Account &Trust_Account::operator=(Trust_Account &&other) noexcept {
    if (this == &other) return *this;

    Savings_Account::operator=(std::move(other));
    num_withdrawals = other.num_withdrawals;

    return *this;
}

// --- Methods ---

void Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold) {
        amount += bonus_amount;
        log_transaction("Trust Deposit (+$50 Bonus Triggered)", amount);
    } else {
        log_transaction("Trust Deposit", amount);
    }
    
    // Delegate to Savings_Account
    Savings_Account::deposit(amount);
}

void Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals) {
        std::cout << "Transaction failed: Maximum withdrawals (" << max_withdrawals << ") reached." << std::endl;
        return;
    }
    
    if (amount > (balance * max_withdraw_percent)) {
        std::cout << "Transaction failed: Cannot withdraw more than " << (max_withdraw_percent * 100) << "% of current balance." << std::endl;
        return;
    }
    
    ++num_withdrawals;
    log_transaction("Trust Withdrawal", amount);

    // Delegate to Savings_Account
    Savings_Account::withdraw(amount);
}