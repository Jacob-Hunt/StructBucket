/**
 * MIT License
 * 
 * Copyright (c) 2023 Jacob Hunt
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file SinglyLinkedList.hpp
 * @brief Implementation of a singly linked list data structure
 * @author Jacob Hunt
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <cstddef>

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

    private:
        SinglyLinkedListNode<TYPE>* head = NULL;
        int length = 0;
};

#endif