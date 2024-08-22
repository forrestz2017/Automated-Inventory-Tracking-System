#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include "Transaction.h"

// Class to represent a customer in the movie rental store
class Customer {
private:
    int customerID;            // Unique 4-digit customer ID
    std::string firstName;     // First name of the customer
    std::string lastName;      // Last name of the customer
    std::vector<Transaction*> transactionHistory; // List of transactions associated with the customer

public:
    // Constructor to initialize a customer with an ID, first name, and last name
    Customer(int customerID, const std::string& firstName, const std::string& lastName);

    // Destructor to clean up transaction history
    ~Customer();

    // Function to add a transaction to the customer's history
    void addTransaction(Transaction* transaction);

    // Function to display the transaction history of the customer
    void displayHistory() const;

    // Getter for the customer's ID
    int getCustomerID() const;

    // Getter for the transaction history
    const std::vector<Transaction*>& getTransactionHistory() const;
};

#endif
