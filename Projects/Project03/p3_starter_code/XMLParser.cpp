// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
    // Initialize class variables
    elementNameBag = new Bag<std::string>();
    parseStack = new Stack<std::string>();
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
    // Clear XMLParser variables and free memory
    XMLParser::clear();
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
    // Ensure the class has been cleared
    XMLParser::clear();

    // Iterate through the entire input string, character by character
    for (std::size_t i = 0; i < inputString.size(); i++) {
        // Check for start of element
        if (inputString.at(i) == '<') {
            // Check for declaration
            if (inputString.at(i+1) == '?') {
                // Is a declaration
                // Tracks length of the token
                std::size_t j = i+1;
                // Get index of string at end of token
                while ((j < inputString.size()) && (inputString.at(j) != '>')) {
                    // Ensure there is not a nested token
                    if (inputString.at(j) == '<') {
                        // Invalid string
                        // Erase vector
                        tokenizedInputVector.clear();
                        // Return with failure
                        return false;
                    }
                    // Increment rolling index
                    j++;
                }

                // Ensure we found a valid end
                if ((inputString.at(j) != '>') || (inputString.at(j-1) != '?')) {
                    // Invalid string
                    // Erase vector
                    tokenizedInputVector.clear();
                    // Return with failure
                    return false;
                }

                // Get sub-string containing token
                std::size_t tokenLength = (j-2) - (i+2) + 1;
                std::string tokenString = inputString.substr(i+1, tokenLength);

                // Create declaration token
                TokenStruct token;
                token.tokenType = DECLARATION;
                token.tokenString = tokenString;

                // Push token onto vector
                tokenizedInputVector.push_back(token);

                // Handled tag, increment i to end of tag
                i = j;
            } else if (inputString.at(i+1) == '/') {
                // End-tag
                // Tracks length of token
                std::size_t j = i+1;
                // Find end of tag
                while ((j < inputString.size()) && (inputString.at(j) != '>')) {
                    // Ensure there is not a nested token
                    if (inputString.at(j) == '<') {
                        // Invalid string
                        // Erase vector
                        tokenizedInputVector.clear();
                        // Return with failure
                        return false;
                    }
                    // Increment rolling index
                    j++;
                }

                // Ensure we found a valid end
                if (inputString.at(j) != '>') {
                    // Invalid string
                    // Erase vector
                    tokenizedInputVector.clear();
                    // Return with failure
                    return false;
                }

                // Get sub-string containing token
                std::size_t tokenLength = (j-1) - (i+2) + 1;
                std::string tokenString = inputString.substr(i+1, tokenLength);

                // Create end-tag token
                TokenStruct token;
                token.tokenType = END_TAG;
                token.tokenString = tokenString;

                // Push token onto vector
                tokenizedInputVector.push_back(token);

                // Handled tag, increment i to end of tag
                i = j;
            } else {
                // Must be start or empty tag, check which it is
                // Tracks length of token
                std::size_t j = i+1;
                // Tracks type of token
                StringTokenType tokenType;
                // Check for how this tag ends
                while (j < inputString.size()) {
                    // Ensure there is not a nested token
                    if (inputString.at(j) == '<') {
                        // Invalid string
                        // Erase vector
                        tokenizedInputVector.clear();
                        // Return with failure
                        return false;
                    }
                    // Check for end of tag
                    if (inputString.at(j) == '>') {
                        // Check for empty tag
                        if (inputString.at(j-1) == '/') {
                            // Empty tag
                            tokenType = EMPTY_TAG;
                        } else {
                            // Start tag
                            tokenType = START_TAG;
                        }
                        // Exit loop
                        break;
                    }
                    j++;
                }

                // Ensure we found a valid end
                if (inputString.at(j) != '>') {
                    // Invalid string
                    // Erase vector
                    tokenizedInputVector.clear();
                    // Return with failure
                    return false;
                }

                // Get size of token
                std::size_t tokenLength = (j-1) - (i+1) + 1;
                // Decrement by 1 if empty tag to exclude '/' at end of string
                if (tokenType == EMPTY_TAG) {
                    tokenLength -= 1;
                }

                // Get sub-string containing token
                std::string tokenString = inputString.substr(i+1, tokenLength);

                // Create end-tag token
                TokenStruct token;
                token.tokenType = tokenType;
                token.tokenString = tokenString;

                // Push token onto vector
                tokenizedInputVector.push_back(token);

                // Handled tag, increment i to end of tag
                i = j;
            }
        } else {
            // Must be content
            // Tracks length of content
            std::size_t j = i+1;
            // Find end of content
            while (j < inputString.size()) {
                // Ensure there is not an invalid token end
                if (inputString.at(j) == '>') {
                    // Invalid string
                    // Erase vector
                    tokenizedInputVector.clear();
                    // Return with failure
                    return false;
                }
                // Check for start of token
                if (inputString.at(j) == '<') {
                    // j is start of new element
                    // Decrement j so its the index of the last character in content
                    j--;
                    // Exit loop
                    break;
                }
                // Increment j
                j++;
            }

            // Content can only exist between two elements / tokens
            // Ensure we found a valid end
            if (inputString.at(j+1) != '<') {
                // Invalid string
                // Erase vector
                tokenizedInputVector.clear();
                // Return with failure
                return false;
            }

            // Get sub-string containing token
            std::size_t tokenLength = (j) - (i) + 1;
            std::string tokenString = inputString.substr(i, tokenLength);

            // Create content token
            TokenStruct token;
            token.tokenType = CONTENT;
            token.tokenString = tokenString;

            // Push token onto vector
            tokenizedInputVector.push_back(token);

            // Handled tag, increment i to end of content
            i = j;
        }
    }

    // Exit with success
    return true;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
