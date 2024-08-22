#include "DramaMovie.h"
#include <iostream>

// Constructor for DramaMovie, initializing with stock, director, and title
DramaMovie::DramaMovie(int stock, const std::string& director, const std::string& title)
    : Movie('D', stock, director, title) {}

// Destructor
DramaMovie::~DramaMovie() {}

// Display function to output details of the drama movie
void DramaMovie::display() const {
    std::cout << "Drama: " << title << ", Directed by " << director << ", Stock: " << stock << std::endl;
}

// Comparison operator to sort drama movies by director, then by title
bool DramaMovie::operator<(const Movie& other) const {
    const DramaMovie* otherDrama = dynamic_cast<const DramaMovie*>(&other);
    if (otherDrama) {
        if (director == otherDrama->director) {
            return title < otherDrama->title;
        }
        return director < otherDrama->director;
    }
    return false;
}
