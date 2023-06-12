/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file ClearTests.cpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../TestRedBlackTree.hpp"

TEST_CASE("Clearing tree results in an empty tree", "[RedBlackTree][clear()]")
{
    TestRedBlackTree<int, std::string> testTree;
    testTree.insert(10, "ten");
    testTree.insert(5, "five");
    testTree.insert(15, "fifteen");
    testTree.insert(2, "two");
    testTree.insert(7, "seven");
    testTree.insert(12, "twelve");
    testTree.insert(20, "twenty");
    testTree.clear();

    SECTION("Clearing the tree results in a null root")
    {
        REQUIRE(testTree.isRootNull());
    }

    SECTION("Clearing the tree results in an empty tree")
    {
        REQUIRE(testTree.size() == 0);
    }
}