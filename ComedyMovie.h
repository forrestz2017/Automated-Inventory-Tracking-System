#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "Movie.h"

// Derived class for Comedy movies, inheriting from the base Movie class
class ComedyMovie : public Movie {
private:
    int releaseYear; // Release year of the comedy movie

public:
    // Constructor to initialize a comedy movie with stock, director, title, and release year
    ComedyMovie(int stock, const std::string& director, const std::string& title, int releaseYear);

    // Destructor
    ~ComedyMovie();

    // Override function to display the details of the comedy movie
    void display() const override;

    // Override function to compare two comedy movies for sorting purposes
    bool operator<(const Movie& other) const override;
};

#endif
