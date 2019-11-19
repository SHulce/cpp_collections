#include <iostream>
#include <string>
#include "../src/collectors.hpp"
#include "catch.hpp"

SCENARIO("A Stack can have items added and removed in FILO order") {
    GIVEN("A custom stack") {
        auto the_stack = collectors::stack<int>();
        REQUIRE( the_stack.count() == 0);

        WHEN("100 Items are added") {
            for (int i = 0; i < 100; i++) {
                the_stack.push(100 - i);
            }
            THEN("The stack should have count 100") {
                REQUIRE( the_stack.count() == 100);
            }
            WHEN("10 Items are removed") {
                for (int i = 0; i < 10; i++) {
                    the_stack.pop();
                }
                THEN("The stack should have count 90") {
                    REQUIRE( the_stack.count() == 90);
                }
                THEN("The top of the stack should be 10") {
                    REQUIRE( the_stack.peek() == 11);
                    REQUIRE( the_stack.peek() == 11);
                }
            }
        }
    }
}