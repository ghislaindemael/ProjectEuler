//
// Created by ghisl on 08/09/2024.
//

#ifndef LISTSGENERATION_H
#define LISTSGENERATION_H
#include <functional>
#include <set>
#include <vector>

std::vector<std::vector<int> > generateCombinations(int n, int k);

std::vector<std::vector<std::vector<int>>> precomputeCombinationVectorsForOneToN(int maxSize);

std::set<int64_t> generateSetOfNFirstTriangularNumbers(int n);

std::set<int64_t> generateSetOfNFirstPentagonalNumbers(int n);

std::set<int64_t> generateSetOfNFirstHexagonalNumbers(int n);

std::set<int64_t> generateSetOfPrimesUnderN(int limit);

#endif //LISTSGENERATION_H
