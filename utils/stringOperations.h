//
// Created by ghisl on 08/09/2024.
//

#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H
#include <set>
#include <string>
#include <unordered_map>

std::vector<char> getDigitsCharVector(const std::string& number);

int getSumOfDigits(const std::string& str);

bool isStringPalindrome(const std::string&);

bool areNumbersPermutations(int, int);

bool areStringsPermutations(const std::string& s1, const std::string& s2);

int getSumOfAlphabeticalIndexes(const std::string& str);

bool isPandigitalFromOneToSize(const std::string& str);

bool isUniquelyPandigital(const std::string& input);


#endif //STRINGOPERATIONS_H
