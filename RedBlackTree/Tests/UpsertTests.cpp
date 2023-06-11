/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file UpsertTests.hpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../RedBlackTree.hpp"

TEST_CASE("Correctly upserts a new key-value pair", "[RedBlackTree][upsert()]")
{
    RedBlackTree<int, std::string> testTree;
    testTree.insert(1, "one");

    bool result = testTree.upsert(5, "five");

    SECTION("Returns false if the key did not already exist in the tree")
    {
        REQUIRE(result == false);
    }

    SECTION("The tree contains the key-value pair after being upserted")
    {
        REQUIRE(*testTree.get(5) == "five");
    }
}

TEST_CASE("Correctly upserts when the key exists in the tree", "[RedBlackTree][upsert()]")
{
    RedBlackTree<int, std::string> testTree;
    testTree.insert(10, "ten");

    bool result = testTree.upsert(10, "updated");

    SECTION("Returns true if the key already exists in the tree")
    {
        REQUIRE(result == true);
    }

    SECTION("The key is associated with the updated value after the upsert")
    {
        REQUIRE(*testTree.get(10) == "updated");
    }
}

TEST_CASE("Correctly inserts into an empty tree", "[RedBlackTree][upsert()]")
{
    RedBlackTree<int, std::string> testTree;

    bool result = testTree.upsert(1, "one");

    SECTION("Returns false if the tree was empty")
    {
        REQUIRE(result == false);
    }

    SECTION("The tree contains the newly inserted node")
    {
        REQUIRE(*testTree.get(1) == "one");
    }
}