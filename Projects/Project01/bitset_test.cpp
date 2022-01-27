#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE("Test bitset construction", "[bitset]") {
    Bitset b;
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE("Test bitset size constructor", "[bitset]") {
    Bitset b(12);
    REQUIRE(b.size() == 12);
    REQUIRE(b.good());
}

TEST_CASE("Test bitset string constructor", "[bitset]") {
    std::string str = "01010111";
    Bitset b(str);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString() == str);
}

TEST_CASE ("Test size method", "[bitset]") {
    Bitset b(23);
    REQUIRE(b.size() == 23);
}

TEST_CASE ("Test validity method", "[bitset]") {
    Bitset b1;
    Bitset b2(8);
    Bitset b3("1001");
    Bitset b4("121");
    Bitset b5("10a1");
    REQUIRE(b1.good());
    REQUIRE(b2.good());
    REQUIRE(b3.good());
    REQUIRE(!b4.good());
    REQUIRE(!b5.good());
}

TEST_CASE("Test set method", "[bitset]") {
    Bitset b1;
    b1.set(0);
    b1.set(3);
    REQUIRE(b1.good());
    REQUIRE(b1.asString() == "10010000");
    b1.set(8);
    REQUIRE(!b1.good());

    Bitset b2(12);
    b2.set(0);
    b2.set(10);
    b2.set(11);
    REQUIRE(b2.asString() == "100000000011");
    REQUIRE(b2.good());
    b2.set(12);
    REQUIRE(!b2.good());
}

TEST_CASE("Test reset method", "[bitset]") {
    Bitset b("11111111");
    b.reset(0);
    b.reset(3);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "01101111");
    b.reset(8);
    REQUIRE(!b.good());
}

TEST_CASE("Test toggle method", "[bitset]") {
    Bitset b("10101010");
    b.toggle(0);
    b.toggle(3);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "00111010");
    b.toggle(8);
    REQUIRE(!b.good());
}

TEST_CASE("Test test method", "[bitset]") {
    Bitset b("10101010");
    REQUIRE(b.test(0));
    REQUIRE(b.good());
    REQUIRE(!b.test(1));
    REQUIRE(b.good());
    REQUIRE(b.test(2));
    REQUIRE(b.good());
    REQUIRE(!b.test(3));
    REQUIRE(b.good());
    REQUIRE(b.test(4));
    REQUIRE(b.good());
    REQUIRE(!b.test(5));
    REQUIRE(b.good());
    REQUIRE(b.test(6));
    REQUIRE(b.good());
    REQUIRE(!b.test(7));
    REQUIRE(b.good());
    bool temp = b.test(8);
    REQUIRE(!b.good());
}

TEST_CASE("Test asString method", "[bitset]") {
    std::string str1 = "10011001";
    Bitset b1(str1);
    Bitset b2(10);
    b2.set(0);
    b2.set(3);
    b2.set(4);
    b2.set(7);
    REQUIRE(b1.asString() == str1);
    REQUIRE(b2.asString() == "1001100100");
    REQUIRE(b1.good());
    REQUIRE(b2.good());
}
