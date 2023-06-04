/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file GetFirstIndexOfTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../SinglyLinkedList.hpp"

TEST_CASE("Retrieves correct indices", "[SinglyLinkedList][getFirstIndexOf()]")
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