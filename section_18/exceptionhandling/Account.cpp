#include "Account.h"
#include "AccountExceptions.h"
#include <iostream>

Account::Account(double initial_balance) {
    if (initial_balance < 0) {
        throw IllegalBalanceException();
    }
    balance = initial_balance;
    std::cout << "Account created with balance: " << balance << std::endl;
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        throw InsufficientFundsException();
    }
    balance -= amount;
    std::cout << "Withdrawal of " << amount << " successful. New balance: " << balance << std::endl;
}