#ifndef MOVIE_H
#define MOVIE_H

#include <string>

// Abstract base class for all types of movies
class Movie {
protected:
    char genre;           // Genre of the movie ('F' for Comedy, 'D' for Drama, 'C' for Classics)
    int stock;            // Number of copies available in the inventory
    std::string director; // Director of the movie
    std::string title;    // Title of the movie

public:
    // Constructor to initialize common movie attributes
    Movie(char genre, int stock, const std::string& director, const std::string& title);

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Movie();

    // Pure virtual function to display movie details, to be implemented by derived classes
    virtual void display() const = 0;

    // Pure virtual function to compare movies for sorting purposes
    virtual bool operator<(const Movie& other) const = 0;

    // Getter for the genre of the movie
    char getGenre() const;

    // Getter for the title of the movie
    std::string getTitle() const;

    // Getter for the director of the movie
    std::string getDirector() const;

    // Getter for the number of copies available
    int getStock() const;

    // Function to increase the stock of the movie
    void increaseStock(int amount);

    // Function to decrease the stock of the movie
    void decreaseStock(int amount);
};

#endif
