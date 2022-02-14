#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE("Default Constructor", "[LinkedList]") {
    LinkedList<int> ll;
    REQUIRE(ll.getLength() == 0);
    REQUIRE(ll.isEmpty());
}

TEST_CASE("Copy Constructor", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    l1.insert(1, 3);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.getEntry(1) == 3);
    LinkedList<int> l2(l1);
    REQUIRE(!l2.isEmpty());
    REQUIRE(l2.getLength() == 1);
    REQUIRE(l2.getEntry(1) == 3);
}

TEST_CASE("Copy Assignment", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    l1.insert(1, 3);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.getEntry(1) == 3);
    LinkedList<int> l2 = l1;
    REQUIRE(!l2.isEmpty());
    REQUIRE(l2.getLength() == 1);
    REQUIRE(l2.getEntry(1) == 3);
}

TEST_CASE("Swap Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.getEntry(1) == 3);
    LinkedList<int> l2;
    REQUIRE(l2.getLength() == 0);
    REQUIRE(l2.isEmpty());
    REQUIRE(l2.insert(1, 15));
    REQUIRE(!l2.isEmpty());
    REQUIRE(l2.getLength() == 1);
    REQUIRE(l2.getEntry(1) == 15);
    l1.swap(l1, l2);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.getEntry(1) == 15);
    REQUIRE(!l2.isEmpty());
    REQUIRE(l2.getLength() == 1);
    REQUIRE(l2.getEntry(1) == 3);
}

TEST_CASE("isEmpty Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.remove(1));
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.getLength() == 0);
}

TEST_CASE("getLength Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.insert(1, 3));
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.insert(2, 15));
    REQUIRE(l1.getLength() == 2);
    REQUIRE(l1.remove(1));
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.remove(1));
    REQUIRE(l1.getLength() == 0);
}

TEST_CASE("insert Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getLength() == 1);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.insert(2, 15));
    REQUIRE(l1.getEntry(2) == 15);
    REQUIRE(l1.getLength() == 2);
    REQUIRE(l1.remove(1));
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.remove(1));
    REQUIRE(l1.getLength() == 0);
}

TEST_CASE("remove Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getLength() == 1);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.insert(2, 15));
    REQUIRE(l1.getEntry(2) == 15);
    REQUIRE(l1.getLength() == 2);
    REQUIRE(l1.remove(1));
    REQUIRE(l1.getEntry(1) == 15);
    REQUIRE(l1.getLength() == 1);
    REQUIRE(l1.remove(1));
    REQUIRE(l1.getLength() == 0);
}

TEST_CASE("clear Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getLength() == 1);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.insert(2, 15));
    REQUIRE(l1.getEntry(2) == 15);
    REQUIRE(l1.getLength() == 2);
    l1.clear();
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
}

TEST_CASE("getEntry Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getLength() == 1);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.insert(2, 15));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getEntry(2) == 15);
    REQUIRE(l1.insert(2, 5));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getEntry(2) == 5);
    REQUIRE(l1.getEntry(3) == 15);
    REQUIRE(l1.getLength() == 3);
    l1.clear();
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
}

TEST_CASE("setEntry Method", "[LinkedList]") {
    LinkedList<int> l1;
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 3));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getLength() == 1);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.insert(2, 15));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getEntry(2) == 15);
    REQUIRE(l1.insert(2, 5));
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(l1.getEntry(2) == 5);
    REQUIRE(l1.getEntry(3) == 15);
    l1.setEntry(1, 1);
    REQUIRE(l1.getEntry(1) == 1);
    REQUIRE(l1.getEntry(2) == 5);
    REQUIRE(l1.getEntry(3) == 15);
    l1.setEntry(3, -12);
    REQUIRE(l1.getEntry(1) == 1);
    REQUIRE(l1.getEntry(2) == 5);
    REQUIRE(l1.getEntry(3) == -12);
    REQUIRE(l1.getLength() == 3);
    l1.clear();
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
}
