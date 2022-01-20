#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"

// force template expansion
template class Bag<int>;

TEST_CASE("Empty Test", "[Bag]"){
  REQUIRE(true);
}

TEST_CASE("Define Test", "[Bag]"){
  Bag<double> b = Bag<double>();
  REQUIRE(b.isEmpty() == true);
}

TEST_CASE("Add Test", "[Bag]"){
  Bag<double> b = Bag<double>();
  REQUIRE(b.isEmpty() == true);
  b.add(2.5);
  REQUIRE(b.isEmpty() == false);
}

TEST_CASE("Clear Test", "[Bag]"){
  Bag<double> b = Bag<double>();
  b.add(2.5);
  REQUIRE(b.isEmpty() == false);
  b.add(3.5);
  REQUIRE(b.isEmpty() == false);
  b.clear();
  REQUIRE(b.isEmpty() == true);
}

TEST_CASE("Remove Test", "[Bag]"){
  Bag<double> b = Bag<double>();
  b.add(2.5);
  REQUIRE(b.isEmpty() == false);
  b.remove(2.5);
  REQUIRE(b.isEmpty() == true);
}

TEST_CASE("Frequency Test", "[Bag]"){
  Bag<int> b = Bag<int>();
  b.add(1);
  b.add(2);
  b.add(2);
  b.add(3);
  b.add(3);
  b.add(3);
  b.add(4);
  REQUIRE(b.getFrequencyOf(1) == 1);
  REQUIRE(b.getFrequencyOf(2) == 2);
  REQUIRE(b.getFrequencyOf(3) == 3);
  REQUIRE(b.getFrequencyOf(4) == 1);
}

TEST_CASE("Contains Test", "[Bag]"){
  Bag<char> b = Bag<char>();
  b.add('e');
  b.add('c');
  b.add('e');
  REQUIRE(b.contains('e') == true);
  REQUIRE(b.contains('a') == false);
  REQUIRE(b.contains(2) == false);
}