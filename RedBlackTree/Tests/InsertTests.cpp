/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file InsertTests.hpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../TestRedBlackTree.hpp"

TEST_CASE("Tree contains nodes after they are inserted", "[RedBlackTree][insert()]")
{
    TestRedBlackTree<int, int> testTree;
    testTree.insert(0, 3);
    testTree.insert(1, 2);
    testTree.insert(2, 1);
    testTree.insert(3, 0);

    REQUIRE(testTree.contains(0));
    REQUIRE(testTree.contains(1));
    REQUIRE(testTree.contains(2));
    REQUIRE(testTree.contains(3));
}

TEST_CASE("Trying to insert duplicate keys throws an exception", "[RedBlackTree][insert()]")
{
    TestRedBlackTree<int, int> testTree;
    testTree.insert(1, 0);
    testTree.insert(2, 0);

    REQUIRE_THROWS(testTree.insert(2, 0));
}
