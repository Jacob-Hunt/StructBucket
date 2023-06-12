/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file DeleteFromIndexTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../SinglyLinkedList.hpp"

TEST_CASE("Throws exception when trying to delete from invalid index", "[SinglyLinkedList][deleteFromIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(1, 'b');
    REQUIRE_THROWS(testList.deleteFromIndex(2));
    REQUIRE(testList.getLength() == 2);
}

TEST_CASE("Deletes the correct element", "[SinglyLinkedList][deleteFromIndex()]")
{
    SinglyLinkedList<char> testList;
    testList.insertAtIndex(0, 'a');
    testList.insertAtIndex(1, 'b');
    testList.insertAtIndex(2, 'c');
    testList.insertAtIndex(3, 'd');

    SECTION("Deletes element at beginning of the list")
    {
        testList.deleteFromIndex(0);
        REQUIRE(testList.getLength() == 3);
        REQUIRE(testList.getElementAtIndex(0) == 'b');
        REQUIRE(testList.getElementAtIndex(1) == 'c');
        REQUIRE(testList.getElementAtIndex(2) == 'd');
    }

    SECTION("Deletes element in middle of the list")
    {
        testList.deleteFromIndex(2);
        REQUIRE(testList.getLength() == 3);
        REQUIRE(testList.getElementAtIndex(0) == 'a');
        REQUIRE(testList.getElementAtIndex(1) == 'b');
        REQUIRE(testList.getElementAtIndex(2) == 'd');
    }

    SECTION("Deletes element at end of the list")
    {
        testList.deleteFromIndex(3);
        REQUIRE(testList.getLength() == 3);
        REQUIRE(testList.getElementAtIndex(0) == 'a');
        REQUIRE(testList.getElementAtIndex(1) == 'b');
        REQUIRE(testList.getElementAtIndex(2) == 'c');
    }
}