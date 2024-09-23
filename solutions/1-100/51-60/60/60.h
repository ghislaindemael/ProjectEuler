//
// Created by ghisl on 23/09/2024.
//

#ifndef INC_60_H
#define INC_60_H
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "utils/primeFunctions.h"

void processValidCombination(const std::vector<std::string>& combination, int& smallestSum);

bool checkConcatenations(const std::vector<std::string>& combination, const std::set<std::string>& primes);

void generateCombinations(const std::vector<std::string>& elements, const std::set<std::string>& primes, int k,
                          int& smallestSum);

#endif //INC_60_H
