#include <string>
#include <vector>
#include <iostream>
#include <locale>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
    locale loc;
    for (int i=0; i<value.size(); i++) {
        value[i] = tolower(value[i],loc);
    }
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
    // Lowest-level loop. currentStringVector is empty
    if (currentStringVector.size() == 0) {
        // String to use as a test case
        std::string candidateString;

        // Convert candidate palindrome to string
        for (std::size_t i = 0; i < candidateStringVector.size(); i++) {
            candidateString += candidateStringVector.at(i);
        }

        // Check if candidateString is a palindrome
        if (isPalindrome(candidateString)) {
            // String is a palindrome, add it to the list
            palindromesList.push_back(candidateStringVector);
        }

        // Exit current recursion level
        return;
    }

    // Ensure palindrome exists within current set
    if (!cutTest2(candidateStringVector, currentStringVector)) {
        // No palindromes exist
        // Exit current recursion level
        return;
    }

    // Palindrome(s) exist, start sub-recursive loop
    for (std::size_t i = 0; i < currentStringVector.size(); i++) {
        // Move first word from current to candidate
        candidateStringVector.push_back(currentStringVector.at(i));
        currentStringVector.erase(currentStringVector.begin() + i);

        // Find palindromes of current candidate
        recursiveFindPalindromes(candidateStringVector, currentStringVector);

        // Rebuild currentStringVector to how it was before this loop
        currentStringVector.insert(currentStringVector.begin(), candidateStringVector.back());

        // Rebuild candidateStringVector to how it was before this loop
        candidateStringVector.erase(candidateStringVector.end());
    }

    return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
    locale loc;
    // make sure that the string is lower case...
    convertToLowerCase(currentString);
    // see if the characters are symmetric...
    int stringLength = currentString.size();
    for (int i=0; i<stringLength/2; i++) {
        if (currentString[i] != currentString[stringLength - i - 1]) {
            return false;
        }
    }
    return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome() {}

FindPalindrome::~FindPalindrome()
{
    // Clear class vectors
    std::vector<std::string>().swap(wordList);
    std::vector<std::vector<std::string>>().swap(palindromesList);
}

int FindPalindrome::number() const
{
    return palindromesList.size();
}

void FindPalindrome::clear()
{
    // Reset class variables
    std::vector<std::string>().swap(wordList);
    std::vector<std::vector<std::string>>().swap(palindromesList);
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
    // Variable to store long character string as
    std::string charList = "";

    // Add all characters to character list
    for (std::size_t i = 0; i < stringVector.size(); i++) {
        std::string value = stringVector.at(i);
        convertToLowerCase(value);
        charList.append(value);
    }

    // Variables to track number of odd characters in the string
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::size_t oddChars = 0;

    // Loop through looking for odd character numbering
    for (std::size_t i = 0; i < alphabet.size(); i++) {
        // Count how many occurances this character has
        std::string testChar = alphabet.substr(i, i+1);
        std::size_t count = 0;
        for (std::size_t j = 0; j < charList.size(); j++) {
            if (charList.substr(j, j+1) == testChar) {
                count++;
            }
        }
        // Check of count is odd, if so increment the number of odd chars
        if (count % 2 != 0) {
            // is odd
            oddChars++;

            // Check if we already have more than 1 odd character
            if (oddChars > 1) {
                return false;
            }

            // Check if we have a string of even length
            if (charList.size() % 2 == 0) {
                return false;
            }
        }
    }

    // Return valid palindrome could exist
    return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
    // Check if either string list is empty
    if (stringVector1.size() == 0 || stringVector2.size() == 0) {
        return true;
    }

    // String character lists to insert all strings from word lists into
    std::string charList1;
    std::string charList2;

    // Copy stringVector1 to charList1
    for (std::size_t i = 0; i < stringVector1.size(); i++) {
        std::string value = stringVector1.at(i);
        convertToLowerCase(value);
        charList1 += value;
    }

    // Copy stringVector2 to charList2
    for (std::size_t i = 0; i < stringVector2.size(); i++) {
        std::string value = stringVector2.at(i);
        convertToLowerCase(value);
        charList2 += value;
    }

    // Determine which string is smaller
    if (charList1.size() >= charList2.size()) {
        // charList2 is smaller
        // Check if there are more of any character in charList2 than charList1
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (std::size_t i = 0; i < alphabet.size(); i++) {
            // Variables to track within loop
            std::string testChar = alphabet.substr(i, i+1);
            int tracker = 0;

            // Count all instances of the testChar in charList1
            for (std::size_t j = 0; j < charList1.size(); j++) {
                if (charList1.substr(j, j+1) == testChar) {
                    tracker++;
                }
            }

            // Count all instances of the testChar in charList2
            for (std::size_t j = 0; j < charList2.size(); j++) {
                if (charList2.substr(j, j+1) == testChar) {
                    tracker--;
                }
            }

            // Check if there are more instances in charList2 than charList1
            if (tracker < 0) {
                // Fails cut test
                return false;
            }
        }
    } else {
        // charList1 is smaller
        // Check if there are more of any character in charList2 than charList1
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (std::size_t i = 0; i < alphabet.size(); i++) {
            // Variables to track within loop
            std::string testChar = alphabet.substr(i, i+1);
            int tracker = 0;

            // Count all instances of the testChar in charList2
            for (std::size_t j = 0; j < charList2.size(); j++) {
                if (charList2.substr(j, j+1) == testChar) {
                    tracker++;
                }
            }

            // Count all instances of the testChar in charList1
            for (std::size_t j = 0; j < charList1.size(); j++) {
                if (charList1.substr(j, j+1) == testChar) {
                    tracker--;
                }
            }

            // Check if there are more instances in charList2 than charList1
            if (tracker < 0) {
                // Fails cut test
                return false;
            }
        }
    }

    // Test passes, return success
    return true;
}

