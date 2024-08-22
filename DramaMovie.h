#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"

// Derived class for Drama movies, inheriting from the base Movie class
class DramaMovie : public Movie {
public:
    // Constructor to initialize a drama movie with stock, director, and title
    DramaMovie(int stock, const std::string& director, const std::string& title);

    // Destructor
    ~DramaMovie();

    // Override function to display the details of the drama movie
    void display() const override;

    // Override function to compare two drama movies for sorting purposes
    bool operator<(const Movie& other) const override;
};

#endif
