#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE("Default Constructor", "[ArrayList]") {
    ArrayList<int> list;
    REQUIRE(list.isEmpty());
    REQUIRE(list.getLength() == 0);
}

TEST_CASE("Copy Constructor", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.getLength() == 0);
    l1.insert(1, 3);
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    ArrayList<int> l2(l1);
    REQUIRE(l2.getEntry(1) == 3);
    REQUIRE(!l2.isEmpty());
    REQUIRE(l2.getLength() == 1);
}

TEST_CASE("Copy Assignment", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.getLength() == 0);
    l1.insert(1, 3);
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    ArrayList<int> l2 = l1;
    REQUIRE(l2.getEntry(1) == 3);
    REQUIRE(!l2.isEmpty());
    REQUIRE(l2.getLength() == 1);
}

TEST_CASE("IsEmpty Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.getLength() == 0);
    l1.insert(1, 3);
    REQUIRE(l1.getEntry(1) == 3);
    REQUIRE(!l1.isEmpty());
    REQUIRE(l1.getLength() == 1);
    l1.remove(1);
    REQUIRE(l1.isEmpty());
    l1.insert(1, 2);
    REQUIRE(!l1.isEmpty());
    l1.clear();
    REQUIRE(l1.isEmpty());
}

TEST_CASE("GetLength Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.getLength() == 0);
    l1.insert(1,3);
    REQUIRE(l1.getLength() == 1);
    l1.insert(2,5);
    REQUIRE(l1.getLength() == 2);
    l1.insert(3,4);
    REQUIRE(l1.getLength() == 3);
    l1.clear();
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
}

TEST_CASE("Insert Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    l1.insert(1, 1);
    REQUIRE(l1.getEntry(1) == 1);
    l1.insert(2, 2);
    REQUIRE(l1.getEntry(2) == 2);
    l1.insert(3, 3);
    REQUIRE(l1.getEntry(3) == 3);
    l1.insert(4, 4);
    REQUIRE(l1.getEntry(4) == 4);
    l1.insert(1, 5);
    REQUIRE(l1.getEntry(1) == 5);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 3);
    REQUIRE(l1.getEntry(5) == 4);
}

TEST_CASE("Remove Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    l1.insert(1, 1);
    REQUIRE(l1.getEntry(1) == 1);
    l1.insert(2, 2);
    REQUIRE(l1.getEntry(2) == 2);
    l1.insert(3, 3);
    REQUIRE(l1.getEntry(3) == 3);
    l1.insert(4, 4);
    REQUIRE(l1.getEntry(4) == 4);
    l1.insert(1, 5);
    REQUIRE(l1.getEntry(1) == 5);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 3);
    REQUIRE(l1.getEntry(5) == 4);
    l1.remove(1);
    REQUIRE(l1.getEntry(1) == 1);
    REQUIRE(l1.getEntry(2) == 2);
    REQUIRE(l1.getEntry(3) == 3);
    REQUIRE(l1.getEntry(4) == 4);
    REQUIRE(l1.getLength() == 4);
}

TEST_CASE("Clear Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 1));
    REQUIRE(l1.getEntry(1) == 1);
    REQUIRE(l1.insert(2, 2));
    REQUIRE(l1.getEntry(2) == 2);
    REQUIRE(l1.insert(3, 3));
    REQUIRE(l1.getEntry(3) == 3);
    REQUIRE(l1.insert(4, 4));
    REQUIRE(l1.getEntry(4) == 4);
    REQUIRE(l1.insert(1, 5));
    REQUIRE(l1.getEntry(1) == 5);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 3);
    REQUIRE(l1.getEntry(5) == 4);
    l1.clear();
    REQUIRE(l1.getLength() == 0);
    REQUIRE(l1.isEmpty());
}

TEST_CASE("GetEntry Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 1));
    REQUIRE(l1.getEntry(1) == 1);
    REQUIRE(l1.insert(2, 2));
    REQUIRE(l1.getEntry(2) == 2);
    REQUIRE(l1.insert(3, 3));
    REQUIRE(l1.getEntry(3) == 3);
    REQUIRE(l1.insert(4, 4));
    REQUIRE(l1.getEntry(4) == 4);
    REQUIRE(l1.insert(1, 5));
    REQUIRE(l1.getEntry(1) == 5);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 3);
    REQUIRE(l1.getEntry(5) == 4);
}

TEST_CASE("SetEntry Method", "[ArrayList]") {
    ArrayList<int> l1;
    REQUIRE(l1.isEmpty());
    REQUIRE(l1.insert(1, 1));
    REQUIRE(l1.getEntry(1) == 1);
    REQUIRE(l1.insert(2, 2));
    REQUIRE(l1.getEntry(2) == 2);
    REQUIRE(l1.insert(3, 3));
    REQUIRE(l1.getEntry(3) == 3);
    REQUIRE(l1.insert(4, 4));
    REQUIRE(l1.getEntry(4) == 4);
    REQUIRE(l1.insert(1, 5));
    REQUIRE(l1.getEntry(1) == 5);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 3);
    REQUIRE(l1.getEntry(5) == 4);
    l1.setEntry(1, 6);
    REQUIRE(l1.getEntry(1) == 6);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 3);
    REQUIRE(l1.getEntry(5) == 4);
    l1.setEntry(4, 6);
    REQUIRE(l1.getEntry(1) == 6);
    REQUIRE(l1.getEntry(2) == 1);
    REQUIRE(l1.getEntry(3) == 2);
    REQUIRE(l1.getEntry(4) == 6);
    REQUIRE(l1.getEntry(5) == 4);
}
