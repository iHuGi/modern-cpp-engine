#pragma once
#include <vector>
#include <string>
#include "Movie.hpp"

/**
 * @class Movies
 * @brief Manages a collection of Movie objects allocated on the Heap.
 * 
 * Handles adding new movies, checking for duplicates, incrementing watch counts,
 * and displaying the entire collection.
 */
class Movies {
private:
    std::vector<Movie> *movies; /**< Raw pointer allocating the movie vector on the Heap. */

public:
    /**
     * @brief Default Constructor.
     * Allocates the movie vector dynamically on the Heap using 'new'.
     */
    Movies();
    
    /**
     * @brief Destructor.
     * Safely frees the Heap-allocated vector memory using 'delete'.
     */
    ~Movies();

    /**
     * @brief Deep Copy Constructor.
     * Prevents shallow copy corruption by allocating a brand new vector copy from the source.
     * 
     * @param source The original Movies object to copy from.
     */
    Movies(const Movies &source);

    /**
     * @brief Adds a new movie to the collection if it doesn't already exist.
     * 
     * @param title The name of the movie.
     * @param rating The age rating of the movie ("G", "PG", "PG-13", "R").
     * @param times_watched The initial number of times the movie has been watched.
     * @return true if successfully added, false if the movie already exists.
     */
    bool add_movie(std::string title, std::string rating, int times_watched);

    /**
     * @brief Increments the watch count for a specified movie.
     * 
     * @param title The name of the movie to find.
     * @return true if the movie was found and incremented, false otherwise.
     */
    bool increment_watched(std::string title);

    /**
     * @brief Displays all movies in the collection or a notice if empty.
     * Marked as 'const' to guarantee it will not modify collection data.
     */
    void display() const;
};