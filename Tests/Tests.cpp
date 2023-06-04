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
#include "../Lists/SinglyLinkedList/Tests/ClearTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/DeleteFromIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/DestructorTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/GetElementAtIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/GetFirstIndexOfTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/GetLengthTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/InsertAtIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/UpdateAtIndexTests.cpp"
