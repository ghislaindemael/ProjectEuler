//
// Created by ghisl on 08/09/2024.
//

#include "stringOperations.h"

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

