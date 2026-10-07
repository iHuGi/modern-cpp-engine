#pragma once
#include "Account.hpp"
#include "Auditable.hpp"

/**
 * @brief A checking account class that inherits from Account and Auditable.
 * Applies a flat fee to every withdrawal transaction.
 */
class Checking_Account: public Account, public Auditable {
    private:
        /**
         * @brief Fixed flat fee applied to every withdrawal.
         */
        static constexpr double fee = 1.50;

    public:
        /**
         * @brief Overloaded constructor.
         * @param balance Initial balance of the account (default is 0.0).
         * @param name Name of the account holder (default is "Unnamed Checking").
         */
        Checking_Account(double balance = 0.0, std::string name = "Unnamed Checking");
        
        /**
         * @brief Destructor.
         */
        virtual ~Checking_Account();

        // --- Copy/Move Control ---

        /**
         * @brief Copy constructor.
         * @param other The Checking_Account object to copy from.
         */
        Checking_Account(const Checking_Account &other);
        
        /**
         * @brief Copy assignment operator.
         * @param other The Checking_Account object to assign from.
         * @return A reference to the current object.
         */
        Checking_Account &operator=(const Checking_Account &other);
        
        /**
         * @brief Move constructor.
         * @param other The temporary Checking_Account object to move from.
         */
        Checking_Account(Checking_Account &&other) noexcept;
        
        /**
         * @brief Move assignment operator.
         * @param other The temporary Checking_Account object to assign from.
         * @return A reference to the current object.
         */
        Checking_Account &operator=(Checking_Account &&other) noexcept;

        // --- Methods ---

        /**
         * @brief Withdraws a specified amount from the account, plus a flat fee.
         * Locked with final to prevent further overrides.
         * @param amount The base amount to withdraw.
         */
        virtual void withdraw(double amount) final override;

        /**
         * @brief Deposits a specified amount into the account.
         * Locked with final to prevent further overrides.
         * @param amount The base amount to deposit.
         */
        virtual void deposit(double amount) final override;

        /**
         * @brief Prints the specific details of the checking account.
         * Locked with final to prevent further overrides.
         * @param os The output stream to write to.
         */
        virtual void print(std::ostream &os) const final override;
};