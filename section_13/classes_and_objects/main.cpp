#include <iostream>
#include <vector>
#include <string>
#include "PlayerClass.hpp"
#include "Account.hpp"
#include "LootBox.hpp"

int main() {
    // ============================================
    // 1. DECLARING A CLASS AND CREATING OBJECTS AND ACCESSING CLASS MEMBERS
    // ============================================

    // ============================================
    // 1.1 CLASS PLAYER
    // ============================================

    std::cout << "1. Declaring a class and creating objects \n" << std::endl;

    // Calls the Default Constructor (0 args)
    Player NpcPlayer;
    
    // Calls the Invincible Constructor (2 args)
    Player Admin("Super Admin", 5000);

    // Calls the Main Constructor (3 args)
    Player Hugo("Hugo Azevedo", 100, 0);
    Player Pedro("Pedro Relvas", 100, 0);

    // Define dialogue strings
    std::string hugo_text = "Bro, Cpp is fast as hell uh!?";
    std::string pedro_text = "Yeah bro, i need to level my cpp!!";

    // Call class methods via the dot operator
    Hugo.talk(hugo_text);
    Pedro.talk(pedro_text);

    // Apply combat mechanics and test default arguments
    Hugo.damage_taken(5, "Zebra");
    Pedro.damage_taken(20, "Lion");

    // Evaluate object state using ternary operators
    Hugo.is_dead() ? std::cout << "Hugo is dead!" << std::endl : std::cout << "Hugo is alive!" << std::endl;
    Pedro.is_dead() ? std::cout << "Pedro is dead!" << std::endl : std::cout << "Pedro is alive!" << std::endl;

    // ============================================
    // 1.2 CLASS ACCOUNT
    // ============================================

    std::cout << "\n";

    // Instantiate accounts with an initial balance
    Account HugoAccount("Hugo Azevedo", 1000.0);
    Account PedroAccount("Pedro Relvas", 1000.0);

    // Accessing class members via dot operator to get names
    HugoAccount.get_name();
    PedroAccount.get_name();

    // Check initial balances
    HugoAccount.check_current_balance();
    PedroAccount.check_current_balance();

    // Process deposits
    HugoAccount.add(500.0);
    PedroAccount.add(1000.0);

    // Check balances after deposits
    HugoAccount.check_current_balance();
    PedroAccount.check_current_balance();

    // Process withdrawals (Hugo attempts overdraw, Pedro succeeds)
    HugoAccount.withdraw(2000.0); // CANNOT
    PedroAccount.withdraw(500.0);

    // Final balance check
    HugoAccount.check_current_balance();
    PedroAccount.check_current_balance();

    // ============================================
    // 2. PUBLIC VS PRIVATE ACCESS MODIFIERS
    // ============================================

    std::cout << "\n2. Public vs Private Access Modifiers" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Theory in codebase comments." << std::endl;
    // NOTE: Our classes above already implemented private and public access modifiers, but let's illustrate the concept further.
    /*
    ====================================================================================
    [THEORY CHEATSHEET] - OOP ACCESS MODIFIERS (Public, Private, Protected)
    ====================================================================================
    The golden rule of Encapsulation: Lock the data in the vault, use methods to read/modify it.

    -> public:    THE FRONT DOOR (Free Access)
                  Any external file (like this main.cpp) can call these functions.
                  It is the control panel you let others use.
                  Ex: withdraw(), damage_taken()

    -> private:   THE VAULT (Restricted Access) -> DEFAULT IN C++ CLASSES
                  Only the methods defined INSIDE the class can read or modify this.
                  If the main tries to do `Hugo.health = 5000;`, the compiler throws a critical error.
                  Ex: current_amount, health, name

    -> protected: THE FAMILY BUSINESS (VIP Access via Inheritance)
                  For main.cpp, it works exactly like 'private' (it is blocked).
                  BUT it allows "child" classes to have access. 
                  Ex: If in the future you create a 'Boss' class that inherits from 'Player', 
                      the 'Boss' will be able to access these variables directly.
    ====================================================================================
    */

    std::cout << "\n3. Destructor Demonstration" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "When the main function ends, all objects go out of scope and their destructors are automatically called." << std::endl;
    std::cout << "Check the console output for destructor messages." << std::endl;
    
   // ============================================
    // 4. COPY CONSTRUCTORS, MOVE SEMANTICS & STATIC MEMBERS
    // ============================================

    std::cout << "\n4. Copying, Moving and Dynamic Memory Management" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "[WARNING] The training wheels are off. Entering the Heap.\n";

    // Check initial state of the static counter (Should be 0 if no boxes exist yet)
    std::cout << "[STATIC CHECK] Active LootBoxes in memory: " << LootBox::get_num_boxes() << "\n";

    // 1. Create the original box on the Heap
    LootBox EpicBox("Epic Sword Box", 99);
    std::cout << "[STATIC CHECK] Active LootBoxes in memory: " << LootBox::get_num_boxes() << "\n";
    EpicBox.print_info();

    std::cout << "\n--- Initiating Cloning Sequence (Deep Copy) ---\n";
    
    // 2. Clone the box (Triggers Deep Copy Constructor, allocates new RAM and increments static counter)
    LootBox ClonedBox{EpicBox};
    ClonedBox.print_info();
    std::cout << "[STATIC CHECK] Active LootBoxes in memory: " << LootBox::get_num_boxes() << "\n";
    
    std::cout << "\n--- Initiating Move Sequence (The Heist) ---\n";
    
    // 3. The Move! We use std::move() to cast ClonedBox into an r-value (a stealable target)
    // This triggers the Move Constructor, stealing the memory address without extra allocation.
    LootBox MoveBox = std::move(ClonedBox);
    std::cout << "[STATIC CHECK] Active LootBoxes in memory: " << LootBox::get_num_boxes() << "\n";
    
    // Demonstrate the 'this' pointer by updating the name of the stolen box
    MoveBox.set_name("Ultimate Stolen Box");
    
    // Inspect the damage: MoveBox holds the memory, ClonedBox is hollowed out (nullptr)
    std::cout << "\n--- Inspecting Object States Post-Heist ---\n";
    MoveBox.print_info();
    ClonedBox.print_info(); // Will gracefully report that its memory was stolen

    std::cout << "\n--- End of Main: Destructors Incoming ---\n";
    std::cout << "[STATIC CHECK] Total active boxes before scope exit: " << LootBox::get_num_boxes() << "\n";
    
    // When main() finishes, MoveBox, ClonedBox, and EpicBox will go out of scope 
    // in reverse order, automatically calling their destructors, freeing the heap, 
    // and decrementing the static counter down to 0.
    return 0;
}