/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file HashTable.hpp
 * @brief Hash Table implementation of a key/value dictionary. Uses linked lists to handle collisions.
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename KEY_TYPE, typename VALUE_TYPE>
struct HashTableNode
{
    KEY_TYPE key;
    VALUE_TYPE value;
    HashTableNode<KEY_TYPE, VALUE_TYPE>* next;
};

template<typename KEY_TYPE, typename VALUE_TYPE>
class HashTable
{
    public:
        // Constructor
        HashTable(size_t tableSize = 100, int (*hashFunction)(KEY_TYPE) = nullptr)
        {
            // Initialize the table and internal variables
            table = new HashTableNode<KEY_TYPE, VALUE_TYPE>*[tableSize];
            for (size_t i = 0; i < tableSize; i++) table[i] = nullptr;
            this->numberOfElements = 0;
            this->tableArrayCapacity = tableSize;

            // Set the hash function
            if (hashFunction == null) this->hashFunction = jenkinsHashFunction;
            else this->hashFunction = hashFunction;
        }

        // Destructor
        ~HashTable()
        {
            // Delete all elements in the table
            clear();

            // Delete the table
            delete[] table;
        }

        // Inserts a key/value pair into the table. If the key already exists, the value will be overwritten.
        void insert(KEY_TYPE key, VALUE_TYPE value)
        {
            // Get the hash of the key
            unsigned int hash = hashFunction(key);

            // Check if the key already exists, overwrite the value if it does and return
            HashTableNode<KEY_TYPE, VALUE_TYPE>* current = table[hash];
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    current->value = value;
                    return;
                }
                current = current->next;
            }

            // The key does not exist, so a new node must be created
            HashTableNode<KEY_TYPE, VALUE_TYPE>* newNode = new HashTableNode<KEY_TYPE, VALUE_TYPE>;
            newNode->key = key;
            newNode->value = value;
            newNode->next = nullptr;

            // Insert the new node into the hash table
            if (table[hash] == nullptr) table[hash] = newNode;
            else
            {
                current = table[hash];
                while (current->next != nullptr) current = current->next;
                current->next = newNode;
            }

            // Increment the number of elements in the table
            numberOfElements++;
        }

        // Removes a key/value pair from the table if it exists, returns false if it does not exist
        bool remove(KEY_TYPE key)
        {
            // Get the hash of the key
            unsigned int hash = hashFunction(key);

            // Search for the key
            HashTableNode<KEY_TYPE, VALUE_TYPE>* current = table[hash];
            HashTableNode<KEY_TYPE, VALUE_TYPE>* previous = nullptr;
            while (current != nullptr)
            {
                // Check if we have found the key
                if (current->key == key)
                {
                    // The key exists, so remove its node
                    if (previous == nullptr) table[hash] = current->next;
                    else previous->next = current->next;
                    delete current;
                    numberOfElements--;
                    return true;
                }
                previous = current;
                current = current->next;
            }

            // The key does not exist
            return false;
        }

        // Returns a pointer to the value associated with the key, or null if the key does not exist
        VALUE_TYPE* get(KEY_TYPE key)
        {
            // Get the hash of the key
            unsigned int hash = hashFunction(key);

            // Search for the key
            HashTableNode<KEY_TYPE, VALUE_TYPE>* current = table[hash];
            while (current != nullptr)
            {
                // Check if we have found the key, return a pointer to the value if we have
                if (current->key == key) return &current->value;

                // Move to the next node if we have not found the key
                current = current->next;
            }

            // The key does not exist
            return nullptr;
        }

        // Returns true if the key exists in the table, false if it does not
        bool contains(KEY_TYPE key)
        {
            // Get the hash of the key
            unsigned int hash = hashFunction(key);

            // Search for the key
            HashTableNode<KEY_TYPE, VALUE_TYPE>* current = table[hash];
            while (current != nullptr)
            {
                // Check if we have found the key, return true if we have
                if (current->key == key) return true;

                // Move to the next node if we have not found the key
                current = current->next;
            }

            // The key does not exist
            return false;
        }

        // Clears all elements from the table, freeing the associated memory. Does not delete the table itself.
        void clear()
        {
            for (size_t i = 0; i < tableSize; i++)
            {
                HashTableNode<KEY_TYPE, VALUE_TYPE>* current = table[i];
                while (current != nullptr)
                {
                    HashTableNode<KEY_TYPE, VALUE_TYPE>* next = current->next;
                    delete current;
                    current = next;
                }
            }
            numberOfElements = 0;
        }

        // Returns the number of elements in the table.
        size_t size()
        {
            return numberOfElements;
        }

        // Returns true if the table is empty, false if it is not
        bool empty()
        {
            return numberOfElements == 0;
        }

        // Prints the contents of the table to the console
        void print()
        {
            for (size_t i = 0; i < tableSize; i++)
            {
                HashTableNode<KEY_TYPE, VALUE_TYPE>* current = table[i];
                while (current != nullptr)
                {
                    std::cout << current->key << ": " << current->value << std::endl;
                    current = current->next;
                }
            }
        }
    
    private:
        // The hash table array
        HashTableNode<KEY_TYPE, VALUE_TYPE>** table;

        unsigned int (*hashFunction)(KEY_TYPE key);

        // The hash function that will be used if one is not provided to
        // the constructor.
        // See: https://en.wikipedia.org/wiki/Jenkins_hash_function
        unsigned int jenkinsHashFunction(KEY_TYPE key)
        {
            std::string hashString(key);
            unsigned int hash = 0;
            for (unsigned int i = 0; hashString[i] != '\0'; i++)
            {
                hash += hashString[i];
                hash += hash << 10;
                hash ^= hash >> 6;
            }
            hash += hash << 3;
            hash ^= hash >> 11;
            hash += hash << 15;
            return hash % tableArrayCapacity;
        }

        // The null pointer
        int (*null)(KEY_TYPE) = nullptr;

        // The size of the table array
        size_t tableArrayCapacity;

        // The number of elements in the table
        size_t numberOfElements;
};

#endif