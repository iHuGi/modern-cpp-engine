#include <iostream>
#include "Auditable.hpp"

// Outputs the transaction details to the console, acting as an independent security mix-in
void Auditable::log_transaction(const std::string& type, double amount) const {
    std::cout << "[SECURITY AUDIT] " << type << " of " << amount << " processed." << std::endl;
}