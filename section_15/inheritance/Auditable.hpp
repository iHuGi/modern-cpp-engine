#pragma once
#include <string>

/**
 * @brief Mix-in class to provide transaction logging capabilities.
 */
class Auditable {
public:
    /**
     * @brief Logs a transaction to the standard output.
     * @param type The type of transaction (e.g., "Deposit", "Withdrawal").
     * @param amount The transaction value.
     */
    void log_transaction(const std::string& type, double amount) const;
};