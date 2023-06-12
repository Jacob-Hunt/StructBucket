/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file TreePropertiesTests.cpp
 * @brief Unit tests for a Red Black Tree implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../TestRedBlackTree.hpp"

TEST_CASE("Red Black Tree properties hold when inserting elements in order", "[RedBlackTree]")
{
    TestRedBlackTree<int, int> testTree;
    for (int i = 0; i < 20; i++) testTree.insert(i, i);

    SECTION("Root node is black")
    {
        REQUIRE(testTree.isRootNodeBlack());
    }

    SECTION("Tree does not contain any red nodes with red children")
    {
        REQUIRE(testTree.noRedNodesWithRedChildren());
    }

    SECTION("All paths from root to leaves contain the same number of black nodes")
    {
        REQUIRE(testTree.blackNodePathEqualityHolds());
    }

    SECTION("The tree is sorted")
    {
        REQUIRE(testTree.isTreeSorted());
    }
}

TEST_CASE("Red Black Tree properties hold when inserting elements in reverse order", "[RedBlackTree]")
{
    TestRedBlackTree<int, int> testTree;
    for (int i = 20; i > 0; i--) testTree.insert(i, i);

    SECTION("Root node is black")
    {
        REQUIRE(testTree.isRootNodeBlack());
    }

    SECTION("Tree does not contain any red nodes with red children")
    {
        REQUIRE(testTree.noRedNodesWithRedChildren());
    }

    SECTION("All paths from root to leaves contain the same number of black nodes")
    {
        REQUIRE(testTree.blackNodePathEqualityHolds());
    }

    SECTION("The tree is sorted")
    {
        REQUIRE(testTree.isTreeSorted());
    }
}

TEST_CASE("Red Black Tree properties hold when inserting elements in a random order", "[RedBlackTree]")
{
    TestRedBlackTree<int, int> testTree;
    int shuffledKeys[20] = {13, 7, 15, 3, 17, 8, 6, 9, 2, 18, 12, 20, 19, 10, 5, 4, 11, 16, 1, 14};
    for (int i = 0; i < 20; i++) testTree.insert(shuffledKeys[i], shuffledKeys[i]);

    SECTION("Root node is black")
    {
        REQUIRE(testTree.isRootNodeBlack());
    }

    SECTION("Tree does not contain any red nodes with red children")
    {
        REQUIRE(testTree.noRedNodesWithRedChildren());
    }

    SECTION("All paths from root to leaves contain the same number of black nodes")
    {
        REQUIRE(testTree.blackNodePathEqualityHolds());
    }

    SECTION("The tree is sorted")
    {
        REQUIRE(testTree.isTreeSorted());
    }
}

TEST_CASE("Red Black Tree properties hold after removing nodes", "[RedBlackTree]")
{
    TestRedBlackTree<int, int> testTree;
    int shuffledKeys[20] = {13, 7, 15, 3, 17, 8, 6, 9, 2, 18, 12, 20, 19, 10, 5, 4, 11, 16, 1, 14};
    for (int i = 0; i < 20; i++) testTree.insert(shuffledKeys[i], shuffledKeys[i]);
    for (int i = 0; i < 10; i += 4) testTree.remove(i);

    SECTION("Root node is black")
    {
        REQUIRE(testTree.isRootNodeBlack());
    }

    SECTION("Tree does not contain any red nodes with red children")
    {
        REQUIRE(testTree.noRedNodesWithRedChildren());
    }

    SECTION("All paths from root to leaves contain the same number of black nodes")
    {
        REQUIRE(testTree.blackNodePathEqualityHolds());
    }

    SECTION("The tree is sorted")
    {
        REQUIRE(testTree.isTreeSorted());
    }
}

TEST_CASE("Red Black Tree properties hold for an empty tree", "[RedBlackTree]")
{
    TestRedBlackTree<int, int> testTree;

    SECTION("Root node is black")
    {
        REQUIRE(testTree.isRootNodeBlack());
    }

    SECTION("Tree does not contain any red nodes with red children")
    {
        REQUIRE(testTree.noRedNodesWithRedChildren());
    }

    SECTION("All paths from root to leaves contain the same number of black nodes")
    {
        REQUIRE(testTree.blackNodePathEqualityHolds());
    }

    SECTION("The tree is sorted")
    {
        REQUIRE(testTree.isTreeSorted());
    }
}

TEST_CASE("Red Black Tree properties hold after clearing tree", "[RedBlackTree]")
{
    TestRedBlackTree<int, int> testTree;
    int shuffledKeys[20] = {13, 7, 15, 3, 17, 8, 6, 9, 2, 18, 12, 20, 19, 10, 5, 4, 11, 16, 1, 14};
    for (int i = 0; i < 20; i++) testTree.insert(shuffledKeys[i], shuffledKeys[i]);
    testTree.clear();

    SECTION("Root node is black")
    {
        REQUIRE(testTree.isRootNodeBlack());
    }

    SECTION("Tree does not contain any red nodes with red children")
    {
        REQUIRE(testTree.noRedNodesWithRedChildren());
    }

    SECTION("All paths from root to leaves contain the same number of black nodes")
    {
        REQUIRE(testTree.blackNodePathEqualityHolds());
    }

    SECTION("The tree is sorted")
    {
        REQUIRE(testTree.isTreeSorted());
    }
}