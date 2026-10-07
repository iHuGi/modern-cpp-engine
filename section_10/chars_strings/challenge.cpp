#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key = "xyze";
    
    string password;
    cout << "Enter your password: ";
    getline(cin, password);
    
    string encrypted = "";
    
    for (char c : password) {
        // Find the position of the character in the alphabet
        size_t pos = alphabet.find(c);
        
        if (pos != string::npos) { // If the character is found in the alphabet
            // Use modulo (%) to cycle through the key index 0-3
            encrypted += key[pos % key.length()];
        } else {
            // If it's a special char (like ! or 1), just keep it as is
            encrypted += c;
        }
    }
    
    cout << "\nYour password is: " << password << endl;
    cout << "Your encrypted key is: " << encrypted << endl;
    
    return 0;
}