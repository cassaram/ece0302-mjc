#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
    INFO("Hint: add a single non-allowable word");
    FindPalindrome b;
    REQUIRE(!b.add("kayak1"));
}

TEST_CASE("Test Default Constructor", "[FindPalindrome]") {
    FindPalindrome b;
    REQUIRE(b.number() == 0);
    REQUIRE(b.toVector().size() == 0);
}

TEST_CASE("Test number method", "[FindPalindrome]") {
    FindPalindrome b;
    REQUIRE(b.add("test"));
    REQUIRE(b.number() == 0);
    REQUIRE(b.add("tset"));
    REQUIRE(b.number() == 1);
    b.clear();
    REQUIRE(b.number() == 0);
    REQUIRE(b.add("noon"));
    REQUIRE(b.number() == 1);
}

TEST_CASE("Test clear method", "[FindPalindrome]") {
    FindPalindrome b;
    REQUIRE(b.number() == 0);
    REQUIRE(b.add("test"));
    REQUIRE(b.add("foo"));
    REQUIRE(b.add("bar"));
    REQUIRE(b.number() != 0);
    b.clear();
    REQUIRE(b.number() == 0);
}

TEST_CASE("Test add(string) method", "[FindPalindrome]") {
    FindPalindrome b;
    // Normal add
    REQUIRE(b.add("noon"));
    REQUIRE(b.add("soon"));
    REQUIRE(b.add("noos"));
    REQUIRE(b.add("non"));
    b.clear();

    // Add with non-conforming strings
    REQUIRE(!b.add("test1"));
    REQUIRE(!b.add("te st"));
    REQUIRE(!b.add(" test"));
    REQUIRE(!b.add("test "));
    REQUIRE(!b.add("1234"));
    REQUIRE(!b.add("@#!AZDX"));
    b.clear();

    // Add with pre-existing words
    REQUIRE(b.add("noon"));
    REQUIRE(!b.add("noon"));
}

TEST_CASE("Test add(vector) method", "[FindPalindrome]") {
    FindPalindrome b;

    // Normal add
    std::vector<std::string> test1;
    test1.push_back("noon");
    test1.push_back("soon");
    test1.push_back("noos");
    test1.push_back("non");
    REQUIRE(b.add(test1));
    b.clear();

    // Add with non-conforming strings
    std::vector<std::string> test2;
    test2.push_back("test1");
    test2.push_back("te st");
    test2.push_back(" test");
    test2.push_back("test ");
    test2.push_back("1234");
    test2.push_back("@#!AZDX");
    REQUIRE(!b.add(test2));
    b.clear();

    // Add with pre-existing words
    std::vector<std::string> test3;
    test3.push_back("noon");
    test3.push_back("noon");
    REQUIRE(!b.add(test3));
}

TEST_CASE("Test cutTest1 method", "[FindPalindrome]") {
    FindPalindrome b;

    // Passing vector
    std::vector<std::string> test1;
    test1.push_back("noon");
    test1.push_back("soon");
    test1.push_back("noos");
    test1.push_back("non");
    REQUIRE(b.cutTest1(test1));

    // Failing vector
    std::vector<std::string> test2;
    test2.push_back("abc");
    test2.push_back("def");
    test2.push_back("ghi");
    test2.push_back("jklmnop");
    REQUIRE(!b.cutTest1(test2));
}

TEST_CASE("Test cutTest2 method", "[FindPalindrome]") {
    FindPalindrome b;

    // Passing vector
    std::vector<std::string> test1Full;
    std::vector<std::string> test1Partial;
    test1Full.push_back("noon");
    test1Full.push_back("soon");
    test1Full.push_back("noos");
    test1Full.push_back("non");
    test1Partial.push_back("non");
    REQUIRE(b.cutTest2(test1Full, test1Partial));

    // Failing vector
    std::vector<std::string> test2Full;
    std::vector<std::string> test2Partial;
    test2Full.push_back("abc");
    test2Full.push_back("def");
    test2Full.push_back("ghi");
    test2Full.push_back("jklmnop");
    test2Partial.push_back("qrs");
    REQUIRE(b.cutTest2(test2Full, test2Partial));
}

TEST_CASE("Test toVector method", "[FindPalindrome]") {
    FindPalindrome b;

    REQUIRE(b.add("noon"));
    // 1: noon
    REQUIRE(b.toVector().size() == 1);
    REQUIRE(b.add("soon"));
    // None
    REQUIRE(b.toVector().size() == 0);
    REQUIRE(b.add("noos"));
    // 2: soonnoonnoos, noosnoonsoon
    REQUIRE(b.toVector().size() == 2);

    b.clear();
    REQUIRE(b.toVector().size() == 0);
}
