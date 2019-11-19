#include <iostream>
#include <string>
#include "../src/collectors.hpp"
#include "catch.hpp"

SCENARIO( "Vectors can be instantiated and added to", "[vector_test]") {
    GIVEN( "A custom vector") {
        auto the_vector = collectors::vector<int>();

        REQUIRE( the_vector.size() == 0);
        WHEN("Items are added") {
            for (int i = 0; i < 10; i++) {
                the_vector.push_back(10 - i);
            }

                THEN("The size of the vector changes") {
                    REQUIRE( the_vector.size() == 10);
                }
        }
    }
}
