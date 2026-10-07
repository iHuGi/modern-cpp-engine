/**
 * @file Account.h
 * @brief Declaration of the Account class for basic banking operations.
 */

#pragma once

/**
 * @class Account
 * @brief Represents a simple bank account that validates balances and withdrawals.
 */
class Account {
private:
    double balance;

public:
    /**
     * @brief Constructs a new Account object.
     * @param initial_balance The starting balance of the account.
     * @throws IllegalBalanceException if initial_balance is negative.
     */
    Account(double initial_balance);

    /**
     * @brief Withdraws a specified amount from the account balance.
     * @param amount The amount to withdraw.
     * @throws InsufficientFundsException if amount exceeds the current balance.
     */
    void withdraw(double amount);
};