bool FindPalindrome::add(const string & value)
{
    // Determine if word is made of allowed characters
    for (std::size_t i = 0; i < value.size(); i++) {
        if ((value[i] < 'a' || value [i] > 'z') && (value[i] < 'A' || value[i] > 'Z')) {
            // String contains characters outside allowable space
            return false;
        }
    }

    // Determine if word is already in wordList
    for (std::size_t i = 0; i < wordList.size(); i++) {
        // Create lower cased versions for comparison
        std::string testWordLower = wordList.at(i);
        std::string valueLower = value;
        convertToLowerCase(testWordLower);
        convertToLowerCase(valueLower);

        // Compare strings
        if (testWordLower == valueLower) {
            // String is already in wordList
            return false;
        }
    }

    // Add word to wordList
    wordList.push_back(value);

    // Recalculate palindromes
    // Clear palindromes list
    palindromesList.clear();
    // Check if a palindrome can exist from the current word list
    if (cutTest1(wordList)) {
        // Find palindromes from wordlist
        std::vector<std::string> candidates;
        recursiveFindPalindromes(candidates, wordList);
    }

    // Return success
    return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
    // Perform checks per word
    for (std::size_t i = 0; i < stringVector.size(); i++) {
        std::string value = stringVector.at(i);

        // Check if word is allowed
        for (std::size_t j = 0; j < value.size(); j++) {
            if ((value[j] < 'a' || value [j] > 'z') && (value[j] < 'A' || value[j] > 'Z')) {
                // String contains characters outside allowable space
                return false;
            }
        }

        // Check if word is in stringVector twice
        std::string valueLower = value;
        convertToLowerCase(valueLower);
        for (std::size_t j = 0; j < stringVector.size(); j++) {
            std::string wordLower = stringVector.at(j);
            convertToLowerCase(wordLower);
            if (i != j && valueLower == wordLower) {
                // String is in stringVector twice
                return false;
            }
        }

        // Check if word is already in wordList
        for (std::size_t j = 0; j < wordList.size(); j++) {
            std::string wordLower = wordList.at(j);
            convertToLowerCase(wordLower);
            if (valueLower == wordLower) {
                // String is already in wordlist
                return false;
            }
        }
    }

    // Checks passed, add words to wordList
    for (std::size_t i = 0; i < stringVector.size(); i++) {
        wordList.push_back(stringVector.at(i));
    }

    // Recalculate palindromes
    // Clear palindromes list
    palindromesList.clear();
    // Check if a palindrome can exist from the current word list
    if (cutTest1(wordList)) {
        // Find palindromes from wordlist
        std::vector<std::string> candidates;
        recursiveFindPalindromes(candidates, wordList);
    }

    // Return success
    return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
    return palindromesList;
}

