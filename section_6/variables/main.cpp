#include <iostream>

using namespace std;

int main() {
    // Print the title of the program
    cout << "** Calculating Room Area **" << endl;

    // Prompt the user for the width
    cout << "Enter the width of the room: ";
    
    // Initialize the width variable to 0 to prevent garbage data
    int room_width {0}; 
    
    // Store the user's input into the width variable
    cin >> room_width;

    // Prompt the user for the length
    cout << "Enter the length of the room: ";
    
    // Initialize the length variable to 0
    int room_length {0}; 
    
    // Store the user's input into the length variable
    cin >> room_length;

    // Calculate the area inline and display the final output
    cout << "The area of the room is: " << (room_width * room_length) << " square feet" << endl;

    // Return 0 to indicate the program ran successfully
    return 0;
}