#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    vector<int> numbers {};
    char choice {};
    
    do {
        // Display menu options cleanly
        cout << "\n=========================" << endl;
        cout << " P - Print numbers" << endl;
        cout << " A - Add a number" << endl;
        cout << " M - Display mean" << endl;
        cout << " S - Display smallest" << endl;
        cout << " L - Display largest" << endl;
        cout << " Q - Quit" << endl;
        cout << "=========================" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        choice = tolower(choice); // Standardize input
        
        cout << "\n"; 

        switch (choice) {
            case 'p': {
                if (numbers.empty()) {
                    cout << ">> [] - The list is empty." << endl;
                } else {
                    cout << ">> [ ";
                    for (int num : numbers) {
                        cout << num << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            }
            case 'a': {
                int new_number {};
                cout << "Enter an integer to add: ";
                cin >> new_number;
                
                if (cin.fail()) {
                    cout << ">> ERROR: Invalid data type. Please enter numbers only." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    numbers.push_back(new_number);
                    cout << ">> " << new_number << " added successfully." << endl;
                }
                break;
            }
            case 'm': {
                if (numbers.empty()) {
                    cout << ">> ERROR: Mean cannot be calculated - no data." << endl;
                } else {
                    double total {0};
                    for (int num : numbers) {
                        total += num;
                    }
                    cout << ">> Mean = " << (total / numbers.size()) << endl;
                }
                break;
            }
            case 's': {
                if (numbers.empty()) {
                    cout << ">> ERROR: Smallest cannot be determined - no data." << endl;
                } else {
                    int smallest {numbers.at(0)};
                    for (int num : numbers) {
                        if (num < smallest) {
                            smallest = num;
                        }
                    }
                    cout << ">> Smallest number = " << smallest << endl;
                }
                break;
            }
            case 'l': {
                if (numbers.empty()) {
                    cout << ">> ERROR: Largest cannot be determined - no data." << endl;
                } else {
                    int largest {numbers.at(0)};
                    for (int num : numbers) {
                        if (num > largest) {
                            largest = num;
                        }
                    }
                    cout << ">> Largest number = " << largest << endl;
                }
                break;
            }
            case 'q': {
                cout << ">> SYSTEM: Shutting down safely. Goodbye!" << endl;
                break;
            }
            default: {
                cout << ">> ERROR: Unknown selection. Please try again." << endl;
            }
        }
    } while (choice != 'q');
    
    return 0;
}