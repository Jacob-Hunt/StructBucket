/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file GetTests.hpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../RedBlackTree.hpp"

TEST_CASE("Retrieves pointer to the value for a key that exists in the tree")
{
    RedBlackTree<int, std::string> testTree;
    testTree.insert(1, "one");
    testTree.insert(2, "two");
    testTree.insert(3, "three");
    REQUIRE(*testTree.get(1) == "one");
    REQUIRE(*testTree.get(2) == "two");
    REQUIRE(*testTree.get(3) == "three");
}

TEST_CASE("Retrieves null pointer when key does not exist in the tree")
{
    RedBlackTree<int, std::string> testTree;
    testTree.insert(1, "one");
    testTree.insert(2, "two");
    testTree.insert(3, "three");
    REQUIRE(testTree.get(5) == NULL);
}

TEST_CASE("Retrieves null pointer when trying to retrieve from an empty tree")
{
    RedBlackTree<int, std::string> testTree;
    REQUIRE(testTree.get(1) == NULL);
}
