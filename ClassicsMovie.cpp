#include "ClassicsMovie.h"
#include <iostream>

// Constructor for ClassicsMovie, initializing with stock, director, title, major actor, release month, and release year
ClassicsMovie::ClassicsMovie(int stock, const std::string& director, const std::string& title, const std::string& majorActor, int releaseMonth, int releaseYear)
    : Movie('C', stock, director, title), majorActor(majorActor), releaseMonth(releaseMonth), releaseYear(releaseYear) {}

// Destructor
ClassicsMovie::~ClassicsMovie() {}

// Display function to output details of the classics movie
void ClassicsMovie::display() const {
    std::cout << "Classics: " << title << ", Major Actor: " << majorActor << ", Released: " << releaseMonth << "/" << releaseYear << ", Directed by " << director << ", Stock: " << stock << std::endl;
}

// Comparison operator to sort classics movies by release date, then by major actor
bool ClassicsMovie::operator<(const Movie& other) const {
    const ClassicsMovie* otherClassics = dynamic_cast<const ClassicsMovie*>(&other);
    if (otherClassics) {
        if (releaseYear == otherClassics->releaseYear) {
            if (releaseMonth == otherClassics->releaseMonth) {
                return majorActor < otherClassics->majorActor;
            }
            return releaseMonth < otherClassics->releaseMonth;
        }
        return releaseYear < otherClassics->releaseYear;
    }
    return false;
}
