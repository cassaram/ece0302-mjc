#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "add.hpp"

// force template expansion
template class Add<int>;

TEST_CASE("Test add 1", "[Add]"){

  Add<int> a;
  REQUIRE(a.call(1,2)==3);
}

TEST_CASE("Test add 2", "[Add]") {

  Add<double> a;
  REQUIRE(a.call(2.5,2.5) == 5.0);
}