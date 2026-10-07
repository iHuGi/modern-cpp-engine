/******************************************************************************
 * @file main.cpp
 * @brief Enterprise-grade test driver for the Movies and Movie OOP system.
 * @author Hugo Azevedo
 * 
 * Demonstrates encapsulation, deep copy memory management, and robust 
 * collection orchestration adhering to modern C++ standards.
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Movie.hpp"
#include "Movies.hpp"

// ============================================================================
// HELPER FUNCTIONS (Encapsulated Testing Utilities)
// ============================================================================

/**
 * @brief Safely attempts to add a movie to the collection and logs the outcome.
 * 
 * @reference A reference to the active Movies collection manager.
 * @param title The title of the movie.
 * @param rating The age rating of the movie.
 * @param watched Initial watch count.
 */
void safe_add_movie(Movies &collection, const std::string &title, const std::string &rating, int watched) {
    std::cout << "[CMD] Attempting to add: \"" << title << "\" ... ";
    if (collection.add_movie(title, rating, watched)) {
        std::cout << "[SUCCESS] Added." << std::endl;
    } else {
        std::cout << "[ERROR] Failed. Movie already exists in the registry." << std::endl;
    }
}

/**
 * @brief Safely attempts to increment a movie's watch count and logs the outcome.
 * 
 * @reference A reference to the active Movies collection manager.
 * @param title The title of the movie to find and update.
 */
void safe_increment_watched(Movies &collection, const std::string &title) {
    std::cout << "[CMD] Incrementing watch count for: \"" << title << "\" ... ";
    if (collection.increment_watched(title)) {
        std::cout << "[SUCCESS] Watch count incremented." << std::endl;
    } else {
        std::cout << "[ERROR] Failed. Movie not found in the registry." << std::endl;
    }
}

// ============================================================================
// MAIN EXECUTION PIPELINE
// ============================================================================

int main() {
    // Enable standard I/O performance optimizations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "==================================================\n";
    std::cout << "         MOVIES SYSTEM INTEGRATION TEST           \n";
    std::cout << "==================================================\n\n";

    try {
        // Instantiate the collection manager (RAII compliant)
        Movies movie_collection;

        // 1. Initial State Verification (Should report empty)
        std::cout << "--- Phase 1: Checking Empty State ---" << std::endl;
        movie_collection.display();

        // 2. Populate Initial Dataset
        std::cout << "\n--- Phase 2: Populating Initial Registry ---" << std::endl;
        safe_add_movie(movie_collection, "The Shawshank Redemption", "R", 4);
        safe_add_movie(movie_collection, "The Dark Knight", "PG-13", 8);
        safe_add_movie(movie_collection, "Interstellar", "PG-13", 5);

        movie_collection.display();

        // 3. Test Duplicate Prevention Guardrails
        std::cout << "\n--- Phase 3: Testing Duplicate Validation ---" << std::endl;
        safe_add_movie(movie_collection, "The Dark Knight", "PG-13", 2); // Should trigger duplicate error

        // 4. Test Watch Count Increments
        std::cout << "\n--- Phase 4: Testing State Mutation (Increments) ---" << std::endl;
        safe_increment_watched(movie_collection, "Interstellar");
        safe_increment_watched(movie_collection, "The Shawshank Redemption");

        movie_collection.display();

        // 5. Test Negative/Error Handling (Non-existent entity)
        std::cout << "\n--- Phase 5: Error Handling (Missing Entities) ---" << std::endl;
        safe_increment_watched(movie_collection, "NonExistentMovie_2026");

        std::cout << "\n==================================================" << std::endl;
        std::cout << "        TEST PIPELINE EXECUTED SUCCESSFULLY       " << std::endl;
        std::cout << "==================================================" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "[CRITICAL EXCEPTION] Unhandled error caught in main: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "[CRITICAL EXCEPTION] Unknown non-standard exception caught." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}