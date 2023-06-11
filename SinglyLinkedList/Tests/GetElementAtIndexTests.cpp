/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file GetElementAtIndexTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
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