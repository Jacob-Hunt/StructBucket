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

        // Returns the number of elements in the tree.
        // Algorithmic runtime: O(1)
        int getSize() const
        {
            return size;
        }

        // Returns true if the tree contains a node referenced by the key.
        // Algorithmic runtime: O(log N)
        bool contains(KEY_TYPE key)
        {
            // TODO
            return false;
        }

        // Inserts a key/value pair into the tree. Throws an exception if the
        // tree already contains an element with the same key.
        // Algorithmic runtime: O(log N)
        void insert(KEY_TYPE key, VALUE_TYPE value)
        {
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
        }

        // Removes the node of the tree with the specified key. Returns false
        // if the tree didn't contain a node with the provided key, returns true
        // otherwise.
        // Algorithmic runtime: O(log N)
        bool remove(KEY_TYPE key)
        {
            // TODO
        }

        // Removes all elements in the tree, deallocating associated memory.
        // Algorithmic runtime: O(N)
        void clear()
        {
            // TODO
        }

    protected:
        RedBlackTreeNode<typename KEY_TYPE, typename VALUE_TYPE>* root = NULL;
        int size = 0;
};

#endif