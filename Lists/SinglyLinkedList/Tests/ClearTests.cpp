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
 * @file ClearTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

TEST_CASE("Clears the list", "[SinglyLinkedList][clear()]")
{
    SinglyLinkedList<int> testList;
    testList.insertAtIndex(0, 10);
    testList.insertAtIndex(1, 20);
    testList.insertAtIndex(2, 30);

    SECTION("Clears a non-empty list")
    {
        testList.clear();

        REQUIRE(testList.getLength() == 0);
        REQUIRE_THROWS(testList.getElementAtIndex(0));
    }

    SECTION("Clears an empty list")
    {
        SinglyLinkedList<float> emptyList;
        emptyList.clear();

        REQUIRE(emptyList.getLength() == 0);
        REQUIRE_THROWS(emptyList.getElementAtIndex(0));
    }
}