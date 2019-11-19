#include <iostream>
#include <string>
#include "../src/collectors.hpp"
#include "catch.hpp"


SCENARIO( "Vectors can be instantiated and added to", "[vector_add]") {
    GIVEN( "A custom vector") {
        auto the_vector = collectors::vector<int>();
        REQUIRE( the_vector.size() == 0);
        REQUIRE (the_vector.capacity() == 10);
        WHEN("Items are added") {
            for (int i = 0; i < 100; i++) {
                the_vector.push_back(100 - i);
            }

                THEN("The size of the vector changes") {
                    REQUIRE( the_vector.size() == 100);
                }
                THEN("The capacity of the vector changes") {
                    REQUIRE( the_vector.capacity() > 100);
                }
        }
    }
}
