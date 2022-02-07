#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Empty Test", "[LimitedSizeBag]"){
    REQUIRE(true);
}

TEST_CASE("Default Constructor Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
    REQUIRE(b.isEmpty());
}

TEST_CASE("Copy Constructor Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b1;
    REQUIRE(b1.isEmpty());
    REQUIRE(b1.add(12));
    REQUIRE(b1.add(4));
    REQUIRE(b1.add(4));
    REQUIRE(b1.add(5));
    REQUIRE(b1.add(6));
    REQUIRE(!b1.add(7));
    LimitedSizeBag<int> b2(b1);
    REQUIRE(!b2.isEmpty());
    REQUIRE(b2.contains(12));
    REQUIRE(b2.contains(4));
    REQUIRE(!b2.contains(7));
}

TEST_CASE("Copy Assignment Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b1;
    REQUIRE(b1.isEmpty());
    REQUIRE(b1.add(12));
    REQUIRE(b1.add(4));
    REQUIRE(b1.add(4));
    REQUIRE(b1.add(5));
    REQUIRE(b1.add(6));
    REQUIRE(!b1.add(7));
    LimitedSizeBag<int> b2;
    b2 = b1;
    REQUIRE(!b2.isEmpty());
    REQUIRE(b2.contains(12));
    REQUIRE(b2.contains(4));
    REQUIRE(!b2.contains(7));
}

TEST_CASE("Add Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
    REQUIRE(b.add(1));
    REQUIRE(b.add(2));
    REQUIRE(b.add(3));
    REQUIRE(b.add(3));
    REQUIRE(b.add(4));
    REQUIRE(!b.add(4));
    REQUIRE(b.getFrequencyOf(4) == 1);
    REQUIRE(!b.isEmpty());
    REQUIRE(b.getCurrentSize() == 5);
}


TEST_CASE("Remove Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
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

TEST_CASE("isEmpty Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
    REQUIRE(b.isEmpty());
    b.add(1);
    REQUIRE(!b.isEmpty());
    b.remove(1);
    REQUIRE(b.isEmpty());
}

TEST_CASE("getCurrentSize Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
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

TEST_CASE("Clear Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
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

TEST_CASE("getFrequencyOf Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
    REQUIRE(b.isEmpty());
    REQUIRE(b.add(1));
    REQUIRE(b.add(1));
    REQUIRE(b.add(2));
    REQUIRE(b.add(2));
    REQUIRE(b.add(2));
    REQUIRE(!b.add(5));
    REQUIRE(b.getFrequencyOf(1) == 2);
    REQUIRE(b.getFrequencyOf(2) == 3);
    REQUIRE(b.getFrequencyOf(3) == 0);
    REQUIRE(b.getFrequencyOf(4) == 0);
    REQUIRE(b.getFrequencyOf(5) == 0);
}

TEST_CASE("Contains Method Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
    REQUIRE(b.isEmpty());
    REQUIRE(b.add(1));
    REQUIRE(b.add(1));
    REQUIRE(b.add(2));
    REQUIRE(b.add(2));
    REQUIRE(b.add(2));
    REQUIRE(!b.add(5));
    REQUIRE(b.contains(1));
    REQUIRE(b.contains(2));
    REQUIRE(!b.contains(3));
    REQUIRE(!b.contains(4));
    REQUIRE(!b.contains(5));
}
