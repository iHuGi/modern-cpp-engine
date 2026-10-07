#include <iostream>

using namespace std;

int main() {
    
    // --- CONSTANTS ---
    const double price_per_room_small {25.0}; 
    const double price_per_room_large {35.0};
    const double tax_rate {0.06}; 
    const int estimate_expiry {30}; 

    // --- INPUT ---
    int num_small_rooms {0};
    cout << "Enter the number of small rooms: ";
    cin >> num_small_rooms;

    int num_large_rooms {0};
    cout << "Enter the number of large rooms: ";
    cin >> num_large_rooms;

    // --- CALCULATIONS ---
    // Using parentheses around the multiplication makes it much easier to read
    double total_cost { (num_small_rooms * price_per_room_small) + 
                        (num_large_rooms * price_per_room_large) };
    
    double tax_amount {total_cost * tax_rate};
    double grand_total {total_cost + tax_amount};

    // --- OUTPUT ---
    cout << "\nEstimate for room cleaning service" << endl;
    cout << "Number of small rooms: " << num_small_rooms << endl;
    cout << "Number of large rooms: " << num_large_rooms << endl;
    
    cout << "Price per small room: $" << price_per_room_small << endl;
    cout << "Price per large room: $" << price_per_room_large << endl;

    cout << "Cost: $" << total_cost << endl;
    cout << "Tax: $" << tax_amount << endl;

    cout << "===============================" << endl;
    cout << "Total estimate: $" << grand_total << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days." << endl;

    return 0;
}