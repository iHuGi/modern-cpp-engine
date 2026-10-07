#pragma once
#include "Savings_Account.hpp"

/**
 * @class Trust_Account
 * @brief Trust account that inherits from Savings_Account. Applies a bonus to large deposits and limits withdrawals.
 * 
 * Locked with the final specifier to prevent any further inheritance.
 */
class Trust_Account final : public Savings_Account {
    private:
        static constexpr double bonus_threshold = 5000.0;     ///< Minimum deposit amount to apply the bonus
        static constexpr double bonus_amount = 50.0;          ///< Bonus amount applied
        static constexpr int max_withdrawals = 3;             ///< Maximum number of withdrawals allowed
        static constexpr double max_withdraw_percent = 0.2;   ///< Maximum percentage of the balance allowed per withdrawal

        int num_withdrawals; ///< Counter for the number of withdrawals made

    public:
        /**
         * @brief Trust_Account constructor.
         * @param balance Initial balance of the account.
         * @param name Name of the account holder (default: "Unknown Trust").
         * @param interest_rate Inherited interest rate (default: 0.0).
         */
        Trust_Account(double balance, std::string name = "Unknown Trust", double interest_rate = 0.0);
        
        /**
         * @brief Destructor.
         */
        virtual ~Trust_Account();

        // --- Copy & Move Constructors ---

        /**
         * @brief Copy constructor.
         * @param other The Trust_Account object to copy from.
         */
        Trust_Account(const Trust_Account &other);
        
        /**
         * @brief Copy assignment operator.
         * @param other The Trust_Account object to assign from.
         * @return A reference to the current object.
         */
        Trust_Account &operator=(const Trust_Account &other);
        
        /**
         * @brief Move constructor.
         * @param other The temporary Trust_Account object to move from.
         */
        Trust_Account(Trust_Account &&other) noexcept;
        
        /**
         * @brief Move assignment operator.
         * @param other The temporary Trust_Account object to assign from.
         * @return A reference to the current object.
         */
        Trust_Account &operator=(Trust_Account &&other) noexcept;

        // --- Methods from Savings which inherits and delegates to Account ---

        /**
         * @brief Deposits an amount, applying a bonus if the threshold is reached. Delegates to Savings_Account.
         * @param amount The base amount to deposit.
         */
        virtual void deposit(double amount) override;
        
        /**
         * @brief Withdraws an amount, validating the number of withdrawals and percentage limit. Delegates to Savings_Account.
         * @param amount The base amount to withdraw.
         */
        virtual void withdraw(double amount) override;

        /**
         * @brief Prints the specific details of the trust account. Overrides I_Printable.
         * @param os The output stream to write to.
         */
        virtual void print(std::ostream &os) const override final;
};