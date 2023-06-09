/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file RedBlackTree.hpp
 * @brief Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <cstddef>

template<typename KEY_TYPE, typename VALUE_TYPE>
struct RedBlackTreeNode
{
    KEY_TYPE key;
    VALUE_TYPE value;
    bool isRed;
    RedBlackTreeNode* parent;
    RedBlackTreeNode* leftChild;
    RedBlackTreeNode* rightChild;
};

template<typename KEY_TYPE, typename VALUE_TYPE>
class RedBlackTree
{
    public:
        // Destructor method; deallocates all memory for the tree.
        // Algorithmic runtime: O(N)
        ~RedBlackTree()
        {
            clear();
        }

        // Returns the number of nodes in the tree.
        // Algorithmic runtime: O(1)
        int size() const
        {
            return this->numberOfNodes;
        }

        // Retrieves a pointer to a value from the tree dictionary with the
        // provided key
        // Algorithmic runtime: O(log N)
        VALUE_TYPE* get(KEY_TYPE key)
        {
            // TODO
            return NULL;
        }

        // Inserts a key/value pair into the tree. Throws an exception if the
        // tree already contains an element with the same key.
        // Algorithmic runtime: O(log N)
        void insert(KEY_TYPE key, VALUE_TYPE value)
        {
            // Throw exception if there is a duplicate key
            if (this->get(key) != NULL) throw std::runtime_error(
                "The dictionary already contains an element with the provided key"
            );

            // Create a new node to insert into the tree
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* newNode = new RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>
            {
                .key = key,
                .value = value,
                .isRed = true,
                .parent = NULL,
                .leftChild = NULL,
                .rightChild = NULL
            };

            // Case where tree is empty
            if (!this->root)
            {
                this->root = newNode;
                this->root->isRed = false;
                return;
            }

            // Insert node as a leaf in the tree
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* currentNode = this->root;
            while (!newNode->parent)
            {
                if (newNode->key < currentNode->key && currentNode->leftChild)
                {
                    currentNode = currentNode->leftChild;
                }
                else if (newNode->key > currentNode->key && currentNode->rightChild)
                {
                    currentNode = currentNode->rightChild;
                }
                else if (newNode->key < currentNode->key)
                {
                    newNode->parent = currentNode;
                    currentNode->leftChild = newNode;
                }
                else
                {
                    newNode->parent = currentNode;
                    currentNode->rightChild = newNode;
                }
            }

            // Restore Red Black Tree properties
            // TODO
        }

        // Updates the value of the node with the specified key. Throws an
        // exception if the tree does not contain a node with the provided
        // key.
        // Algorithmic runtime: O(log N)
        void update(KEY_TYPE key, VALUE_TYPE newValue)
        {
            // TODO
        }

        // Updates the value of the node with the specified key, or inserts the
        // provided key/value pair if the tree does not already contain the key.
        // Algorithmic runtime: O(log N)
        bool upsert(KEY_TYPE key, VALUE_TYPE newValue)
        {
            // TODO
            return false;
        }

        // Removes the node of the tree with the specified key. Returns false
        // if the tree didn't contain a node with the provided key, returns true
        // otherwise.
        // Algorithmic runtime: O(log N)
        bool remove(KEY_TYPE key)
        {
            // TODO
            return false;
        }

        // Removes all elements in the tree, deallocating associated memory.
        // Algorithmic runtime: O(N)
        void clear()
        {
            // TODO
        }

    protected:
        RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* root = NULL;
        int numberOfNodes = 0;
};

#endif