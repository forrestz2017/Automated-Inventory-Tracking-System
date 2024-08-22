#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Movie.h" // Assuming Transaction uses Movie

class Transaction {
private:
    std::string action; // Action of the transaction ('Borrow' or 'Return')
    Movie* movie;       // Pointer to the movie involved in the transaction

public:
    // Constructor to initialize a transaction with action and movie
    Transaction(const std::string& action, Movie* movie);

    // Getter for the action
    std::string getAction() const;

    // Getter for the movie
    Movie* getMovie() const;

    // Function to display the details of the transaction
    void display() const;
};

#endif
