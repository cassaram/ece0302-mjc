#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

TEST_CASE( "Test Constructor", "[deque]" ) {
    Deque<int> d;
    REQUIRE(d.isEmpty());
}

TEST_CASE("Test copy constructor", "[deque]") {
    Deque<int> d1;
    REQUIRE(d1.isEmpty());
    d1.pushBack(1);
    REQUIRE(!d1.isEmpty());
    Deque<int> d2(d1);
    REQUIRE(!d2.isEmpty());
    d2.popBack();
    REQUIRE(!d1.isEmpty());
    REQUIRE(d2.isEmpty());
}

TEST_CASE("Test copy assignment", "[deque]") {
    Deque<int> d1;
    REQUIRE(d1.isEmpty());
    d1.pushBack(1);
    REQUIRE(!d1.isEmpty());
    Deque<int> d2 = d1;
    REQUIRE(!d2.isEmpty());
    d2.popBack();
    REQUIRE(!d1.isEmpty());
    REQUIRE(d2.isEmpty());
}

TEST_CASE("Test isEmpty", "[deque]") {
    Deque<int> d;
    REQUIRE(d.isEmpty());
    d.pushFront(1);
    REQUIRE(!d.isEmpty());
    d.popFront();
    REQUIRE(d.isEmpty());
}

TEST_CASE("Test pushFront", "[deque]") {
    Deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.pushFront(i);
        REQUIRE(d.front() == i);
        REQUIRE(d.back() == 0);
    }
}

TEST_CASE("Test popFront", "[deque]") {
    Deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.pushFront(i);
    }
    for (int i = 9; i >= 0; i--) {
        REQUIRE(d.front == i);
        d.popFront();
    }
}

TEST_CASE("Test front", "[deque]") {
    Deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.pushFront(i);
        REQUIRE(d.front == i);
    }
    for (int i = 9; i >= 0; i--) {
        REQUIRE(d.front == i);
        d.popFront();
    }
}

TEST_CASE("Test pushBack", "[deque]") {
    Deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.pushBack(i);
        REQUIRE(d.back() == i);
        REQUIRE(d.front() == 0);
    }
}

TEST_CASE("Test popBack", "[deque]") {
    Deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.pushBack(i);
    }
    for (int i = 9; i >= 0; i--) {
        REQUIRE(d.back() == i);
        d.popBack();
    }
}

TEST_CASE("Test back", "[deque]") {
    Deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.pushBack(i);
        REQUIRE(d.back() == i);
        REQUIRE(d.front() == 0);
    }
    for (int i = 9; i >= 0; i--) {
        REQUIRE(d.back() == i);
        d.popBack();
    }
}
