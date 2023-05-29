#include "../SinglyLinkedList.h"

TEST_CASE( "This test should pass", "[SinglyLinkedList]" ) {
    REQUIRE( 1 == 1 );
}

TEST_CASE( "This test should fail", "[SinglyLinkedList]" ) {
    REQUIRE( 1 == 2 );
}