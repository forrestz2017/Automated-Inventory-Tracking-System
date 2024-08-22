#include "Inventory.h"
#include <iostream>
#include <algorithm>

// Constructor to initialize an empty inventory
Inventory::Inventory() {}

// Destructor to clean up dynamically allocated movies
Inventory::~Inventory() {
    for (auto& entry : inventory) {
        for (Movie* movie : entry.second) {
            delete movie;
        }
    }
}

// Function to add a movie to the inventory
void Inventory::addMovie(Movie* movie) {
    std::string key = movie->getGenre() + movie->getTitle(); // Create a key for the map based on genre and title
    inventory[key].push_back(movie); // Add the movie to the appropriate vector in the map

    // Sort the vector to maintain order
    std::sort(inventory[key].begin(), inventory[key].end(), [](Movie* a, Movie* b) {
        return *a < *b;
        });
}

// Function to borrow a movie from the inventory, reducing its stock
Movie* Inventory::borrowMovie(const std::string& identifier) {
    if (inventory.find(identifier) != inventory.end()) {
        for (Movie* movie : inventory[identifier]) {
            if (movie->getStock() > 0) {
                movie->decreaseStock(1);
                return movie;
            }
        }
    }
    return nullptr; // Movie not found or out of stock
}

// Function to return a movie to the inventory, increasing its stock
void Inventory::returnMovie(Movie* movie) {
    if (movie) {
        movie->increaseStock(1);
    }
    else {
        std::cerr << "Error: Attempt to return a non-existent movie." << std::endl;
    }
}

// Function to display the entire inventory, sorted by genre and then by sorting criteria
void Inventory::displayInventory() const {
    for (const auto& entry : inventory) {
        for (const Movie* movie : entry.second) {
            movie->display(); // Display each movie's details
        }
    }
}
