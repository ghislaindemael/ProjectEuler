//
// Created by ghisl on 06/09/2024.
//

#include "32.h"

bool containsOnlyOnceAllDigits(const std::string& input) {
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

bool haveCommonDigits(const std::string& stra, const std::string& strb) {
    for(char a : stra) {
        for (char b : strb) {
            if(a==b) {
                return true;
            }
        }
    }
    return false;
}