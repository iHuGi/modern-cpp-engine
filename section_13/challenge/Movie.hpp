#pragma once
#include <string>

/**
 * @class Movie
 * @brief Models an individual movie with a title, age rating, and watch count.
 */
class Movie {
private:
    std::string title;         /**< The title of the movie. */
    std::string rating;        /**< The age rating of the movie (e.g., G, PG, PG-13, R). */
    int times_watched;         /**< The number of times the movie has been watched. */

public:
    /**
     * @brief Standard Constructor.
     * Initializes a movie object with the provided details.
     * 
     * @param title The name of the movie.
     * @param rating The age rating of the movie.
     * @param times_watched The initial watch count.
     */
    Movie(std::string title, std::string rating, int times_watched);

    /**
     * @brief Copy Constructor (Masterclass: using Constructor Delegation).
     * Clones an existing movie object safely.
     * 
     * @param source The original Movie object being copied.
     */
    Movie(const Movie &source);

    /**
     * @brief Retrieves the movie title.
     * Marked as 'const' to guarantee safety.
     * 
     * @return std::string The title of the movie.
     */
    std::string get_title() const;

    /**
     * @brief Retrieves the age rating of the movie.
     * Marked as 'const' to guarantee safety.
     * 
     * @return std::string The rating string.
     */
    std::string get_rating() const;

    /**
     * @brief Retrieves the current watch count.
     * Marked as 'const' to guarantee safety.
     * 
     * @return int The number of times watched.
     */
    int get_times_watched() const;

    /**
     * @brief Increments the watch count by 1.
     */
    void increment_times_watched();

    /**
     * @brief Displays the movie details to the console.
     * Marked as 'const' to guarantee it will not modify object data.
     */
    void display() const;
};