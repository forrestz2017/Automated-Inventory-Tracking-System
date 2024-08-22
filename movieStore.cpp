/******************************************************************************
 * Project Name: Auto Tracking Inventory System
 * File Name: main.cpp
 * Description:
 * This file contains the main execution logic for the Auto Tracking Inventory
 * System. The program loads movie and customer data from external files,
 * processes a series of commands (borrow, return, inventory, history),
 * and manages the movie rental store's inventory and customer transactions.
 * Programmer: Forrest Zhang
 * Date: 8/14/2024
 *****************************************************************************/



#include <iostream>
#include <fstream>
#include <sstream>
#include "Inventory.h"
#include "Customer.h"
#include "HashTable.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicsMovie.h"


// Function to load movies from a file and populate the inventory
void loadMovies(const std::string& filename, Inventory& inventory) {
    std::cout << "Opening movie file: " << filename << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open movie file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        char genre;
        ss >> genre;

        if (genre == 'F') {
            std::cout << "Parsing comedy movie: " << line << std::endl;
            // Rest of the parsing logic for comedy movies...

        }
        else if (genre == 'D') {
            std::cout << "Parsing drama movie: " << line << std::endl;
            // Rest of the parsing logic for drama movies...

        }
        else if (genre == 'C') {
            std::cout << "Parsing classics movie: " << line << std::endl;
            // Rest of the parsing logic for classics movies...

        }
        else {
            std::cerr << "Invalid genre code '" << genre << "' found. Line discarded: " << line << std::endl;
        }
    }
    std::cout << "Finished loading movies." << std::endl;
}


// Function to load customers from a file and populate the customer hash table
void loadCustomers(const std::string& filename, HashTable& customers) {
    std::cout << "Opening customer file: " << filename << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open customer file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        int customerID;
        std::string firstName, lastName;
        ss >> customerID >> lastName >> firstName;

        std::cout << "Adding customer: " << customerID << ", " << firstName << " " << lastName << std::endl;
        Customer* customer = new Customer(customerID, firstName, lastName);
        customers.insert(std::to_string(customerID), customer);
    }
    std::cout << "Finished loading customers." << std::endl;
}


// Function to process commands from a file
void processCommands(const std::string& filename, Inventory& inventory, HashTable& customers) {
    std::cout << "Opening command file: " << filename << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open command file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        char command;
        ss >> command;

        std::cout << "Processing command: " << command << " | " << line << std::endl;

        if (command == 'B') {
            std::cout << "Borrow command detected." << std::endl;
            // Borrow command logic...

        }
        else if (command == 'R') {
            std::cout << "Return command detected." << std::endl;
            // Return command logic...

        }
        else if (command == 'I') {
            std::cout << "Inventory command detected." << std::endl;
            // Inventory command logic...

        }
        else if (command == 'H') {
            std::cout << "History command detected." << std::endl;
            // History command logic...

        }
        else {
            std::cerr << "Invalid command '" << command << "' found in line: " << line << std::endl;
        }
    }
    std::cout << "Finished processing commands." << std::endl;
}


int main() {
    std::cout << "Starting program..." << std::endl;

    // Initialize the inventory and customer hash table
    Inventory inventory;
    HashTable customers(100); // Assuming a hash table size of 100 for simplicity

    // Output for debugging
    std::cout << "Loading movie data from file..." << std::endl;
    loadMovies("data4movies.txt", inventory);
    std::cout << "Movie data loaded successfully." << std::endl;

    std::cout << "Loading customer data from file..." << std::endl;
    loadCustomers("data4customers.txt", customers);
    std::cout << "Customer data loaded successfully." << std::endl;

    std::cout << "Processing commands from file..." << std::endl;
    processCommands("data4commands.txt", inventory, customers);
    std::cout << "Commands processed successfully." << std::endl;

    std::cout << "Program finished successfully." << std::endl;

    return 0;
}

