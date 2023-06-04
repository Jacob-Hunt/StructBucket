/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file InsertAtIndexTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../SinglyLinkedList.hpp"

TEST_CASE("Inserts element at the beginning of the list", "[SinglyLinkedList][insertAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    REQUIRE(testList.getElementAtIndex(0) == 'a');
    REQUIRE(testList.getLength() == 1);
}

TEST_CASE("Inserts element in the middle of the list", "[SinglyLinkedList][insertAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(1, 'b');
    testList.insertAtIndex(1, 'c');
    REQUIRE(testList.getElementAtIndex(0) == 'a');
    REQUIRE(testList.getElementAtIndex(1) == 'c');
    REQUIRE(testList.getElementAtIndex(2) == 'b');
    REQUIRE(testList.getLength() == 3);
}

TEST_CASE("Inserts element at the end of the list", "[SinglyLinkedList][insertAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(1, 'b');
    testList.insertAtIndex(2, 'c');
    testList.insertAtIndex(testList.getLength(), 'd');
    REQUIRE(testList.getElementAtIndex(0) == 'a');
    REQUIRE(testList.getElementAtIndex(1) == 'b');
    REQUIRE(testList.getElementAtIndex(2) == 'c');
    REQUIRE(testList.getElementAtIndex(3) == 'd');
    REQUIRE(testList.getLength() == 4);
}

TEST_CASE("Inserts element at the specified index", "[SinglyLinkedList][insertAtIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    REQUIRE_THROWS(testList.insertAtIndex(2, 'b'));
    REQUIRE(testList.getLength() == 1);
}
