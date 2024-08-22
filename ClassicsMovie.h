#ifndef CLASSICSMOVIE_H
#define CLASSICSMOVIE_H

#include "Movie.h"
#include <string>

// Derived class for Classics movies, inheriting from the base Movie class
class ClassicsMovie : public Movie {
private:
    std::string majorActor; // Major actor in the classics movie
    int releaseMonth;       // Release month of the classics movie
    int releaseYear;        // Release year of the classics movie

public:
    // Constructor to initialize a classics movie with stock, director, title, major actor, release month, and release year
    ClassicsMovie(int stock, const std::string& director, const std::string& title, const std::string& majorActor, int releaseMonth, int releaseYear);

    // Destructor
    ~ClassicsMovie();

    // Override function to display the details of the classics movie
    void display() const override;

    // Override function to compare two classics movies for sorting purposes
    bool operator<(const Movie& other) const override;
};

#endif
