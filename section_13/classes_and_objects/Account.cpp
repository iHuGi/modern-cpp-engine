#include "Account.hpp"
#include <iostream>

// Initializes the account with an owner and an initial balance
Account::Account(std::string name, double initial_balance) {
    owner_name = name;
    current_amount = initial_balance;
}

// Adds funds to the account if the provided amount is strictly positive
void Account::add(const double amount) {
    if (amount > 0) {
        current_amount += amount;
        std::cout << "[+] " << owner_name << " depositou " << amount << " euros.\n";
    } else {
        std::cout << "[-] " << owner_name << " tentou depositar um valor negativo.\n";
    }
}

// Processes a withdrawal after validating funds and account status
void Account::withdraw(const double amount) { 
    // Prevent operations on accounts with negative balances
    if (current_amount < 0) {
        std::cout << "[!] Erro Crítico: A conta de " << owner_name << " já está a zeros ou negativa!\n";
        return; 
    }
    
    // Ensure sufficient funds for the requested withdrawal
    if (amount > current_amount) {
        std::cout << "[-] Levantamento recusado! " << owner_name << " não tem " << amount << " euros disponíveis.\n";
    } else {
        current_amount -= amount;
        std::cout << "[-] " << owner_name << " levantou " << amount << " euros.\n";
    }
}

// Outputs the current financial status of the account
void Account::check_current_balance() const {
    std::cout << "[=] " << owner_name << " tem atualmente " << current_amount << " euros na conta.\n";
}

// Returns the account owner's name securely without modifying state
std::string Account::get_name() const {
    return owner_name;
}

// Destructor implementation
Account::~Account() {
    std::cout << "Account for " << owner_name << " is being destroyed." << std::endl;
}