#pragma once
#include <string>

/**
 * @class Player
 * @brief Represents a character entity within the game environment.
 *
 * This class manages the player's core attributes such as name, health,
 * and experience points, as well as interactions and combat mechanics.
 */
class Player {
private:
    std::string name; /**< The display name of the player. */
    int health;       /**< The current health points (HP) of the player. */
    int xp;           /**< The accumulated experience points (XP). */

public:
    /* =========================================================================
     * ARCHITECTURAL EVOLUTION & LEARNING HISTORY:
     * -------------------------------------------------------------------------
     * Previously, we implemented explicit constructor overloading and delegation 
     * (Default, Invincible 2-parameter, and Main 3-parameter constructors). 
     * 
     * They are commented out below for reference, but have been consolidated 
     * into a single "God" constructor using Default Parameter Values. This prevents 
     * compiler ambiguity while retaining 100% of the instantiation flexibility.
     * ========================================================================= */

    // [ARCHIVED] Step 1 & 2: Manual Overloads and Delegating Constructors
    // Player();
    // Player(std::string playerName, int startingHealth);
    // Player(std::string playerName, int startingHealth, int startingXp);

    /**
     * @brief The Ultimate Unified Constructor (Default Parameter Values).
     * 
     * Replaces multiple overloaded variants by leveraging default arguments.
     * Handles 0, 2, or 3 parameters seamlessly during instantiation.
     * 
     * @param playerName The name assigned to the player (defaults to "Unknown NPC").
     * @param startingHealth Initial health pool (defaults to 100).
     * @param startingXp Initial experience points (defaults to 0).
     */
    Player(std::string playerName = "Unknown NPC", int startingHealth = 100, int startingXp = 0);

    /**
     * @brief Outputs a dialogue string to the console.
     * @param text_to_say The text the player will speak.
     */
    void talk(std::string text_to_say) const;

    /**
     * @brief Checks if the player's health has dropped to or below zero.
     * @return True if health is <= 0, otherwise false.
     */
    bool is_dead() const;

    /**
     * @brief Applies damage to the player based on the attacking entity.
     * 
     * Calculates specific damage multipliers depending on the enemy type.
     * If no recognized animal is passed, the player takes zero damage.
     * 
     * @param damage The base damage multiplier.
     * @param animal The type of animal attacking (defaults to "None").
     */
    void damage_taken(int damage, std::string animal = "None");

    /**
     * @brief Destroys the Player object.
     * 
     * Automatically called to clean up resources when the object goes out of scope.
     */
    ~Player();
};