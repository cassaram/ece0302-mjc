#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"

typedef SortedList<int, DynamicArrayList<int> > slst;

TEST_CASE("Test SortedList constructor", "[sorted list]") {
    slst l;
    REQUIRE(l.isEmpty());
}

TEST_CASE("Test SortedList copy constructor", "[sorted list]") {
    slst l1;
    REQUIRE(l1.isEmpty());
    l1.insert(0);
    REQUIRE(!l1.isEmpty());
    slst l2(l1);
    REQUIRE(l2.getLength() == l1.getLength());
    REQUIRE(l2.isEmpty());
}

TEST_CASE("Test SortedList copy assignment", "[sorted list]") {
    slst l1;
    REQUIRE(l1.isEmpty());
    l1.insert(0);
    REQUIRE(!l1.isEmpty());
    slst l2 = l1;
    REQUIRE(l2.getLength() == l1.getLength());
    REQUIRE(l2.isEmpty());
}

TEST_CASE("Test SortedList isEmpty method", "[sorted list]") {
    slst l1;
    REQUIRE(l1.isEmpty());
    l1.insert(12);
    REQUIRE(!l1.isEmpty());
    l1.clear();
    REQUIRE(l1.isEmpty());
}

TEST_CASE("Test SortedList getLength method", "[sorted list]") {
    slst l1;
    for (std::size_t i = 0; i < 13; i++) {
        REQUIRE(l1.getLength() == i);
        l1.insert(i);
    }
    REQUIRE(l1.getLength() == 13);
    l1.clear();
    REQUIRE(l1.getLength() == 0);
}

TEST_CASE("Test SortedList insert method", "[sorted list]") {
    slst l1;
    for (std::size_t i = 13; i > 0; i--) {
        l1.insert(i);
    }
    REQUIRE(l1.getLength() == 13);
    for (std::size_t i = 0; i < 12; i++) {
        REQUIRE(l1.getEntry(i) <= l1.getEntry(i + 1));
    }
}

TEST_CASE("Test SortedList remove method", "[sorted list]") {
    slst l1;
    for (std::size_t i = 13; i > 0; i--) {
        l1.insert(i);
    }
    REQUIRE(l1.getLength() == 13);
    l1.remove(3);
    REQUIRE(l1.getLength() == 12);
    for (std::size_t i = 0; i < 11; i++) {
        REQUIRE(l1.getEntry(i) <= l1.getEntry(i + 1));
        REQUIRE(l1.getEntry(i) != 3);
    }
}

TEST_CASE("Test SortedList removeAt method", "[sorted list]") {
    slst l1;
    for (std::size_t i = 13; i > 0; i--) {
        l1.insert(i);
    }
    REQUIRE(l1.getLength() == 13);
    l1.removeAt(0);
    REQUIRE(l1.getLength() == 12);
    for (std::size_t i = 0; i < 11; i++) {
        REQUIRE(l1.getEntry(i) <= l1.getEntry(i + 1));
        REQUIRE(l1.getEntry(i) != 1);
    }
}

TEST_CASE("Test SortedList clear method", "[sorted list]") {
    slst l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    l1.insert(0);
    l1.insert(13);
    REQUIRE(l1.getLength() != 0);
    REQUIRE(!l1.isEmpty());
    l1.clear();
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
}

TEST_CASE("Test SortedList getEntry method", "[sorted list]") {
    slst l1;
    for (std::size_t i = 13; i > 0; i--) {
        l1.insert(i);
    }
    for (std::size_t i = 0; i < 13; i++) {
        REQUIRE(l1.getEntry(i) == i+1);
    }
}

TEST_CASE("Test SortedList getPosition method", "[sorted list]") {
    slst l1;
    for (std::size_t i = 13; i > 0; i--) {
        l1.insert(i);
    }
    for (std::size_t i = 0; i < 13; i++) {
        REQUIRE(l1.getPosition(i+1) == i);
    }

    REQUIRE(l1.getPosition(15) == -1 * l1.getLength());
}
