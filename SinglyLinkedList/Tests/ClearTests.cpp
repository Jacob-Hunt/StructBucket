/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file ClearTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../SinglyLinkedList.hpp"

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