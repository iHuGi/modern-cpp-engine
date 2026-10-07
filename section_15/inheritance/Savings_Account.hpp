#pragma once
#include "Account.hpp"
#include "Auditable.hpp"

/**
 * @brief Class representing a savings account with interest rates.
 * 
 * Inherits core functionality from Account and transaction logging capabilities from Auditable.
 */
class Savings_Account : public Account, public Auditable {
    public:
        /** @brief Interest rate applied to deposits. */
        double interest_rate;
        
        // --- Constructors & Destructor ---

        /**
         * @brief Overloaded constructor.
         * @param balance The initial balance of the savings account.
         * @param name The name of the account holder.
         * @param interest_rate The interest rate percentage to be applied on deposits.
         */
        Savings_Account(double balance, std::string name, double interest_rate);

        /**
         * @brief Destructor. Cleans up any resources held by the Savings_Account.
         */
        ~Savings_Account();
        
        // --- Copy Control ---

        /**
         * @brief Copy constructor (Lvalue reference).
         * @param other The Savings_Account object to copy from.
         */
        Savings_Account(const Savings_Account &other);

        /**
         * @brief Copy assignment operator (Lvalue reference).
         * @param other The right-hand side Savings_Account object to assign from.
         * @return A reference to the current object to allow chaining.
         */
        Savings_Account &operator=(const Savings_Account &other);

        // --- Move Control ---

        /**
         * @brief Move constructor (Rvalue reference).
         * @param other The temporary Savings_Account object to steal data from.
         */
        Savings_Account(Savings_Account &&other) noexcept;

        /**
         * @brief Move assignment operator (Rvalue reference).
         * @param other The temporary right-hand side Savings_Account object to steal data from.
         * @return A reference to the current object to allow chaining.
         */
        Savings_Account &operator=(Savings_Account &&other) noexcept;
        
        // --- Overridden Base Methods ---

        /**
         * @brief Deposits an amount and applies the interest rate bonus.
         * @param amount The base amount to deposit.
         */
        void deposit(double amount);

        /**
         * @brief Withdraws an amount and applies a standard withdrawal fee.
         * @param amount The base amount to withdraw.
         */
        void withdraw(double amount);
};