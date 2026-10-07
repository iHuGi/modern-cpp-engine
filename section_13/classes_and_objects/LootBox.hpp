#pragma once
#include <string>

/**
 * @class LootBox
 * @brief A sandbox class designed to master Heap memory, Deep Copying, Move Semantics, and Static Members.
 */
class LootBox {
private:
    /** 
     * @brief Global counter for active LootBoxes. 
     * Shared across all instances (Static).
     */
    static int num_boxes; 
    
    std::string name;    /**< The name of the specific loot box instance. */
    int* item_power;     /**< Raw pointer dynamically allocating power data on the Heap. */

public:
    /**
     * @brief Standard Constructor allocating new memory on the Heap.
     * Increments the static num_boxes counter.
     * 
     * @param box_name The name of the box (defaults to "Standard Box").
     * @param power The integer value stored on the Heap (defaults to 10).
     */
    LootBox(std::string box_name = "Standard Box", int power = 10);

    /**
     * @brief Deep Copy Constructor (The Clone).
     * 
     * Intercepts cloning to prevent Shallow Copy memory corruption.
     * Allocates a brand new memory block for the clone and increments num_boxes.
     * 
     * @param source The original object being cloned (passed by const reference).
     */
    LootBox(const LootBox& source);

    /**
     * @brief Move Constructor (The Heist).
     * 
     * Steals the memory address from a temporary (r-value) object.
     * Lightning fast. Leaves the source object's pointer as nullptr.
     * 
     * @param source The temporary object being stolen from (passed by r-value reference &&).
     */
    LootBox(LootBox&& source) noexcept;

    /**
     * @brief Destructor to safely free Heap memory.
     * 
     * Automatically triggers when the object goes out of scope. 
     * Decrements the static counter and safely handles hollowed-out (nullptr) objects.
     */
    ~LootBox();

    /**
     * @brief Updates the name of the LootBox.
     * Demonstrates the 'this' pointer to resolve naming collisions.
     * 
     * @param name The new name to assign to the box.
     */
    void set_name(std::string name);

    /**
     * @brief Safely prints the contents and the raw memory address.
     * Marked as 'const' to guarantee it will never modify object data.
     */
    void print_info() const;

    /**
     * @brief Retrieves the total number of active LootBoxes.
     * Static method: can be called without instantiating an object.
     * 
     * @return The current value of the static num_boxes counter.
     */
    static int get_num_boxes();
};