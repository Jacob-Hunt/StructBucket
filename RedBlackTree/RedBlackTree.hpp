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
#include <stdexcept>

template<typename KEY_TYPE, typename VALUE_TYPE>
struct RedBlackTreeNode
{
    KEY_TYPE key;
    VALUE_TYPE value;
    bool isRed;
    RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* parent;
    RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* leftChild;
    RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* rightChild;
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
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node = getNode(key);
            if (node != NULL) return &(node->value);
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
            restoreAfterInsert(newNode);

            // Increment the counter
            this->numberOfNodes++;
        }

        // Updates the value of the node with the specified key. Throws an
        // exception if the tree does not contain a node with the provided
        // key.
        // Algorithmic runtime: O(log N)
        void update(KEY_TYPE key, VALUE_TYPE newValue)
        {
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node = getNode(key);
            if (node == NULL) throw std::runtime_error(
                "Could not find Red Black Tree entry with the provided key"
            );
            node->value = newValue;
        }

        // Updates the value of the node with the specified key, or inserts the
        // provided key/value pair if the tree does not already contain the key.
        // Returns true of if tree already contained a node with the provided
        // key, returns false otherwise.
        // Algorithmic runtime: O(log N)
        bool upsert(KEY_TYPE key, VALUE_TYPE newValue)
        {
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node = getNode(key);

            // Node already exists, so update
            if (node != NULL)
            {
                node->value = newValue;
                return true;
            }

            // Node doesn't already exist, so insert
            insert(key, newValue);
            return false;
        }

        // Removes the node of the tree with the specified key. Returns false
        // if the tree didn't contain a node with the provided key, returns true
        // otherwise.
        // Algorithmic runtime: O(log N)
        bool remove(KEY_TYPE key)
        {
            // Get the node that we want to remove from the tree
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* nodeToDelete = this->getNode(key);

            // Edge case where the tree doesn't contain the node
            if (nodeToDelete == NULL) return false;

            // Pointer to the node that we will pass to the post-delete cleanup
            // method (varies depending on the properties of the node to be
            // deleted)
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* nodeForRestoreAfterDelete;

            // Case were the left child is NULL
            if (nodeToDelete->leftChild == NULL)
            {
                transplantNodes(nodeToDelete, nodeToDelete->rightChild);
                nodeForRestoreAfterDelete = nodeToDelete->rightChild;
            }

            // Case where the right child is NULL
            else if (nodeToDelete->rightChild == NULL)
            {
                transplantNodes(nodeToDelete, nodeToDelete->leftChild);
                nodeForRestoreAfterDelete = nodeToDelete->leftChild;
            }

            // Case where neither child is NULL
            else
            {
                // Get the leftmost node of the right subtree of the node to be
                // deleted
                RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* rightSubtreeMin = nodeToDelete->rightChild;
                while (rightSubtreeMin->leftChild != NULL) rightSubtreeMin = rightSubtreeMin->leftChild;

                // Save the node for the cleanup method
                nodeForRestoreAfterDelete = rightSubtreeMin->rightChild;

                // Adjust pointers
                transplantNodes(rightSubtreeMin, rightSubtreeMin->rightChild);
                rightSubtreeMin->rightChild = nodeToDelete->rightChild;
                rightSubtreeMin->rightChild->parent = rightSubtreeMin;
                transplantNodes(nodeToDelete, rightSubtreeMin);
                rightSubtreeMin->leftChild = nodeToDelete->leftChild;
                rightSubtreeMin->leftChild->parent = rightSubtreeMin;
            }

            // If the node we're deleting is black, we need to call the cleanup
            // method
            if (!nodeToDelete->isRed) restoreAfterDelete(nodeForRestoreAfterDelete);

            // Deallocate the memory and decrement the counter
            delete nodeToDelete;
            this->numberOfNodes--;
            return true;
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
    
    private:
        RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* getNode(KEY_TYPE key)
        {
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* currentNode = this->root;
            while (currentNode != NULL)
            {
                if (key < currentNode->key) currentNode = currentNode->leftChild;
                else if (key > currentNode->key) currentNode = currentNode->rightChild;
                else if (key == currentNode->key) return currentNode; 
            }
            return NULL;
        }

        void restoreAfterInsert(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* parent;
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* grandparent;
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* uncle;

            while (node->parent && node->parent->isRed)
            {
                parent = node->parent;
                grandparent = getGrandparent(node);
                uncle = getUncle(node);

                if (uncle && uncle->isRed)
                {
                    parent->isRed = false;
                    uncle->isRed = false;
                    grandparent->isRed = true;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->rightChild && parent == grandparent->leftChild)
                    {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    else if (node == parent->leftChild && parent == grandparent->rightChild)
                    {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    parent->isRed = false;
                    grandparent->isRed = true;

                    if (node == parent->leftChild)
                    {
                        rotateRight(grandparent);
                    }
                    else
                    {
                        rotateLeft(grandparent);
                    }
                }
            }

            this->root->isRed = false;
        }

        RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* getGrandparent(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            if (node == NULL || node->parent == NULL) return NULL;
            else return node->parent->parent;
        }

        RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* getUncle(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* grandparent = getGrandparent(node);
            if (grandparent == NULL) return NULL;
            if (grandparent->leftChild == node->parent) return grandparent->rightChild;
            return grandparent->leftChild;
        }

        void rotateLeft(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            // Validate argument
            if (node->rightChild == NULL)
            {
                throw std::runtime_error("Cannot left-rotate a Red Black Tree node with no right child.");
            }

            // Save pointer to original right child
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* oldRightChild = node->rightChild;

            // Reassign parent/child pointers so that the initial right-left
            // child is now the node's right child
            node->rightChild = oldRightChild->leftChild;
            if (oldRightChild->leftChild != NULL) oldRightChild->leftChild->parent = node;

            // Reassign parent pointer of original right child to be a pointer
            // to the orignal node's parent
            oldRightChild->parent = node->parent;

            // If the original node was the root node of the tree, the original
            // right child is now the root node
            if (node->parent == NULL) this->root = oldRightChild;

            // If the original node was the left child of its parent, the
            // original right child is now its left child
            else if (node == node->parent->leftChild) node->parent->leftChild = oldRightChild;

            // If the original node was the right child of its parent, the
            // original right child is now the original node's parent's right
            // child
            else node->parent->rightChild = oldRightChild;

            // Reassign pointer relationship between the initial right child and
            // the rotated node
            oldRightChild->leftChild = node;
            node->parent = oldRightChild;
        }

        void rotateRight(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            // Validate argument
            if (node->leftChild == NULL)
            {
                throw std::runtime_error("Cannot right-rotate a Red Black Tree node with no left child.");
            }

            // Save pointer to original left child
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* oldLeftChild = node->leftChild;

            // Reassign parent/child pointers so that the initial left-right
            // child is now the node's left child
            node->leftChild = oldLeftChild->rightChild;
            if (oldLeftChild->rightChild != NULL) oldLeftChild->rightChild->parent = node;

            // Reassign parent pointer of original left child to be a pointer
            // to the original node's parent
            oldLeftChild->parent = node->parent;

            // If the original node was the root node of the tree, the original
            // left child is now the root node
            if (node->parent == NULL) this->root = oldLeftChild;

            // If the original node was the right child of its parent, the
            // original left child is now its right child
            else if (node == node->parent->rightChild) node->parent->rightChild = oldLeftChild;

            // If the original node was the left child of its parent, the
            // original left child is now the original node's parent's left
            // child
            else node->parent->leftChild = oldLeftChild;

            // Reassign pointer relationship between the initial left child and
            // the rotated node
            oldLeftChild->rightChild = node;
            node->parent = oldLeftChild;
        }

        void transplantNodes(
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* original,
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* replacement
        ) {
            if (original->parent == NULL)
            {
                this->root = replacement;
            }
            else if (original == original->parent->leftChild)
            {
                original->parent->leftChild = replacement;
            }
            else
            {
                original->parent->rightChild = replacement;
            }
            if (replacement != NULL)
            {
                replacement->parent = original->parent;
            }
        }

        void restoreAfterDelete(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            // Edge case where node is NULL
            if (node == NULL) return;

            // Pointer to the current node's sibling
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* sibling;

            // While the node isn't the root and has not been colored red
            while (node->parent != NULL && !node->isRed)
            {
                // Case where the node is the left child of its parent
                if (node == node->parent->leftChild)
                {
                    // Fix iteration when sibling node is red
                    if (sibling != NULL and sibling->isRed)
                    {
                        sibling->isRed = false;
                        node->parent->isRed = true;
                        rotateLeft(node->parent);
                        sibling = node->parent->rightChild;
                    }

                    // Fix iteration when sibling node is black with black child
                    // nodes
                    else if ((sibling->leftChild == NULL || !sibling->leftChild->isRed) &&
                        (sibling->rightChild == NULL || !sibling->rightChild->isRed)
                    ) {
                        sibling->isRed = true;
                        node = node->parent;
                    }
                    else
                    {
                        // Fix iteration when sibling node is black with black
                        // right child and red left child
                        if (sibling->rightChild == NULL || !sibling->rightChild->isRed)
                        {
                            sibling->leftChild->isRed = false;
                            sibling->isRed = true;
                            rotateRight(sibling);
                            sibling = node->parent->rightChild;
                        }

                        // Fix iteration when sibling node is black with black
                        // left child and red right child
                        sibling->isRed = node->parent->isRed;
                        node->parent->isRed = false;
                        sibling->rightChild->isRed = false;
                        rotateLeft(node->parent);
                        node = this->root;
                    }
                }

                // Case where the node is the right child of its parent
                else
                {
                    sibling = node->parent->leftChild;

                    // Fix iteration when sibling node is red
                    if (sibling != NULL and sibling->isRed)
                    {
                        sibling->isRed = false;
                        node->parent->isRed = true;
                        rotateRight(node->parent);
                        sibling = node->parent->leftChild;
                    }

                    // Fix iteration when sibling node is black with black child
                    // nodes
                    else if ((sibling->leftChild == NULL || !sibling->leftChild->isRed) &&
                        (sibling->rightChild == NULL || !sibling->rightChild->isRed)
                    ) {
                        sibling->isRed = true;
                        node = node->parent;
                    }
                    else
                    {
                        // Fix iteration when sibling node is black with black
                        // left child and red right child
                        if (sibling->leftChild == NULL || !sibling->leftChild->isRed)
                        {
                            sibling->rightChild->isRed = false;
                            sibling->isRed = true;
                            rotateLeft(sibling);
                            sibling = node->parent->leftChild;
                        }

                        // Fix iteration when sibling node is black with black
                        // right child and red right left
                        sibling->isRed = node->parent->isRed;
                        node->parent->isRed = false;
                        sibling->leftChild->isRed = false;
                        rotateRight(node->parent);
                        node = this->root;
                    }
                }
            }

            // Color node black
            node->isRed = false;
        }
};

#endif