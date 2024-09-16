//
// Created by ghisl on 08/09/2024.
//

#include "stringOperations.h"

#include <algorithm>


bool isStringPalindrome(const std::string& str) {
    std::string reversed = str;
    std::ranges::reverse(reversed);
    return str == reversed;
}

bool areNumbersPermutations(int int1, int int2) {
    return areStringsPermutations(std::to_string(int1), std::to_string(int2));
}

bool areStringsPermutations(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    std::unordered_map<char, int> charCount;

    for (char c : s1) {
        charCount[c]++;
    }

    for (char c : s2) {
        if (!charCount.contains(c) || charCount[c] == 0) {
            return false;
        }
        charCount[c]--;
    }

    return true;
}

int getSumOfAlphabeticalIndexes(const std::string &str) {
    int sum = 0;
    for (char c : str) {
        if (std::isupper(c)) {
            sum += c - 'A' + 1;
        } else if (std::islower(c)) {
            sum += c - 'a' + 1;
        }
    }
    return sum;
}

bool isPandigitalFromOneToSize(const std::string &str) {
    int length = str.length();
    if (length < 1 || length > 9) {
        return false;
    }

    std::set<char> seenDigits;

    for (char c : str) {
        if (c < '1' || c > '0' + length) {
            return false;
        }
        if (seenDigits.contains(c)) {
            return false;
        }
        seenDigits.insert(c);
    }

    return seenDigits.size() == length;
}

bool isUniquelyPandigital(const std::string& input) {
    if (input.length() != 9) {
        return false;
    }

    std::set<char> seenDigits;

    for (char c : input) {
        if (c < '1' || c > '9') {
            return false;
        }
        if (seenDigits.contains(c)) {
            return false;
        }
        seenDigits.insert(c);
    }

    return true;
}

