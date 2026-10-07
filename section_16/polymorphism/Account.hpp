#pragma once
#include <string>
#include "I_Printable.hpp"

/**
 * @brief Base class representing a standard bank account.
 * 
 * Provides core banking functionality such as deposits, withdrawals, 
 * and proper memory management through the Rule of Five. It is an abstract 
 * class (due to pure virtual functions) and cannot be instantiated directly.
 */
class Account: public I_Printable {
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
        virtual ~Account();

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
         * Pure virtual function forcing derived classes to implement deposit logic.
         * @param amount The amount to deposit.
         */
        virtual void deposit(double amount) = 0;

        /**
         * @brief Deducts a specified amount from the account balance.
         * Pure virtual function forcing derived classes to implement withdrawal logic.
         * @param amount The amount to withdraw.
         */
        virtual void withdraw(double amount) = 0;

        /**
         * @brief Prints the specific details of the account. Overrides I_Printable.
         * @param os The output stream to write to.
         */
        virtual void print(std::ostream &os) const override;

        /**
         * @brief Returns the current account balance.
         * @return The balance as a double.
         */
        double get_balance() const;
};