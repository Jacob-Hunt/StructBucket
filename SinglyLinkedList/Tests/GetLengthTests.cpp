/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file GetLengthTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../SinglyLinkedList.hpp"

TEST_CASE("Returns the correct length for an empty list", "[SinglyLinkedList][getLength()]")
{
    SinglyLinkedList<char> testList;
    REQUIRE(testList.getLength() == 0);
}

TEST_CASE("Returns the correct length a list with multiple elements", "[SinglyLinkedList][getLength()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(0, 'b');
    REQUIRE( testList.getLength() == 2 );
}

TEST_CASE("Returns the correct length after elements have been removed", "[SinglyLinkedList][getLength()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(0, 'b');
    testList.deleteFromIndex(1);
    REQUIRE( testList.getLength() == 1 );
}
