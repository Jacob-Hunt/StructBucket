/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file UpdateTests.cpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../RedBlackTree.hpp"

TEST_CASE("Correctly updates the value of an existing node", "[RedBlackTree][update()]")
{
    RedBlackTree<int, int> testTree;
    testTree.insert(1, 1);

    testTree.update(1, 5);

    REQUIRE(*(testTree.get(1)) == 5);
}

TEST_CASE("Throws exception with correct message when updating non-existant node", "[RedBlackTree][update()]")
{
    RedBlackTree<int, int> testTree;
    testTree.insert(1, 1);

    REQUIRE_THROWS_WITH(
        testTree.update(2, 2),
        "Could not find Red Black Tree entry with the provided key"
    );
}

TEST_CASE("Correctly updates node multiple times", "[RedBlackTree][update()]")
{
    RedBlackTree<int, int> testTree;
    testTree.insert(1, 10);

    testTree.update(1, 20);
    testTree.update(1, 30);

    REQUIRE(*(testTree.get(1)) == 30);
}
