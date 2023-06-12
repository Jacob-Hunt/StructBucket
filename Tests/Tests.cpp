/**
 * Copyright (c) 2023 Jacob Hunt
 * 
 * @file Tests.cpp
 * @brief Catch2 unit tests from all collections in the project
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

// Macro to build main method for unit test driver
#define CATCH_CONFIG_MAIN

// Include unit testing library
#include "../Libraries/Catch2/catch.hpp"

// Include all unit tests for all collections in the project
#include "../RedBlackTree/Tests/ClearTests.cpp"
#include "../RedBlackTree/Tests/TreePropertiesTests.cpp"
#include "../RedBlackTree/Tests/InsertTests.cpp"
#include "../RedBlackTree/Tests/RemoveTests.cpp"
#include "../RedBlackTree/Tests/UpdateTests.cpp"
#include "../RedBlackTree/Tests/UpsertTests.cpp"
#include "../SinglyLinkedList/Tests/ClearTests.cpp"
#include "../SinglyLinkedList/Tests/DeleteFromIndexTests.cpp"
#include "../SinglyLinkedList/Tests/DestructorTests.cpp"
#include "../SinglyLinkedList/Tests/GetElementAtIndexTests.cpp"
#include "../SinglyLinkedList/Tests/GetFirstIndexOfTests.cpp"
#include "../SinglyLinkedList/Tests/GetLengthTests.cpp"
#include "../SinglyLinkedList/Tests/InsertAtIndexTests.cpp"
#include "../SinglyLinkedList/Tests/UpdateAtIndexTests.cpp"
