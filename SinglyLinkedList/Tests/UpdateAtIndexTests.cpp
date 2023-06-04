/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file UpdateAtIndexTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../SinglyLinkedList.hpp"

TEST_CASE("Updates an element at a valid index", "[SinglyLinkedList][updateElementAtIndex()]")
{
    SinglyLinkedList<int> testList;
    testList.insertAtIndex(0, 10);
    testList.insertAtIndex(1, 20);
    testList.insertAtIndex(2, 30);

    testList.updateAtIndex(1, 25);

    REQUIRE(testList.getElementAtIndex(1) == 25);
}

TEST_CASE("Throws exception when updating at invalid index", "[SinglyLinkedList][updateElementAtIndex()]")
{
    SinglyLinkedList<int> testList;
    testList.insertAtIndex(0, 10);
    testList.insertAtIndex(1, 20);
    testList.insertAtIndex(2, 30);

    SECTION("Throws exception when updating at out-of-bounds index")
    {
        REQUIRE_THROWS(testList.updateAtIndex(10, 40));
    }

    SECTION("Throws exception when updating at negative index")
    {
        REQUIRE_THROWS(testList.updateAtIndex(-1, 40));
    }
}
