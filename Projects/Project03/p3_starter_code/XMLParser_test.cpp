#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

/*
 * Bag Class Tests
*/
TEST_CASE( "Test Bag add", "[XMLParser]" )
{
       INFO("Hint: testing Bag add()");
        // Create a Bag to hold ints
        Bag<int> intBag;
        int testSize = 2;
        int bagSize;
        bool success;
        for (int i=0; i<testSize; i++) {
            success = intBag.add(i);
            REQUIRE(success);
            bagSize = intBag.size();
            success = (bagSize == (i+1));
            REQUIRE(success);
        }
}

/*
 * Stack Class Tests
*/
TEST_CASE( "Test Stack push", "[XMLParser]" )
{
    INFO("Hint: testing Stack push()");
    // Create a Stack to hold ints
    Stack<int> intStack;
    int testSize = 3;
    int stackSize;
    bool success;
    for (int i=0; i<testSize; i++) {
        success = intStack.push(i);
        REQUIRE(success);
        stackSize = intStack.size();
        success = (stackSize == (i+1));
        REQUIRE(success);
    }
}

TEST_CASE("Test Stack Size", "[XMLParser]") {
    Stack<int> s;
    REQUIRE(s.size() == 0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    REQUIRE(s.size() == 4);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    REQUIRE(s.size() == 0);
}

TEST_CASE("Test Stack isEmpty", "[XMLParser]") {
    Stack<int> s;
    REQUIRE(s.isEmpty());
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    REQUIRE(!s.isEmpty());
    for (int i = 10; i > 0; i--) {
        s.pop();
    }
    REQUIRE(s.isEmpty());
}

TEST_CASE("Test Stack pop", "[XMLParser]") {
    Stack<int> s;
    REQUIRE(s.isEmpty());
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    REQUIRE(!s.isEmpty());
    for (int i = 10; i > 0; i--) {
        REQUIRE(s.pop());
    }
    REQUIRE(s.isEmpty());
}

TEST_CASE("Test Stack peek", "[XMLParser]") {
    Stack<int> s;
    REQUIRE(s.isEmpty());
    for (int i = 0; i < 10; i++) {
        REQUIRE(s.push(i));
        REQUIRE(s.peek() == i);
    }
    REQUIRE(!s.isEmpty());
    for (int i = 9; i >= 0; i--) {
        REQUIRE(s.peek() == i);
        REQUIRE(s.pop());
    }
    REQUIRE(s.isEmpty());
}

TEST_CASE("Test Stack clear", "[XMLParser]") {
    Stack<int> s;
    REQUIRE(s.isEmpty());
    for (int i = 0; i < 10; i++) {
        REQUIRE(s.push(i));
        REQUIRE(s.peek() == i);
    }
    REQUIRE(!s.isEmpty());
    REQUIRE(s.size() != 0);
    s.clear();
    REQUIRE(s.isEmpty());
    REQUIRE(s.size() == 0);
}

/*
 * XMLParser Class Tests
*/
TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
    // Create an instance of XMLParse
    XMLParser myXMLParser;
    // Test valid xml
    string testString1 = "<test>stuff</test>";
    bool success1;
    success1 = myXMLParser.tokenizeInputString(testString1);
    REQUIRE(success1);
    // Test tag-invalid xml
    string testString2 = "<test<test2>>stuff</test>";
    bool success2;
    success2 = myXMLParser.tokenizeInputString(testString2);
    REQUIRE(!success2);
    // Test no-end invalid xml
    string testString3 = "<test>stuff</test";
    bool success3;
    success3 = myXMLParser.tokenizeInputString(testString3);
    REQUIRE(!success3);
    // Test too many ends invalid xml
    string testString4 = "<test>stuff</test>>";
    bool success4;
    success4 = myXMLParser.tokenizeInputString(testString4);
    REQUIRE(!success4);
}

TEST_CASE("Test XMLParser parseTokenizedInput", "[XMLParser]") {
    // Create an xmlParser
    XMLParser p;
    // Feed valid xml 1
    string testString1 = "<test>stuff</test>";
    bool success1;
    success1 = p.tokenizeInputString(testString1);
    REQUIRE(success1);
    // Test valid xml
    success1 = p.parseTokenizedInput();
    REQUIRE(success1);
    // Feed valid xml 2
    string testString2 = "<test>stuff<InnerTest/><InnerNode>Content of inner node</InnerNode></test>";
    bool success2;
    success2 = p.tokenizeInputString(testString2);
    REQUIRE(success2);
    // Test valid xml
    success2 = p.parseTokenizedInput();
    REQUIRE(success2);
    // Feed invalid xml by white space
    string testString3 = "<test not valid>stuff</test not valid>";
    bool success3;
    success3 = p.tokenizeInputString(testString3);
    REQUIRE(success3);
    // Test valid xml
    success3 = p.parseTokenizedInput();
    REQUIRE(!success3);
    // Feed invalid xml by no end node
    string testString4 = "<test>stuff";
    bool success4;
    success4 = p.tokenizeInputString(testString4);
    REQUIRE(!success4);
}

