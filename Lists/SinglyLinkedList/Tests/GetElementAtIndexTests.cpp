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
 * @file GetElementAtIndexTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../SinglyLinkedList.hpp"

TEST_CASE("Throws an exception when trying to retrieve from an empty list", "[SinglyLinkedList][getElementAtIndex()]")
{
    SinglyLinkedList<char> testList;
    REQUIRE_THROWS( testList.getElementAtIndex(0) );
}

TEST_CASE("Retrieves correct elements", "[SinglyLinkedList][getElementAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(1, 'b');
    testList.insertAtIndex(2, 'c');

    SECTION("Retrieves correct element from head of list")
    {
        REQUIRE(testList.getElementAtIndex(0) == 'a');
    }

    SECTION("Retrieves correct element from tail of list")
    {
        REQUIRE(testList.getElementAtIndex(2) == 'c');
    }

    SECTION("Retrieves correct element from middle of list")
    {
        REQUIRE(testList.getElementAtIndex(1) == 'b');
    }

    SECTION("Does not modify size of list")
    {
        int size = testList.getLength();
        testList.getElementAtIndex(1);
        REQUIRE(testList.getLength() == size);
    }

    SECTION("Throws an exception when trying to retrieve from a negative index")
    {
        REQUIRE_THROWS(testList.getElementAtIndex(-1));
    }

    SECTION("Throws an exception when trying to retrieve from an out-of-bounds index")
    {
        REQUIRE_THROWS(testList.getElementAtIndex(4));
    }
}