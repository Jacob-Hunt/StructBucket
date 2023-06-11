/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file SinglyLinkedList.hpp
 * @brief Implementation of a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <cstddef>
#include <stdexcept>

template<typename TYPE>
struct SinglyLinkedListNode
{
    TYPE element;
    SinglyLinkedListNode* next;
};

template<typename TYPE>
class SinglyLinkedList
{
    public:
        // Destructor method; deallocates all memory for the linked list.
        // Algorithmic runtime: O(N)
        ~SinglyLinkedList()
        {
            clear();
        }

        // Returns the number of elements in the linked list.
        // Algorithmic runtime: O(1)
        int getLength() const
        {
            return length;
        }

        // Returns the element at the specified index or throws an exception
        // if the index is out of range.
        // Algorithmic runtime: O(N)
        TYPE getElementAtIndex(int index) const
        {
            // Validate argument
            if (index < 0 || index >= length)
            {
                throw std::out_of_range("Invalid index (out of range)");
            }

            // Traverse list up to specified index
            SinglyLinkedListNode<TYPE>* currentNode = head;
            for (int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            // Return the element from the node at the specified index
            return currentNode->element;
        }

        // Searches the list for the first element that is strictly equal to
        // the "element" argument using a linear search algorithm. Returns
        // the index of the element, or returns -1 if the list does not
        // contain the specified element.
        // Algorithmic runtime: O(N)
        int getFirstIndexOf(TYPE element) const
        {
            // Instantiate traversal variables
            SinglyLinkedListNode<TYPE>* currentNode = head;
            int index = 0;

            // While we haven't reached the end of the list...
            while (currentNode != NULL)
            {
                // If we found it...
                if (currentNode->element == element)
                {
                    // ...return it
                    return index;
                }

                // Otherwise, keep on moving through the list
                currentNode = currentNode->next;
                index++;
            }

            // Return -1 if the element was not found
            return -1;
        }

        // Inserts an element at the specified index, or throws an exception
        // if the index is out of range.
        // Algorithmic runtime: O(N)
        void insertAtIndex(int index, TYPE element)
        {
            // Validate arguments
            if (index < 0 || index > length)
            {
                throw std::out_of_range("Invalid index (out of range)");
            }

            // Create node to insert into the list
            SinglyLinkedListNode<TYPE>* newNode = new SinglyLinkedListNode<TYPE>
            {
                element,
                NULL
            };

            // Handle case where node is inserted at the head of the list
            if (index == 0)
            {
                newNode->next = head;
                head = newNode;
                length++;
                return;
            }

            // Traverse list up to the insertion location
            SinglyLinkedListNode<TYPE>* currentNode = head;
            for (int i = 0; i < index - 1; i++) currentNode = currentNode->next;

            // Insert new node by adjusting pointers 
            newNode->next = currentNode->next;
            currentNode->next = newNode;

            // Increase length counter
            length++;
        }

        // Assigns the provided element to the existing node at the specified
        // index.
        // Algorithmic runtime: O(N) 
        void updateAtIndex(int index, TYPE element)
        {
            // Validate arguments
            if (index < 0 || index >= length)
            {
                throw std::out_of_range("Invalid index (out of range)");
            }

            // Traverse the list up to the specified index
            SinglyLinkedListNode<TYPE>* currentNode = head;
            for (int i = 0; i < index; i++) currentNode = currentNode->next;

            // Update the element in the node at the specified index
            currentNode->element = element;
        }

        // Deletes an element from the specified index, or throws an exception
        // if the index is out of range.
        // Algorithmic runtime: O(N)
        void deleteFromIndex(int index)
        {
            // Validate arguments
            if (index < 0 || index >= length)
            {
                throw std::out_of_range("Invalid index (out of range)");
            }

            // Allocate variable for the node that will be deleted
            SinglyLinkedListNode<TYPE>* nodeToDelete;

            // Handle case where head of list is deleted
            if (index == 0)
            {
                nodeToDelete = head;
                head = head->next;
                length--;
                return;
            }

            // Traverse to index of node to be deleted
            SinglyLinkedListNode<TYPE>* currentNode = head;
            for (int i = 0; i < index - 1; i++) currentNode = currentNode->next;

            // Rearrange pointers
            nodeToDelete = currentNode->next;
            currentNode->next = nodeToDelete->next;

            // Perform housekeeping
            delete nodeToDelete;
            length--;
        }

        // Removes all elements from the list, deallocating the associated
        // memory and setting the head of the list to NULL.
        // Algorithmic runtime: O(N)
        void clear()
        {
            SinglyLinkedListNode<TYPE>* currentNode = head;

            // Traverse the list until we reach the end, deleting all nodes
            // along the way.
            while (currentNode != NULL)
            {
                SinglyLinkedListNode<TYPE>* next = currentNode->next;
                delete currentNode;
                currentNode = next;
            }

            // Housekeeping
            head = NULL;
            length = 0;
        }

    private:
        SinglyLinkedListNode<TYPE>* head = NULL;
        int length = 0;
};

#endif