#include <iostream>
#include <string>
#include <vector>
#include "Movies.hpp"

/**
 * @brief Construct a new Movies:: Movies object (Default Constructor).
 * Dynamically allocates the movie container on the Heap.
 */
Movies::Movies() {
    movies = new std::vector<Movie>;
}

/**
 * @brief Construct a new Movies:: Movies object (Deep Copy Constructor).
 * Allocates a brand new vector on the Heap and copies the underlying elements 
 * from the source to prevent shallow copy pointer corruption.
 * 
 * @param source The original Movies object being copied.
 */
Movies::Movies(const Movies &source) {
    movies = new std::vector<Movie>(*source.movies);
}

/**
 * @brief Destroy the Movies:: Movies object (Destructor).
 * Safely frees the Heap-allocated vector memory to prevent memory leaks.
 */
Movies::~Movies() {
    delete movies;
}

/**
 * @brief Adds a new movie to the collection.
 * Iterates through the collection to check for duplicates before inserting.
 * 
 * @param title The title of the movie.
 * @param rating The age rating of the movie.
 * @param times_watched The initial watch count.
 * @return true if the movie was successfully added, false if it already exists.
 */
bool Movies::add_movie(std::string title, std::string rating, int times_watched) {
    for (const auto &movie : *movies) {
        if (movie.get_title() == title) {
            return false; // Movie already exists; return false so main can handle the warning
        }
    }

    movies->push_back(Movie(title, rating, times_watched));
    return true; // Successfully added
}

/**
 * @brief Increments the watch count for a specific movie in the collection.
 * 
 * @param title The title of the movie to search for.
 * @return true if the movie was found and incremented, false if not found.
 */
bool Movies::increment_watched(std::string title) {
    for (auto &movie : *movies) {
        if (movie.get_title() == title) {
            movie.increment_times_watched();
            return true;
        }
    }
    return false;
}

/**
 * @brief Displays all movies currently stored in the collection.
 * Prints a formatted boundary or a warning message if the vector is empty.
 */
void Movies::display() const {
    if (movies->empty()) {
        std::cout << "Sorry, no movies to display" << std::endl;
        return;
    }

    std::cout << "\n===================================" << std::endl;
    for (const auto &movie : *movies) {
        movie.display();
    }
    std::cout << "===================================\n" << std::endl;
}