/**
 * Copyright (c) 2023 Jacob Hunt
 *
 * @file HashTableTests.cpp
 * @brief Unit tests for a Hash Table implementation of a key/value dictionary
 * @author Jacob Hunt
 * @copyright MIT License
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

#include "../../Libraries/Catch2/catch.hpp"
#include "../HashTable.hpp"

TEST_CASE("Insert method behaves as expected when there is no collision", "[HashTable][insert()]")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");

    SECTION("There are no collisions")
    {
        unsigned int hashOfTen = testTable.getHash(10);
        unsigned int hashOfFive = testTable.getHash(5);
        unsigned int hashOfFifteen = testTable.getHash(15);
        REQUIRE(hashOfTen != hashOfFive);
        REQUIRE(hashOfTen != hashOfFifteen);
        REQUIRE(hashOfFive != hashOfFifteen);
    }

    SECTION("Inserting a key/value pair into the table results in the correct number of elements")
    {
        REQUIRE(testTable.size() == 3);
    }

    SECTION("Inserting a key/value pair into the table results in the correct value")
    {
        REQUIRE(*testTable.get(10) == "ten");
        REQUIRE(*testTable.get(5) == "five");
        REQUIRE(*testTable.get(15) == "fifteen");
    }
}

TEST_CASE("Insert method behaves as expected when there are collisions", "[HashTable][insert()]")
{
    HashTable<int, std::string> testTable(1);
    testTable.insert(10, "ten");
    testTable.insert(5, "five");

    SECTION("There is a collision")
    {
        unsigned int hashOfTen = testTable.getHash(10);
        unsigned int hashOfFive = testTable.getHash(5);
        REQUIRE(hashOfTen == hashOfFive);
    }

    SECTION("Inserting a key/value pair into the table results in the correct number of elements in the table after a collision")
    {
        REQUIRE(testTable.size() == 2);
    }

    SECTION("Inserting a key/value pair into the table results in the correct value after a collision")
    {
        REQUIRE(*testTable.get(10) == "ten");
        REQUIRE(*testTable.get(5) == "five");
    }
}

TEST_CASE("Remove function behaves as expected")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");

    SECTION("Removing a key/value pair from the table results in the correct number of elements")
    {
        testTable.remove(10);
        REQUIRE(testTable.size() == 2);
    }

    SECTION("Removing a key/value pair from the table results in a nullptr when trying to retrieve the value")
    {
        testTable.remove(10);
        REQUIRE(testTable.get(10) == nullptr);
    }
}

TEST_CASE("Get function behaves as expected")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");

    SECTION("Getting a key/value pair from the table results in the correct value")
    {
        REQUIRE(*testTable.get(10) == "ten");
        REQUIRE(*testTable.get(5) == "five");
        REQUIRE(*testTable.get(15) == "fifteen");
    }

    SECTION("Getting a key/value pair from the table results in a nullptr when the key does not exist")
    {
        REQUIRE(testTable.get(20) == nullptr);
    }
}

TEST_CASE("Contains function behaves as expected")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");

    SECTION("Contains returns true when the key exists")
    {
        REQUIRE(testTable.contains(10) == true);
        REQUIRE(testTable.contains(5) == true);
        REQUIRE(testTable.contains(15) == true);
    }

    SECTION("Contains returns false when the key does not exist")
    {
        REQUIRE(testTable.contains(20) == false);
    }
}

TEST_CASE("Clear function behaves as expected when there are no collisions")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");
    testTable.clear();

    SECTION("Clearing the table results in the correct number of elements")
    {
        REQUIRE(testTable.size() == 0);
    }

    SECTION("Clearing the table results in a nullptr when trying to retrieve the previously inserted values")
    {
        REQUIRE(testTable.get(10) == nullptr);
        REQUIRE(testTable.get(5) == nullptr);
        REQUIRE(testTable.get(15) == nullptr);
    }
}

TEST_CASE("Clear function behaves as expected when there are collisions")
{
    HashTable<int, std::string> testTable(1);
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.clear();

    SECTION("Clearing the table results in the correct number of elements")
    {
        REQUIRE(testTable.size() == 0);
    }

    SECTION("Clearing the table results in a nullptr when trying to retrieve the previously inserted values")
    {
        REQUIRE(testTable.get(10) == nullptr);
        REQUIRE(testTable.get(5) == nullptr);
    }
}

TEST_CASE("Size function behaves as expected when there are collisions")
{
    HashTable<int, std::string> testTable(1);
    testTable.insert(10, "ten");
    testTable.insert(5, "five");

    REQUIRE(testTable.size() == 2);
}

TEST_CASE("Size function behaves as expected when there are no collisions")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");

    REQUIRE(testTable.size() == 3);
}

TEST_CASE("Empty function behaves as expected")
{
    HashTable<int, std::string> testTable;

    SECTION("Empty returns true when the table is empty")
    {
        REQUIRE(testTable.empty() == true);
    }

    SECTION("Empty returns false when the table is not empty")
    {
        testTable.insert(10, "ten");
        REQUIRE(testTable.empty() == false);
    }
}

TEST_CASE("Print function behaves as expected")
{
    HashTable<int, std::string> testTable;
    testTable.insert(10, "ten");
    testTable.insert(5, "five");
    testTable.insert(15, "fifteen");

    SECTION("Print function prints the correct values")
    {
        std::stringstream outputStream;
        testTable.print(outputStream);
        REQUIRE(outputStream.str() == "5: five\n10: ten\n15: fifteen\n");
    }
}