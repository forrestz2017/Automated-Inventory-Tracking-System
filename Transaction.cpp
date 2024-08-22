#include "Transaction.h"
#include <iostream>

// Constructor to initialize a transaction with an action and a pointer to the movie involved
Transaction::Transaction(const std::string& action, Movie* movie)
    : action(action), movie(movie) {}

// Getter for the action of the transaction
std::string Transaction::getAction() const {
    return action;
}

// Getter for the movie involved in the transaction
Movie* Transaction::getMovie() const {
    return movie;
}

// Function to display the details of the transaction (borrow or return)
void Transaction::display() const {
    std::cout << action << " - ";
    movie->display();
}
