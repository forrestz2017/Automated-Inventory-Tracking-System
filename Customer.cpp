#include "Customer.h"
#include <iostream>

// Constructor to initialize a customer with ID, first name, and last name
Customer::Customer(int customerID, const std::string& firstName, const std::string& lastName)
    : customerID(customerID), firstName(firstName), lastName(lastName) {}

// Destructor to clean up dynamically allocated transactions in the customer's history
Customer::~Customer() {
    for (Transaction* transaction : transactionHistory) {
        delete transaction;
    }
}

// Function to add a transaction to the customer's history
void Customer::addTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}

// Function to display the customer's transaction history
void Customer::displayHistory() const {
    std::cout << "Customer " << customerID << " - " << firstName << " " << lastName << std::endl;
    for (Transaction* transaction : transactionHistory) {
        transaction->display();
    }
}

// Getter for the customer's ID
int Customer::getCustomerID() const {
    return customerID;
}

// Getter for the transaction history
const std::vector<Transaction*>& Customer::getTransactionHistory() const {
    return transactionHistory;
}
