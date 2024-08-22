#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include "Customer.h"

// Class to implement a hash table for quick lookup of customers
class HashTable {
private:
    std::vector<Customer*> table; // Vector to store pointers to Customer objects, implementing the hash table
    int hashFunction(const std::string& key) const; // Hash function to generate index from a string key

public:
    // Constructor to initialize a hash table of a given size
    HashTable(int size);

    // Destructor to clean up dynamically allocated items in the hash table
    ~HashTable();

    // Function to insert an item into the hash table using a key
    void insert(const std::string& key, Customer* item);

    // Function to search for an item in the hash table by key
    Customer* search(const std::string& key) const;

    // Function to remove an item from the hash table by key
    void remove(const std::string& key);
};

#endif
