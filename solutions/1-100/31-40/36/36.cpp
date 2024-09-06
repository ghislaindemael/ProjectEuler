//
// Created by ghisl on 06/09/2024.
//

#include "36.h"

bool isPalindrome(std::string input) {
    while (input.at(0) == '0') {
        input.erase(0, 1);
    }
    std::string reversed;
    reversed.resize(input.size());

    for(int i = 0; i < input.size(); i++) {
        reversed[i] = input[input.size() - 1 - i];
    }

    return reversed == input;
}