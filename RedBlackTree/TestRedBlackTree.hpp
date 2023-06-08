/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file TestableRedBlackTree.hpp
 * @brief Extension of the RedBlackTree data structure with support for testing the tree's internal structure.
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#ifndef TESTREDBLACKTREE_H
#define TESTREDBLACKTREE_H

#include <stack>
#include "./RedBlackTree.hpp"

template<typename KEY_TYPE, typename VALUE_TYPE>
class TestRedBlackTree : RedBlackTree<KEY_TYPE, VALUE_TYPE>
{
    public:
        // Red Black Tree property: root node must be black
        bool isRootNodeBlack()
        {
            return !this->root.isRed;
        }

        // Red Black Tree property: a red node cannot have another red node as a
        // child.
        bool noRedNodesWithRedChildren()
        {
            // Stack of nodes to check
            std::stack<RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>*> nodeStack;

            // Node currently being checked
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* currentNode;

            // Start with the root node
            nodeStack.push(this->root);

            // While we still have nodes to check...
            while (!nodeStack.empty())
            {
                // Check if current node is red and has red children, returning
                // false if so.
                currentNode = nodeStack.top();
                nodeStack.pop();
                if (currentNode->isRed && hasRedChild(currentNode)) return false;

                // Add child nodes to the stack (if they exist)
                if (currentNode->leftChild) nodeStack.push(currentNode->leftChild);
                if (currentNode->rightChild) nodeStack.push(currentNode->rightChild);
            }

            // No red nodes with red children were found; this Red Black Tree
            // property holds.
            return true;
        }

        // Red Black Tree property: all paths to leaf nodes must contain the
        // same number of black nodes.
        bool blackNodePathEqualityHolds()
        {
            // Stack of nodes to check
            std::stack<RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>*> nodeStack;

            // Node currently being checked
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* currentNode;

            // Stack of black node path counts to be checked (if Red Black Tree
            // property holds, all numbers in this stack should be identical).
            std::stack<int> blackNodePathCounts;

            // Start with the root node
            nodeStack.push(this->root);

            // While we still have nodes to check...
            while (!nodeStack.empty())
            {
                // Check if the current node is a leaf node and, if so, count
                // the number of black nodes between the current node and the
                // root. Otherwise, keep traversing the tree.
                currentNode = nodeStack.top();
                nodeStack.pop();
                if (isLeafNode(currentNode))
                {
                    blackNodePathCounts.push(getBlackNodeCountToRoot(currentNode));
                }
                else
                {
                    if (currentNode->leftChild) nodeStack.push(currentNode->leftChild);
                    if (currentNode->rightChild) nodeStack.push(currentNode->rightChild);
                }
            }

            // Go through the stack of black node counts and make sure that all
            // counts are identical.
            if (blackNodePathCounts.size() < 2) return true;
            else
            {
                int lastCount = blackNodePathCounts.top();
                while (!blackNodePathCounts.empty())
                {
                    if (lastCount != blackNodePathCounts.top()) return false;
                    blackNodePathCounts.pop();
                }
            }

            return true;
        }

        // Binary Search Tree property: all left children have keys that are
        // less than the parent's key and all right children have keys that are
        // greater than the parent's key.
        bool isTreeSorted()
        {
            // Stack of nodes to check
            std::stack<RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>*> nodeStack;

            // Node currently being checked
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* currentNode;

            // Start with the root node
            nodeStack.push(this->root);

            // While we still have nodes to check...
            while (!nodeStack.empty())
            {
                // Check if current node is balanced, returning false if not
                currentNode = nodeStack.top();
                nodeStack.pop();
                if (!isBalancedNode(currentNode)) return false;

                // Add child nodes to the stack (if they exist)
                if (currentNode->leftChild) nodeStack.push(currentNode->leftChild);
                if (currentNode->rightChild) nodeStack.push(currentNode->rightChild);
            }

            // All nodes are balanced, therefore tree is balanced
            return true;
        }

        // Returns true if a node exists in the tree with the provided key,
        // regardless of other tree properties (such as sorting and balance)
        bool contains(KEY_TYPE key)
        {
            // Stack of nodes to check
            std::stack<RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>*> nodeStack;

            // Node currently being checked
            RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* currentNode;

            // Start with the root node
            nodeStack.push(this->root);

            // While we still have nodes to check...
            while (!nodeStack.empty())
            {
                // Check if current node is balanced, returning false if not
                currentNode = nodeStack.top();
                nodeStack.pop();
                if (currentNode->key == key) return true;

                // Add child nodes to the stack (if they exist)
                if (currentNode->leftChild) nodeStack.push(currentNode->leftChild);
                if (currentNode->rightChild) nodeStack.push(currentNode->rightChild);
            }

            // Could not find node with the provided key
            return false;
        }
    
    private:
        bool hasRedChild(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            return (
                (node->leftChild && node->leftChild->isRed) ||
                (node->rightChild && node->rightChild->isRed)
            );
        }

        int getBlackNodeCountToRoot(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            int count = 0;
            while (node->parent)
            {
                if (!node->isRed)
                {
                    count++;
                }
                node = node->parent;
            }
            return count;
        }

        bool isLeafNode(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            return !node->leftChild && !node->rightChild;
        }

        bool isBalancedNode(RedBlackTreeNode<KEY_TYPE, VALUE_TYPE>* node)
        {
            return (
                !(node->leftChild && node->leftChild->key >= node->key) &&
                !(node->rightChild && node->rightChild->key <= node->key)
            );
        }
};

#endif