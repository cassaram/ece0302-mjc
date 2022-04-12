#define CATCH_CONFIG_MAIN
//#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "heap_priority_queue.h"

TEST_CASE("Test Construction", "[construction]") {
    HeapPriorityQueue<int>  pq;
    REQUIRE(pq.isEmpty());
}

TEST_CASE("Test add", "[add]") {
    HeapPriorityQueue<int>  pq;
    pq.add(25);

    REQUIRE(pq.peek() == 25);
    REQUIRE(!pq.isEmpty());

    pq.add(1);
    REQUIRE(pq.peek() == 25);
    REQUIRE(!pq.isEmpty());

    pq.add(78);
    REQUIRE(pq.peek() == 78);
    REQUIRE(!pq.isEmpty());

    pq.add(4);
    REQUIRE(pq.peek() == 78);
    REQUIRE(!pq.isEmpty());

    pq.add(-1);
    REQUIRE(pq.peek() == 78);
    REQUIRE(!pq.isEmpty());

    pq.add(100);
    REQUIRE(pq.peek() == 100);
    REQUIRE(!pq.isEmpty());
}

TEST_CASE("Test remove", "[remove]") {
    HeapPriorityQueue<int>  pq;
    pq.add(25);
    pq.add(1);
    pq.add(78);

    REQUIRE(pq.peek() == 78);
    REQUIRE(!pq.isEmpty());
    pq.remove();
    REQUIRE(pq.peek() == 25);
    REQUIRE(!pq.isEmpty());
    pq.remove();
    REQUIRE(pq.peek() == 1);
    REQUIRE(!pq.isEmpty());
    pq.remove();
    REQUIRE(pq.isEmpty());
}
