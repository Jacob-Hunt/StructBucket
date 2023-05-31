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
 * @file GetFirstIndexOfTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

TEST_CASE("Throws an exception when trying to retrieve an element of the wrong type", "[SinglyLinkedList][getElementAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    REQUIRE_THROWS(testList.getFirstIndexOf(0));
}

TEST_CASE("Retrieves correct indices", "[SinglyLinkedList][getElementAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(1, 'b');
    testList.insertAtIndex(2, 'c');
    testList.insertAtIndex(3, 'c');
    testList.insertAtIndex(4, 'd');

    SECTION("Retrieves correct index of element at head of list")
    {
        REQUIRE(testList.getFirstIndexOf('a') == 0);
    }

    SECTION("Retrieves correct index of element at tail of list")
    {
        REQUIRE(testList.getFirstIndexOf('d') == 4);
    }

    SECTION("Retrieves correct index of element in middle of list")
    {
        REQUIRE(testList.getFirstIndexOf('b') == 1);
    }

    SECTION("Retrieves first index of element that appears multiple times in list")
    {
        REQUIRE(testList.getFirstIndexOf('c') == 2);
    }

    SECTION("Returns -1 when list doesn't contain element")
    {
        REQUIRE(testList.getFirstIndexOf('z') == -1);
    }
}