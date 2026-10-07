#pragma once
#include <string>

/**
 * @brief Base class representing a standard bank account.
 * 
 * Provides core banking functionality such as deposits, withdrawals, 
 * and proper memory management through the Rule of Five.
 */
class Account {
    protected:
        /** @brief Current account balance, accessible to derived classes. */
        double balance;
        
        /** @brief Name of the account holder. */
        std::string name;
        
    public:
        // --- Constructors & Destructor ---

        /**
         * @brief Default constructor. Initializes an empty account with a zero balance.
         */
        Account();

        /**
         * @brief Overloaded constructor.
         * @param balance The initial balance of the account.
         * @param name The name of the account holder.
         */
        Account(double balance, std::string name);

        /**
         * @brief Destructor. Cleans up any resources held by the Account.
         */
        ~Account();

        // --- Copy Control ---

        /**
         * @brief Copy constructor (Lvalue reference).
         * @param other The Account object to copy from.
         */
        Account(const Account &other);

        /**
         * @brief Copy assignment operator (Lvalue reference).
         * @param other The right-hand side Account object to assign from.
         * @return A reference to the current object to allow chaining.
         */
        Account &operator=(const Account &other);

        // --- Move Control ---

        /**
         * @brief Move constructor (Rvalue reference).
         * @param other The temporary Account object to steal data from.
         */
        Account(Account &&other) noexcept;

        /**
         * @brief Move assignment operator (Rvalue reference).
         * @param other The temporary right-hand side Account object to steal data from.
         * @return A reference to the current object to allow chaining.
         */
        Account &operator=(Account &&other) noexcept;

        // --- Core Account Operations ---

        /**
         * @brief Adds a specified amount to the account balance.
         * @param amount The amount to deposit.
         */
        void deposit(double amount);

        /**
         * @brief Deducts a specified amount from the account balance.
         * @param amount The amount to withdraw.
         */
        void withdraw(double amount);

        /**
         * @brief Returns the current account balance.
         * @return The balance as a double.
         */
        double get_balance() const;
};