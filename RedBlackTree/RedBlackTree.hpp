/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file RedBlackTree.hpp
 * @brief Implementation of a Red Black Tree data structure that can contain duplicate elements
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <cstddef>

template<typename TYPE>
struct RedBlackTreeNode
{
    TYPE element;
    int count;
    bool isRed;
    RedBlackTreeNode* parent;
    RedBlackTreeNode* leftChild;
    RedBlackTreeNode* rightChild;
};

template<typename TYPE>
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

        // Returns the number of elements strictly equal to the provided
        // argument that are contained in the tree.
        // Algorithmic runtime: O(log N)
        int contains(TYPE element)
        {
            // TODO
            return 0;
        }

        // Inserts one or more elements into the tree. The number of copies of
        // "element" parameter to be inserted is specified by the "number"
        // parameter (with a single element being insterted if "number" is not
        // specified).
        // Algorithmic runtime: O(log N)
        void insert(TYPE element, int number = 1)
        {
            // TODO
        }

        // Removes one or more elements from the tree. The number of copies of
        // "element" parameter to be deleted is specified by the "number"
        // parameter (with a single element being insterted if "number" is not
        // specified). Returns false if attempting to remove more matching 
        // elements than already exist in the tree, while still deleting the
        // matching elements that do exist.
        // Algorithmic runtime: O(log N)
        void remove(TYPE element, int number = 1)
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
        RedBlackTreeNode<TYPE>* head = NULL;
        int size = 0;
};

#endif