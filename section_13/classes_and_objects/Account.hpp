#pragma once
#include <iostream>
#include <string> // CRÍTICO: Faltava o include para o std::string

/**
 * @class Account
 * @brief Represents a basic bank account.
 *
 * This class manages the account owner's name and current balance,
 * providing safe methods for deposits and withdrawals.
 */
class Account {
private: // Boa prática: colocar a tag private de forma explícita
    std::string owner_name; /**< The name of the account owner. */
    double current_amount;  /**< The current balance of the account. */

public:
    /**
     * @brief Initializes a new Account instance.
     * @param name The name of the account owner.
     * @param initial_balance The starting balance (defaults to 0.0).
     */
    Account(std::string name, double initial_balance = 0.0);

    // Methods
    /**
     * @brief Deposits a specified amount into the account.
     * @param amount The value to deposit (must be greater than 0).
     */
    void add(const double amount);

    /**
     * @brief Withdraws a specified amount from the account.
     * @param amount The value to withdraw (must be <= current balance).
     */
    void withdraw(const double amount);

    /**
     * @brief Prints the current account balance to the console.
     * 
     * Marked as const to guarantee it does not modify object state.
     */
    void check_current_balance() const;

    // Auxiliary method for main
    /**
     * @brief Retrieves the name of the account owner.
     * @return The account owner's name.
     */
    std::string get_name() const;

    /**
     * @brief Destroys the Account object.
     * 
     * Automatically called when the object goes out of scope.
     */
    ~Account();
};