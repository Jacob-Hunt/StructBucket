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
    TYPE* element;
    SinglyLinkedListNode* next;
};

template<typename TYPE>
class SinglyLinkedList
{
    public:
        // Returns the number of elements in the linked list.
        // Algorithmic runtime: O(1)
        int getLength() const;

        // Returns the element at the specified index or throws an exception
        // if the index is out of range.
        // Algorithmic runtime: O(N)
        TYPE getElementAtIndex(int index) const;

        // Searches the list for the first element that is strictly equal to
        // the "element" argument. Returns the index of the element, or
        // returns -1 if the list does not contain the specified element.
        // Algorithmic runtime: O(N)
        int getFirstIndexOf(TYPE element) const;

        // Inserts an element at the specified index, or throws an exception
        // if the index is out of range.
        // Algorithmic runtime: O(N)
        void insertAtIndex(TYPE element, int index);

        // Deletes an element from the specified index, or throws an exception
        // if the index is out of range.
        // Algorithmic runtime: O(N)
        void deleteFromIndex(int index);

    private:
        SinglyLinkedListNode<TYPE>* head = NULL;
        int length = 0;
};

#endif