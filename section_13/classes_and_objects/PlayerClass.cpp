#include "PlayerClass.hpp"
#include <iostream>

/* =========================================================================
 * ARCHITECTURAL EVOLUTION & LEARNING HISTORY:
 * -------------------------------------------------------------------------
 * Previously, we implemented delegating constructors where the default 
 * and 2-parameter variants handed off work to our 3-parameter "Heavy Lifter".
 * 
 * They are archived below. We have now unified all of them into a single 
 * constructor leveraging Default Parameter Values in the header, initialized 
 * via an initialization list below for optimal performance.
 * ========================================================================= */

/* [ARCHIVED] Step 1: The Heavy Lifter (3 parameters)
Player::Player(std::string playerName, int startingHealth, int startingXp) 
    : name{playerName}, health{startingHealth}, xp{startingXp} {
    std::cout << "[SYSTEM] Main Constructor called for " << name << ".\n";
}
*/

/* [ARCHIVED] Step 2: Delegating Default Constructor (0 parameters)
Player::Player()
    : Player{"Unknown NPC", 100, 0} {
    std::cout << "[SYSTEM] Default Constructor called for " << name << ".\n";
}
*/

/* [ARCHIVED] Step 3: Delegating Invincible Mode Constructor (2 parameters)
Player::Player(std::string playerName, int startingHealth) 
    : Player{playerName, startingHealth, 9999} {
    std::cout << "[SYSTEM] Invincible Mode Constructor called for " << name << ".\n";
}
*/

// =========================================================================
// CURRENT IMPLEMENTATION: The Ultimate Unified Constructor
// =========================================================================
/**
 * @brief Initializes player attributes using an initialization list.
 * 
 * Defaults are defined in the header contract, enabling seamless handling 
 * of 0, 2, or 3 arguments without code duplication or delegation overhead.
 */
Player::Player(std::string playerName, int startingHealth, int startingXp) 
    : name{playerName}, health{startingHealth}, xp{startingXp} {
    std::cout << "[SYSTEM] Ultimate Constructor created for: " << name << ".\n";
}

// Handles player dialogue output
void Player::talk(std::string text_to_say) const {
    std::cout << name << " says: " << text_to_say << std::endl;
}

// Evaluates mortality status
bool Player::is_dead() const {
    return health <= 0;
}

// Calculates and applies damage based on enemy type classification
void Player::damage_taken(int damage, std::string animal) {
    
    // High-threat enemy logic
    if (animal == "Lion") {
        int actual_damage = damage * 5;
        health -= actual_damage;
        std::cout << "Bro you got attacked by a Lion, you took " << actual_damage << " damage!" << std::endl;
        
    // Low-threat enemy logic
    } else if (animal == "Zebra") {
        int actual_damage = static_cast<int>(damage * 0.1);
        health -= actual_damage;
        std::cout << "Bro you got attacked by a Zebra, you took " << actual_damage << " damage!" << std::endl;
        
    // Safe scenario fallback
    } else {
        std::cout << "No damage taken, you are safe!" << std::endl;
    }
}

// Destructor implementation
Player::~Player() {
    std::cout << "Player object for " << name << " is being destroyed." << std::endl;
}