TEST_CASE( "Test Stack handout-0", "[XMLParser]" )
{
    // Create a Stack to hold ints
    Stack<int> intStack;
    int testSize = 10;
    int stackSize;
    bool success = false;
    for (int i=0; i<testSize; i++) {
        intStack.push(i);
        stackSize = intStack.size();
        success = (stackSize == (i+1));
        REQUIRE(success);
    }
    for (int i = testSize-1; i>=0; i--) {
        REQUIRE(intStack.isEmpty() == false);
        int elem = intStack.peek();
        REQUIRE(elem == i);
        REQUIRE(intStack.isEmpty() == false);
        intStack.pop();
    }
    REQUIRE(intStack.isEmpty() == true);
}

TEST_CASE( "Test Stack handout-1", "[XMLParser]" )
{
    Stack<char> charStack;
    std::string s("Hello world");
    int i = 1;
    for (auto c:s) {
        charStack.push(c);
        REQUIRE(charStack.size() == i);
        i++;
    }
    for (i = 0; i < 5; i++) {
        REQUIRE(charStack.isEmpty() == false);
        char c = charStack.peek();
        REQUIRE(c == s[s.length()-1-i]);
        REQUIRE(charStack.isEmpty() == false);
        charStack.pop();
    }
    REQUIRE(charStack.size() == 6);
    charStack.clear();
    REQUIRE(charStack.isEmpty() == true);
}

// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-0", "[XMLParser]" )
{
    INFO("Hint: tokenize single element test of XMLParse");
    // Create an instance of XMLParse
    XMLParser myXMLParser;
    string testString = "<test>stuff</test>";
    bool success;
    success = myXMLParser.tokenizeInputString(testString);
    REQUIRE(success);
    std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
                                        TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
                                        TokenStruct{StringTokenType::END_TAG, std::string("test")}};
    std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
    REQUIRE(result.size() == output.size());
    for (int i = 0; i < result.size(); i++) {
        REQUIRE(result[i].tokenType == output[i].tokenType);
        REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
    }
}


// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-1", "[XMLParser]" )
{
    INFO("Hint: tokenize multiple elements test of XMLParse");
    // Create an instance of XMLParse
    XMLParser myXMLParser;
    string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
    bool success;
    success = myXMLParser.tokenizeInputString(testString);
    REQUIRE(success);
    std::vector<TokenStruct> result = { TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
                                TokenStruct{StringTokenType::START_TAG, std::string("Note")},
                                TokenStruct{StringTokenType::START_TAG, std::string("From")},
                                TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
                                TokenStruct{StringTokenType::END_TAG, std::string("From")},
                                TokenStruct{StringTokenType::START_TAG, std::string("To")},
                                TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
                                TokenStruct{StringTokenType::END_TAG, std::string("To")},
                                TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
    std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
    REQUIRE(result.size() == output.size());
    for (int i = 0; i < result.size(); i++) {
        REQUIRE(result[i].tokenType == output[i].tokenType);
        REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
    }
}

TEST_CASE( "Test XMLParser parseTokenizedInput Handout-0", "[XMLParser]" )
{
    INFO("Hint: tokenize single element test of XMLParse");
    // Create an instance of XMLParse
    XMLParser myXMLParser;
    string testString = "<test myattr='abcdef'>stuff<this_is_empty_tag/></test>";
    bool success;
    success = myXMLParser.tokenizeInputString(testString);
    REQUIRE(success);
    std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
                                        TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
                                        TokenStruct{StringTokenType::EMPTY_TAG, std::string("this_is_empty_tag")},
                                        TokenStruct{StringTokenType::END_TAG, std::string("test")}};
    std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
    REQUIRE(result.size() == output.size());
    success = myXMLParser.parseTokenizedInput();
    REQUIRE(success);
    output = myXMLParser.returnTokenizedInput();
    REQUIRE(result.size() == output.size());
    for (int i = 0; i < result.size(); i++) {
        REQUIRE(result[i].tokenType == output[i].tokenType);
        REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
    }
}

