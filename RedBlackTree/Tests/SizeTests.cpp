/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file SizeTests.cpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../TestRedBlackTree.hpp"

TEST_CASE("Tree initializes to size 0", "[RedBlackTree][size()]")
{
    RedBlackTree<int, int> testTree;
    REQUIRE(testTree.size() == 0);
}

TEST_CASE("Returns the correct size after inserting nodes", "[RedBlackTree][size()]")
{
    RedBlackTree<int, int> testTree;
    for (int i = 0; i < 5; i++) testTree.insert(i, i);
    REQUIRE(testTree.size() == 5);
}

TEST_CASE("Returns the correct size after deleting nodes", "[RedBlackTree][size()]")
{
    RedBlackTree<int, int> testTree;
    for (int i = 0; i < 5; i++) testTree.insert(i, i);
    for (int i = 0; i < 2; i++) testTree.remove(i);
    REQUIRE(testTree.size() == 3);
}

TEST_CASE("Returns the correct size after attempting to deleting node that does not exist", "[RedBlackTree][size()]")
{
    RedBlackTree<int, int> testTree;
    for (int i = 0; i < 5; i++) testTree.insert(i, i);
    testTree.remove(10);
    REQUIRE(testTree.size() == 5);
}
