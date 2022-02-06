#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case", "fancyPower"){
    REQUIRE(true);
    REQUIRE(fancyPower(2, 2) == 4);
    REQUIRE(fancyPower(3, 2) == 9);
}