TEST_CASE( "Test XMLParser Final Handout-0", "[XMLParser]" )
{
    INFO("Hint: Product");
    // Create an instance of XMLParse
    XMLParser myXMLParser;
    ifstream myfile ("./TestFile.txt");
    std::string inputString((std::istreambuf_iterator<char>(myfile) ), (std::istreambuf_iterator<char>()) );

    bool success;
    success = myXMLParser.tokenizeInputString(inputString);
    REQUIRE(success);
    success = myXMLParser.parseTokenizedInput();
    REQUIRE(success);
    REQUIRE(myXMLParser.containsElementName("catalog"));
    REQUIRE(myXMLParser.frequencyElementName("catalog") == 1);
    REQUIRE(myXMLParser.containsElementName("product"));
    REQUIRE(myXMLParser.frequencyElementName("product") == 1);
    REQUIRE(myXMLParser.containsElementName("catalog_item"));
    REQUIRE(myXMLParser.frequencyElementName("catalog_item") == 2);
    REQUIRE(myXMLParser.containsElementName("item_number"));
    REQUIRE(myXMLParser.frequencyElementName("item_number") == 2);
    REQUIRE(myXMLParser.containsElementName("size"));
    REQUIRE(myXMLParser.frequencyElementName("size") == 6);
    REQUIRE(myXMLParser.containsElementName("color_swatch"));
    REQUIRE(myXMLParser.frequencyElementName("color_swatch") == 15);
}

TEST_CASE("Test XMLParser returnTokenizedInput", "[XMLParser]") {
    XMLParser p;
    std::string testString = "<TestCase>Test Case Project<TestNode Attrib=\"1\"/><NextNode></NextNode></TestCase>";
    REQUIRE(p.tokenizeInputString(testString));
    REQUIRE(p.parseTokenizedInput());

    std::vector<TokenStruct> referenceVector;
    TokenStruct a;
    a.tokenString = "TestCase";
    a.tokenType = START_TAG;
    referenceVector.push_back(a);
    TokenStruct b;
    b.tokenString = "Test Case Project";
    b.tokenType = CONTENT;
    referenceVector.push_back(b);
    TokenStruct c;
    c.tokenString = "TestNode";
    c.tokenType = EMPTY_TAG;
    referenceVector.push_back(c);
    TokenStruct d;
    d.tokenString = "NextNode";
    d.tokenType = START_TAG;
    referenceVector.push_back(d);
    TokenStruct e;
    e.tokenString = "NextNode";
    e.tokenType = END_TAG;
    referenceVector.push_back(e);
    TokenStruct f;
    f.tokenString = "TestCase";
    f.tokenType = END_TAG;
    referenceVector.push_back(f);

    std::vector<TokenStruct> parsedVector = p.returnTokenizedInput();

    REQUIRE(referenceVector.size() == parsedVector.size());
    for (std::size_t i = 0; i < referenceVector.size(); i++) {
        REQUIRE(referenceVector.at(i).tokenString == parsedVector.at(i).tokenString);
        REQUIRE(referenceVector.at(i).tokenType == parsedVector.at(i).tokenType);
    }
}

TEST_CASE("Test XMLParser containsElementName", "[XMLParser]") {
    XMLParser p;
    std::string testString = "<TestCase>Test Case Project<TestNode Attrib=\"1\"/><NextNode></NextNode></TestCase>";
    REQUIRE(p.tokenizeInputString(testString));
    REQUIRE(p.parseTokenizedInput());

    REQUIRE(p.containsElementName("TestCase"));
    REQUIRE(p.containsElementName("TestNode"));
    REQUIRE(p.containsElementName("NextNode"));
}

TEST_CASE("Test XMLParser frequencyElementName", "[XMLParser]") {
    XMLParser p;
    std::string testString = "<TestCase>Test Case Project<TestNode Attrib=\"1\"/><NextNode></NextNode><NextNode></NextNode></TestCase>";
    REQUIRE(p.tokenizeInputString(testString));
    REQUIRE(p.parseTokenizedInput());

    REQUIRE(p.frequencyElementName("TestCase") == 1);
    REQUIRE(p.frequencyElementName("TestNode") == 1);
    REQUIRE(p.frequencyElementName("NextNode") == 2);

    REQUIRE(p.frequencyElementName("NotReal") == 0);
}

TEST_CASE("Test XMLParser clear", "[XMLParser]") {
    XMLParser p;
    std::string testString = "<TestCase>Test Case Project<TestNode Attrib=\"1\"/><NextNode></NextNode></TestCase>";
    REQUIRE(p.tokenizeInputString(testString));
    REQUIRE(p.parseTokenizedInput());

    p.clear();
    REQUIRE(p.returnTokenizedInput().size() == 0);
}
