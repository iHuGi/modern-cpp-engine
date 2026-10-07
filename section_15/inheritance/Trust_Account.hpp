#pragma once
#include "Savings_Account.hpp"

/**
 * @class Trust_Account
 * @brief Conta fiduciária que herda de Savings_Account. Aplica bónus em grandes depósitos e limita saques.
 */
class Trust_Account : public Savings_Account {
    private:
        static constexpr double bonus_threshold = 5000.0;     ///< Valor mínimo de depósito para aplicar o bónus
        static constexpr double bonus_amount = 50.0;          ///< Valor do bónus aplicado
        static constexpr int max_withdrawals = 3;             ///< Número máximo de levantamentos permitidos
        static constexpr double max_withdraw_percent = 0.2;   ///< Percentagem máxima do saldo permitida por levantamento

        int num_withdrawals; ///< Contador de levantamentos efetuados

    public:
        /**
         * @brief Construtor da Trust_Account.
         * @param balance Saldo inicial da conta.
         * @param name Nome do titular da conta (default: "Unknown Trust").
         * @param interest_rate Taxa de juro herdada (default: 0.0).
         */
        Trust_Account(double balance, std::string name = "Unknown Trust", double interest_rate = 0.0);
        
        /**
         * @brief Destrutor.
         */
        ~Trust_Account();

        // --- Copy & Move Constructors ---

        /**
         * @brief Construtor de cópia.
         * @param other Objeto Trust_Account a copiar.
         */
        Trust_Account(const Trust_Account &other);
        
        /**
         * @brief Operador de atribuição de cópia.
         * @param other Objeto Trust_Account a copiar.
         * @return Referência para o objeto atual.
         */
        Trust_Account &operator=(const Trust_Account &other);
        
        /**
         * @brief Construtor de movimento (sem const para permitir roubo de dados).
         * @param other Temporário Trust_Account a mover.
         */
        Trust_Account(Trust_Account &&other) noexcept;
        
        /**
         * @brief Operador de atribuição de movimento.
         * @param other Temporário Trust_Account a mover.
         * @return Referência para o objeto atual.
         */
        Trust_Account &operator=(Trust_Account &&other) noexcept;

        // --- Methods from Savings which inherits and delegates to Account ---

        /**
         * @brief Deposita um valor, aplicando bónus se atingir o threshold. Delega para Savings.
         * @param amount Valor base a depositar.
         */
        void deposit(double amount);
        
        /**
         * @brief Levanta um valor, validando número de saques e percentagem. Delega para Savings.
         * @param amount Valor base a levantar.
         */
        void withdraw(double amount);
};