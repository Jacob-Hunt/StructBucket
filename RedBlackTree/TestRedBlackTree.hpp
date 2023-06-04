/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file TestableRedBlackTree.hpp
 * @brief Extension of the RedBlackTree data structure with support for testing the tree's internal structure.
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include <stack>
#include "../RedBlackTree.hpp"

template<typename KEY_TYPE, typename VALUE_TYPE>
class TestRedBlackTree : RedBlackTree
{
    public:
        // Red Black Tree property: root node must be black
        bool isRootNodeBlack()
        {
            return !root.isRed;
        }

        // Red Black Tree property: a red node cannot have another red node as a
        // child.
        bool noRedNodesWithRedChildren()
        {
            // Stack of nodes to check
            stack<RedBlackTreeNode<typename KEY_TYPE, typename VALUE_TYPE>*> nodeStack;

            // Node currently being checked
            RedBlackTreeNode<typename KEY_TYPE, typename VALUE_TYPE>* currentNode;

            // Start with the root node
            nodeStack.push(root);

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
            // TODO
        }

        // Binary Search Tree property: all left children have keys that are
        // less than the parent's key and all right children have keys that are
        // greater than the parent's key.
        bool isTreeSorted()
        {
            // TODO
        }
    
    private:
        bool hasRedChild(RedBlackTreeNode<typename KEY_TYPE, typename VALUE_TYPE>* node)
        {
            return (
                (node->leftChild && node->leftChild->isRed) ||
                (node->rightChild && node->rightChild->isRed)
            );
        }
}

