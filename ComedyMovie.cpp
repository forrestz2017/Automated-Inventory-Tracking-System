#include "ComedyMovie.h"
#include <iostream>

// Constructor for ComedyMovie, initializing with stock, director, title, and release year
ComedyMovie::ComedyMovie(int stock, const std::string& director, const std::string& title, int releaseYear)
    : Movie('F', stock, director, title), releaseYear(releaseYear) {}

// Destructor
ComedyMovie::~ComedyMovie() {}

// Display function to output details of the comedy movie
void ComedyMovie::display() const {
    std::cout << "Comedy: " << title << " (" << releaseYear << "), Directed by " << director << ", Stock: " << stock << std::endl;
}

// Comparison operator to sort comedy movies by title, then by release year
bool ComedyMovie::operator<(const Movie& other) const {
    const ComedyMovie* otherComedy = dynamic_cast<const ComedyMovie*>(&other);
    if (otherComedy) {
        if (title == otherComedy->title) {
            return releaseYear < otherComedy->releaseYear;
        }
        return title < otherComedy->title;
    }
    return false;
}
