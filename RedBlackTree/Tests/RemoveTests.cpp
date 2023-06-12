/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file RemoveTests.hpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../RedBlackTree.hpp"

TEST_CASE("Expected behavior for RBT remove method", "[RedBlackTree][remove()]")
{
    RedBlackTree<int, std::string> testTree;
    testTree.insert(10, "ten");
    testTree.insert(5, "five");
    testTree.insert(15, "fifteen");
    testTree.insert(2, "two");
    testTree.insert(7, "seven");
    testTree.insert(12, "twelve");
    testTree.insert(20, "twenty");

    SECTION("Removing a node that exists in the tree returns true")
    {
        REQUIRE(testTree.remove(2));
    }

    SECTION("Removing a node that doesn't exist in the tree returns false")
    {
        REQUIRE_FALSE(testTree.remove(8));
    }

    SECTION("Removing a node reduces the size of the tree by 1")
    {
        int initialSize = testTree.size();
        testTree.remove(2);
        int newSize = testTree.size();
        REQUIRE(newSize == initialSize - 1);
    }

    SECTION("Removing a node removes the corresponding node from the tree")
    {
        testTree.remove(2);
        REQUIRE(testTree.get(2) == NULL);
    }
}
