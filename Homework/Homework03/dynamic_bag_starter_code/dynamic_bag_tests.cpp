#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Default Constructor Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.isEmpty());
}

TEST_CASE("Copy Constructor Test", "[DynamicBag]") {
    DynamicBag<int> b1;
    REQUIRE(b1.isEmpty());
    b1.add(12);
    b1.add(4);
    DynamicBag<int> b2(b1);
    REQUIRE(!b1.isEmpty());
    REQUIRE(b1.contains(12));
    REQUIRE(b1.contains(4));
    REQUIRE(!b1.contains(5));
}

TEST_CASE("Copy Assignment Test", "[DynamicBag]") {
    DynamicBag<int> b1;
    REQUIRE(b1.isEmpty());
    b1.add(12);
    b1.add(4);
    DynamicBag <int> b2;
    b2 = b1;
    REQUIRE(!b1.isEmpty());
    REQUIRE(b1.contains(12));
    REQUIRE(b1.contains(4));
    REQUIRE(!b1.contains(5));
}

TEST_CASE("Add Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    b.add(1);
    b.add(2);
    b.add(3);
    b.add(3);
    b.add(4);
    REQUIRE(!b.isEmpty());
    REQUIRE(b.getCurrentSize() == 5);
}


TEST_CASE("Remove Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.isEmpty());
    REQUIRE(b.getCurrentSize() == 0);
    b.add(1);
    REQUIRE(b.getCurrentSize() == 1);
    b.add(2);
    REQUIRE(b.getCurrentSize() == 2);
    b.add(3);
    REQUIRE(b.getCurrentSize() == 3);
    b.add(3);
    REQUIRE(b.getCurrentSize() == 4);
    b.add(4);
    REQUIRE(b.getCurrentSize() == 5);
    REQUIRE(!b.isEmpty());
    b.remove(1);
    REQUIRE(b.getCurrentSize() == 4);
    b.remove(2);
    REQUIRE(b.getCurrentSize() == 3);
    b.remove(3);
    REQUIRE(b.getCurrentSize() == 2);
    b.remove(4);
    REQUIRE(b.getCurrentSize() == 1);
    b.remove(3);
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
}

TEST_CASE("isEmpty Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.isEmpty());
    b.add(1);
    REQUIRE(!b.isEmpty());
    b.remove(1);
    REQUIRE(b.isEmpty());
}

TEST_CASE("getCurrentSize Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    b.add(1);
    REQUIRE(b.getCurrentSize() == 1);
    b.add(1);
    REQUIRE(b.getCurrentSize() == 2);
    b.remove(1);
    REQUIRE(b.getCurrentSize() == 1);
    b.remove(1);
    REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("Clear Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.isEmpty());
    b.add(1);
    b.add(2);
    b.add(3);
    REQUIRE(b.getCurrentSize() == 3);
    REQUIRE(!b.isEmpty());
    b.clear();
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
}

TEST_CASE("getFrequencyOf Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.isEmpty());
    b.add(1);
    b.add(1);
    b.add(2);
    b.add(2);
    b.add(2);
    b.add(5);
    REQUIRE(b.getFrequencyOf(1) == 2);
    REQUIRE(b.getFrequencyOf(2) == 3);
    REQUIRE(b.getFrequencyOf(3) == 0);
    REQUIRE(b.getFrequencyOf(4) == 0);
    REQUIRE(b.getFrequencyOf(5) == 1);
}

TEST_CASE("Contains Method Test", "[DynamicBag]") {
    DynamicBag<int> b;
    REQUIRE(b.isEmpty());
    b.add(1);
    b.add(1);
    b.add(2);
    b.add(2);
    b.add(2);
    b.add(5);
    REQUIRE(b.contains(1));
    REQUIRE(b.contains(2));
    REQUIRE(!b.contains(3));
    REQUIRE(!b.contains(4));
    REQUIRE(b.contains(5));
}
