#include "HashTable.h"

// Constructor to initialize a hash table of a given size
HashTable::HashTable(int size)
    : table(size, nullptr) {}

// Destructor to clean up dynamically allocated items in the hash table
HashTable::~HashTable() {
    for (Customer* item : table) {
        delete item; // Delete each item in the hash table
    }
}

// Hash function to generate an index from a string key
int HashTable::hashFunction(const std::string& key) const {
    int hash = 0;
    for (char c : key) {
        hash = hash * 31 + c; // Simple hash function based on character values
    }
    return hash % table.size(); // Modulo to ensure index is within table size
}

// Function to insert an item into the hash table using a key
void HashTable::insert(const std::string& key, Customer* item) {
    int index = hashFunction(key);
    table[index] = item; // Insert the item at the calculated index
}

// Function to search for an item in the hash table by key
Customer* HashTable::search(const std::string& key) const {
    int index = hashFunction(key);
    return table[index]; // Return the item found at the calculated index
}

// Function to remove an item from the hash table by key
void HashTable::remove(const std::string& key) {
    int index = hashFunction(key);
    delete table[index]; // Delete the item at the calculated index
    table[index] = nullptr; // Set the table entry to null
}
