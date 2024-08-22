#ifndef INVENTORY_H
#define INVENTORY_H

#include "Movie.h"
#include <vector>
#include <map>
#include <string>

// Class to manage the inventory of movies in the rental store
class Inventory {
private:
    std::map<std::string, std::vector<Movie*>> inventory; // Map to store movies by genre and title

public:
    // Constructor to initialize an empty inventory
    Inventory();

    // Destructor to clean up dynamically allocated movies
    ~Inventory();

    // Function to add a movie to the inventory
    void addMovie(Movie* movie);

    // Function to borrow a movie from the inventory, reducing its stock
    Movie* borrowMovie(const std::string& identifier);

    // Function to return a movie to the inventory, increasing its stock
    void returnMovie(Movie* movie);

    // Function to display the entire inventory, sorted by genre and then by sorting criteria
    void displayInventory() const;
};

#endif
