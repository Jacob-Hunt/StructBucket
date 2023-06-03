/**
 * MIT License
 * 
 * Copyright (c) 2023 Jacob Hunt
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file Tests.cpp
 * @brief Catch2 unit tests from all collections in the project
 * @author Jacob Hunt
 * Contact: (jacobhuntdevelopment@gmail.com)
 */

// Macro to build main method for unit test driver
#define CATCH_CONFIG_MAIN

// Include unit testing library
#include "../Libraries/Catch2/catch.hpp"

// Include all unit tests for all collections in the project
#include "../Lists/SinglyLinkedList/Tests/GetElementAtIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/GetLengthTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/GetFirstIndexOfTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/InsertAtIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/DeleteFromIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/UpdateAtIndexTests.cpp"
#include "../Lists/SinglyLinkedList/Tests/ClearTests.cpp"
