#include <iostream>
#include <vector> // Required for dynamic arrays (vectors)

using namespace std;

int main() {
    
    // =======================================================
    // PART 1: 1D VECTORS (Single List)
    // =======================================================
    cout << "--- 1D VECTOR FOUNDATIONS ---" << endl;
    
    // Initialize a vector with 3 starting scores
    vector<int> high_scores {95, 82, 74};
    
    // SAFE MODIFICATION: We use .at() instead of standard brackets [].
    // WHY? If a junior accidentally types high_scores.at(10), C++ will throw a clear 
    // "out of bounds" error. If they use high_scores[10], it crashes silently or corrupts memory.
    high_scores.at(1) = 88; 

    // DYNAMIC GROWTH: push_back() creates a new slot at the end and drops the data in.
    // This is the main advantage of vectors over raw arrays.
    high_scores.push_back(105); 
    high_scores.push_back(120);

    // pop_back() destroys the very last element in the vector.
    high_scores.pop_back(); 

    cout << "Current 1D Scoreboard: ";
    for (int score : high_scores) {
        cout << score << " ";
    }
    cout << "\nTotal games tracked: " << high_scores.size() << "\n\n";


    // =======================================================
    // PART 2: 2D VECTORS (Dynamic Grid)
    // =======================================================
    cout << "--- 2D VECTOR GRID CHALLENGE ---" << endl;

    // Step 1: Create two separate 1D vectors
    vector<int> vector1;
    vector<int> vector2;

    // Step 2: Populate them (Notice they can be different sizes!)
    vector1.push_back(10);
    vector1.push_back(20);
    vector1.push_back(30);

    vector2.push_back(40);
    vector2.push_back(50);
    
    // Step 3: Create the 2D Vector (A vector that holds other vectors)
    vector<vector<int>> vector_2d;
    
    // Step 4: Push our 1D vectors into the 2D vector as rows
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    // Step 5: Modify specific grid coordinates
    // Syntax: .at(row).at(column)
    vector_2d.at(0).at(0) = 100;  // Changes the 10 in vector1 to 100
    vector_2d.at(1).at(0) = 1000; // Changes the 40 in vector2 to 1000
    
    
    // --- PRINTING THE DYNAMIC GRID ---
    cout << "Final 2D Grid Output:" << endl;

    // OUTER LOOP: Iterates through the rows (vector1, then vector2)
    for (size_t i = 0; i < vector_2d.size(); i++) {
        
        // INNER LOOP: Iterates through the columns of the current row
        // CRITICAL LOGIC: We use `vector_2d.at(i).size()` instead of a fixed number.
        // WHY? Because vector1 has 3 items, but vector2 only has 2 items! 
        // This prevents the program from crashing by checking the exact size of each specific row.
        for (size_t j = 0; j < vector_2d.at(i).size(); j++) {
            
            cout << vector_2d.at(i).at(j) << " ";
        }
        
        // Drops to the next line after finishing a row to visually create the grid
        cout << endl; 
    }

    return 0;
}