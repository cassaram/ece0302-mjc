#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case", "fancyPower"){
    REQUIRE(true);
    // N > 1 tests
    REQUIRE(fancyPower(2, 0) == 1);
    REQUIRE(fancyPower(2, 1) == 2);
    REQUIRE(fancyPower(2, 2) == 4);
    REQUIRE(fancyPower(2, 3) == 8);
    REQUIRE(fancyPower(2, 4) == 16);
    REQUIRE(fancyPower(2, 5) == 32);
    REQUIRE(fancyPower(2, 6) == 64);
    REQUIRE(fancyPower(3, 2) == 9);
    REQUIRE(fancyPower(3, 3) == 27);
    // N = 1 tests
    REQUIRE(fancyPower(1, 1) == 1);
    REQUIRE(fancyPower(1, 2) == 1);
    REQUIRE(fancyPower(1, 3) == 1);
    // N = 0 tests
    REQUIRE(fancyPower(0, 1) == 0);
    REQUIRE(fancyPower(0, 2) == 0);
    REQUIRE(fancyPower(0, 3) == 0);
    REQUIRE(fancyPower(0, 4) == 0);
    // M = 0 tests
    REQUIRE(fancyPower(1, 0) == 1);
    REQUIRE(fancyPower(2, 0) == 1);
    REQUIRE(fancyPower(3, 0) == 1);
    REQUIRE(fancyPower(4, 0) == 1);
    REQUIRE(fancyPower(5, 0) == 1);
    // M = 1 tests
    REQUIRE(fancyPower(1, 1) == 1);
    REQUIRE(fancyPower(2, 1) == 2);
    REQUIRE(fancyPower(3, 1) == 3);
}
