#include <iostream>
#include <string>  // Needed for the movie titles and review sources
#include <iomanip> // Needed for setprecision() to format the decimals

using namespace std;

int main() {
    
    // ==========================================
    // 1. STANDARD ARRAY (1D - Single Row)
    // ==========================================
    cout << "--- 1D ARRAY (ACCESS & MODIFY) ---" << endl;
    
    int array_example[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Original array: ";
    for (int each_arr : array_example) {
        cout << each_arr << " "; 
    }
    
    cout << "\n\nChanging index 0 to 100 and index 9 to 999..." << endl;
    
    // Modifying elements by targeting their exact index position
    array_example[0] = 100; 
    array_example[9] = 999; 
    
    cout << "Updated array:  ";
    for (int each_arr : array_example) {
        cout << each_arr << " "; 
    }
    cout << "\n\n=========================================\n\n";


    // ==========================================
    // 2. MULTI-DIMENSIONAL ARRAY (2D - Grid)
    // ==========================================
    cout << "=========================================" << endl;
    cout << "       TOP 10 MOVIE REVIEW DATABASE      " << endl;
    cout << "        (Real World Data Edition)        " << endl;
    cout << "=========================================\n" << endl;

    const int num_reviews = 3;  // Rows
    const int num_movies = 10;  // Columns
    
    // 1D Array for the titles
    const string movie_titles[num_movies] = {
        "Mad Max: Fury Road", "Inception", "The Dark Knight", "Interstellar", "The Matrix",
        "Pulp Fiction", "The Lord of the Rings", "The Shawshank Redemption", "Fight Club", "Forrest Gump"
    };

    // 1D Array to label our rows so the output makes sense
    const string review_sources[num_reviews] = {
        "RT Critics", "RT Audience", "Metacritic "
    };

    // 2D Array using 'double' for decimal scores [Rows][Columns]
    double movie_reviews[num_reviews][num_movies] = {
        // Row 0: Rotten Tomatoes Critic Scores (Converted to 10-point scale)
        {9.7, 8.7, 9.4, 7.3, 8.3, 9.2, 9.4, 8.9, 7.9, 7.1},   
        
        // Row 1: Rotten Tomatoes Audience Scores
        {8.6, 9.1, 9.4, 8.6, 8.5, 9.6, 8.6, 9.8, 9.6, 9.5},   
        
        // Row 2: Metacritic Scores
        {9.0, 7.4, 8.4, 7.4, 7.3, 9.5, 9.4, 8.2, 6.6, 8.2} 
    };

    // --- PRINTING THE DATABASE ---
    for (int col = 0; col < num_movies; col++) {
        
        cout << "Movie: " << movie_titles[col] << endl;
        
        // Inner loop grabs the 3 scores and their source labels
        for (int row = 0; row < num_reviews; row++) {
            
            // fixed << setprecision(1) ensures a score like 9.0 doesn't just print as '9'
            cout << "  - " << review_sources[row] << ": " 
                 << fixed << setprecision(1) << movie_reviews[row][col] << " / 10.0" << endl;
        }
        
        cout << "-----------------------------------------" << endl;
    }

    return 0;
}