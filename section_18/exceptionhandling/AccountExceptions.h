/**
 * @file AccountExceptions.h
 * @brief Custom exception classes for Account operations.
 */

#pragma once
#include <exception>

/**
 * @class IllegalBalanceException
 * @brief Exception thrown when an account is instantiated with a negative balance.
 */
class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;

    /**
     * @brief Provides the specific error message.
     * @return A C-style string describing the negative balance error.
     */
    virtual const char* what() const noexcept override {
        return "Error: Cannot initialize an account with a negative balance.";
    }
};

/**
 * @class InsufficientFundsException
 * @brief Exception thrown when a withdrawal amount exceeds the available balance.
 */
class InsufficientFundsException : public std::exception { // Typo "public::" corrigido
public:
    InsufficientFundsException() = default;
    ~InsufficientFundsException() = default;
    
    /**
     * @brief Provides the specific error message.
     * @return A C-style string describing the insufficient funds error.
     */
    virtual const char* what() const noexcept override {
        return "Error: Insufficient funds to complete the withdrawal.";
    }
};