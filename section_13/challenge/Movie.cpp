#include <iostream>
#include <string>
#include "Movie.hpp"

/**
 * @brief Construct a new Movie:: Movie object (Standard Constructor).
 * Initializes the member variables using an initialization list.
 * 
 * @param title The title of the movie.
 * @param rating The age rating of the movie.
 * @param times_watched The initial watch count.
 */
Movie::Movie(std::string title, std::string rating, int times_watched)
    : title{title}, rating{rating}, times_watched{times_watched} {
    std::cout << "Movie constructor called for: " << title << std::endl;
}

/**
 * @brief Construct a new Movie:: Movie object (Copy Constructor).
 * Masterclass technique: delegates construction to the standard constructor.
 * 
 * @param source The original Movie object being copied.
 */
Movie::Movie(const Movie &source)
    : Movie{source.title, source.rating, source.times_watched} {
    std::cout << "Movie copy constructor called for: " << source.title << std::endl;
}

/**
 * @brief Retrieves the movie title.
 * 
 * @return std::string The title string.
 */
std::string Movie::get_title() const {
    return title;
}

/**
 * @brief Retrieves the movie age rating.
 * 
 * @return std::string The rating string.
 */
std::string Movie::get_rating() const {
    return rating;
}

/**
 * @brief Retrieves the number of times the movie has been watched.
 * 
 * @return int The watch count.
 */
int Movie::get_times_watched() const {
    return times_watched;
}

/**
 * @brief Increments the watch counter by 1.
 */
void Movie::increment_times_watched() {
    ++times_watched;
}

/**
 * @brief Prints the formatted movie details to the standard output.
 * Format: Title (Rating) - X times watched
 */
void Movie::display() const {
    std::cout << title << " (" << rating << ") - " << times_watched << " times watched" << std::endl;
}