/**
 * @brief Creates a string with just the name of the element without attributes
 *
 * @param input String with / without attributes to remove
 * @return std::string String without attributes
 */
static std::string deleteAttributes(std::string input) const
{
    // Find index of last valid character in string
    for (std::size_t i = 0; i < input.size(); i++) {
        // Check if we are at the end of the name
        if (input.at(i) == ' ') {
            // Return name only
            return input.substr(0, i);
        }
    }
    // No (valid) attributes exist, return entire input
    return input;
}

/**
 * @brief Method to check if a tag name string is valid
 *
 * @param name String to check
 * @return true Name is valid
 * @return false Name is not valid
 */
static bool isValidName(std::string name) const {
    // Vector containing all invalid characters in tag names
    // Invalid characters: !"#$%&'()*+,/;<=>?@[\]^`{|}~
    std::vector<char> invalidTagNames{'!','\"','#','$','%','&','\'','(',')','*','+',',','/',';','<','=','>','?','@','[','\\',']','^','`','{','|','}','~'};
    // Vector containing all invalid first characters in tag names
    // Invalid characters: -.0123456789
    std::vector<char> invalidTagNamesFirstCharacter{'-','.','0','1','2','3','4','5','6','7','8','9'};

    // Ensure invalid characters don't exist in the string
    for (std::size_t i = 0; i < invalidTagNames.size(); i++) {
        char invalidChar = invalidTagNames.at(i);
        // Check each character in string against invalid character
        for (std::size_t j = 0; j < name.size(); j++) {
            if (name.at(j) == invalidChar) {
                // String contains invalid character(s)
                return false;
            }
        }
    }

    // Ensure first character doesn't contain an invalid first character
    for (std::size_t i = 0; i < invalidTagNamesFirstCharacter.size(); i++) {
        if (name.at(0) == invalidTagNamesFirstCharacter.at(i)) {
            // Name contains invalid first letter
            return false;
        }
    }

    // Name is valid
    return true;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
    // Ensure tokenized data exists
    if (tokenizedInputVector.size() < 1) {
        // Not a valid xml document because it's not an xml document
        return false;
    }

    // Quickly check if the document looks roughly valid
    // Check if document begins with a declaration tag
    if (tokenizedInputVector.at(0).tokenType == DECLARATION) {
        // Check if document is just an empty tag
        if (tokenizedInputVector.at(1).tokenType == EMPTY_TAG) {
            // Check if document only has the empty tag
            if (tokenizedInputVector.size() > 2) {
                // Not valid XML
                return false;
            }
        } else {
            // Check if document begins with a valid start tag
            if (tokenizedInputVector.at(1).tokenType != START_TAG) {
                // Not valid XML
                return false;
            }
            // Check if the document ends with a valid end tag
            if (tokenizedInputVector.back().tokenType != END_TAG) {
                // Not valid XML
                return false;
            }
        }
    } else {
        // Check if document is just an empty tag
        if (tokenizedInputVector.at(0).tokenType == EMPTY_TAG) {
            // Check if document only has the empty tag
            if (tokenizedInputVector.size() > 1) {
                // Not valid XML
                return false;
            }
        } else {
            // Check if document begins with a valid start tag
            if (tokenizedInputVector.at(0).tokenType != START_TAG) {
                // Not valid XML
                return false;
            }
            // Check if the document ends with a valid end tag
            if (tokenizedInputVector.back().tokenType != END_TAG) {
                // Not valid XML
                return false;
            }
        }
    }

    // Clear parse stack
    parseStack.clear();

    // Iterate through elements
    for (std::size_t i = 0; i < tokenizedInputVector.size(); i++) {
        // Check for start tag
        if (tokenizedInputVector.at(i).tokenType == START_TAG) {
            // Get name of tag
            std::string name = deleteAttributes(tokenizedInputVector.at(i).tokenString);
            // Ensure name is valid
            if (!isValidName(name)) {
                // Name not valid, xml not valid
                return false;
            }
            // Add to stack
            parseStack->push(name);
            // Add to bag
            elementNameBag->add(name);
        }
        // Check for end tag
        if (tokenizedInputVector.at(i).tokenType == END_TAG) {
            // Ensure last item in stack has the same name
            // Get name of tag
            std::string name = deleteAttributes(tokenizedInputVector.at(i).tokenString);
            // Ensure name is valid
            if (!isValidName(name)) {
                // Name not valid, xml not valid
                return false;
            }
            // Check if last tag in stack is start node
            if (parseStack->peek() == name) {
                // Valid XML, remove element from stack
                parseStack.pop();
            } else {
                // Invalid XML, clear stack and exit
                parseStack.clear();
                return false;
            }
        }
        // Check for empty tag
        if (tokenizedInputVector.at(i).tokenType == EMPTY_TAG) {
            // Get name of tag
            std::string name = deleteAttributes(tokenizedInputVector.at(i).tokenString);
            // Ensure name is valid
            if (!isValidName(name)) {
                // Name not valid, xml not valid
                return false;
            }
            // Add name to bag
            elementNameBag.add(name);
        }
    }

    // Ensure stack is empty (evert start element has end element)
    if (!parseStack->isEmpty()) {
        // Invalid XML
        return false;
    }

    // XML document is valid
    return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
    // Clear all data structures
    elementNameBag->clear();
    parseStack->clear();
    tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
    return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
    // Check if elementNameBag contains the string
    return elementNameBag->contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
    // Check elementNameBag for frequency of string
    return elementNameBag->getFrequencyOf(inputString);
}

