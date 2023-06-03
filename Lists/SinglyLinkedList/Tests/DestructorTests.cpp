/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file DestructorTests.cpp
 * @brief Unit tests for a singly linked list data structure
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

TEST_CASE("Does not throw an exception when deleting a list", "[SinglyLinkedList][destructor]")
{
    SinglyLinkedList<int>* testList = new SinglyLinkedList<int>();
    testList->insertAtIndex(0, 10);
    testList->insertAtIndex(1, 20);
    testList->insertAtIndex(2, 30);
    REQUIRE_NOTHROW(delete testList);
}