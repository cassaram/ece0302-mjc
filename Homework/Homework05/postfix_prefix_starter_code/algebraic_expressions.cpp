#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {
    // Get last character of postfix
    char ch = postfix.at(postfix.size() - 1 );

    // Ensure last character is an operator
    if (!isoperator(ch)) {
        // Not an operator, return
        return;
    }

    // Copy operator to prefix
    prefix.push_back(ch);

    // Copy rest of string to prefix
    for (std::size_t i = 0; i < postfix.size(); i++) {
        // Get character
        ch = postfix.at(i);

        // Skip operators
        if (!isoperator(ch)) {
            // Copy character to prefix
            prefix.push_back(ch);
        }
    }
}
