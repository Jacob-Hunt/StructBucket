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
 * @file Tests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../SinglyLinkedList.hpp"

TEST_CASE( "Returns the correct length for an empty list", "[SinglyLinkedList][getLength()]" ) {
    SinglyLinkedList<char> testList;
    REQUIRE( testList.getLength() == 0 );
}

TEST_CASE( "Returns the correct length a list with multiple elements", "[SinglyLinkedList][getLength()]" ) {
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(0, 'b');
    REQUIRE( testList.getLength() == 2 );
}

TEST_CASE( "Returns the correct length after elements have been removed", "[SinglyLinkedList][getLength()]" ) {
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(0, 'b');
    testList.deleteFromIndex(1);
    REQUIRE( testList.getLength() == 1 );
}