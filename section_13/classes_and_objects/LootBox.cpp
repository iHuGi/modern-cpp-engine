#include <iostream>
#include "LootBox.hpp"

// 1. Initialize the shared static member variable (Always outside the constructors!)
int LootBox::num_boxes = 0; 

// =========================================================================
// STANDARD CONSTRUCTOR
// =========================================================================
LootBox::LootBox(std::string box_name, int power)
    : name{box_name} {
        item_power = new int; // 1. Allocate raw memory on the Heap
        *item_power = power;  // 2. Dereference to store the actual value
        
        num_boxes++;          // INCREMENT: A new loot box has been created!
        
        std::cout << "[HEAP] Created: " << name << " | Address: " << item_power << "\n";
}

// =========================================================================
// DEEP COPY CONSTRUCTOR 
// =========================================================================
LootBox::LootBox(const LootBox& source)
    : name(source.name + " Clone") {
        item_power = new int;             // 1. Allocate a BRAND NEW memory block
        *item_power = *source.item_power; // 2. Copy the VALUE, not the address
        
        num_boxes++;                      // INCREMENT: The clone also counts as a box!
        
        std::cout << "[HEAP] Deep Copy Constructor fired for: " << name << " | New Address: " << item_power << "\n";
}

// =========================================================================
// MOVE CONSTRUCTOR (THE HEIST)
// =========================================================================
LootBox::LootBox(LootBox&& source) noexcept
    : name(source.name + " (Stolen)") {
        item_power = source.item_power; // 1. Steal the memory address
        source.item_power = nullptr;    // 2. Nullify the victim's pointer!
        
        num_boxes++;                    // INCREMENT: Even by stealing memory, a new object wrapper is formed.
        
        std::cout << "[HEAP] Move Constructor (Heist successful) for: " << name << "\n";
}

// =========================================================================
// 'THIS' POINTER DEMONSTRATION
// =========================================================================
void LootBox::set_name(std::string name) {
    this->name = name; // Resolves naming collision between class member and parameter
    std::cout << "[SYSTEM] Name updated at object address: " << this << "\n";
}

// =========================================================================
// DESTRUCTOR
// =========================================================================
LootBox::~LootBox() {
    if (item_power != nullptr) {
        std::cout << "[HEAP] Destroying: " << name << " | Freeing Address: " << item_power << "\n";
        delete item_power;
    } else {
        std::cout << "[HEAP] Destroying hollowed-out object: " << name << " (Memory was stolen!)\n";
    }
    
    num_boxes--; // DECREMENT: Box destroyed, reduce total active count.
}

// =========================================================================
// HELPER METHODS
// =========================================================================
void LootBox::print_info() const {
    if (item_power != nullptr) {
        std::cout << "-> " << name << " contains power: " << *item_power 
                  << " [Stored safely at RAM address: " << item_power << "]\n";
    } else {
        std::cout << "-> " << name << " is EMPTY. Its memory was stolen!\n";
    }
}

// =========================================================================
// STATIC GETTER
// =========================================================================
int LootBox::get_num_boxes() {
    return num_boxes; // Returns the global shared value across all instances.
}