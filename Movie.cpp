#include "Movie.h"

// Constructor to initialize a movie with genre, stock, director, and title
Movie::Movie(char genre, int stock, const std::string& director, const std::string& title)
    : genre(genre), stock(stock), director(director), title(title) {}

// Virtual destructor
Movie::~Movie() {}

// Getter for the genre of the movie
char Movie::getGenre() const {
    return genre;
}

// Getter for the title of the movie
std::string Movie::getTitle() const {
    return title;
}

// Getter for the director of the movie
std::string Movie::getDirector() const {
    return director;
}

// Getter for the stock of the movie
int Movie::getStock() const {
    return stock;
}

// Function to increase the stock of the movie
void Movie::increaseStock(int amount) {
    stock += amount;
}

// Function to decrease the stock of the movie
void Movie::decreaseStock(int amount) {
    stock -= amount;
}
