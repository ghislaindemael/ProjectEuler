//
// Created by ghisl on 08/09/2024.
//

#ifndef LISTSGENERATION_H
#define LISTSGENERATION_H
#include <functional>
#include <set>
#include <string>
#include <vector>

std::vector<std::vector<int> > generateCombinations(int n, int k);

std::vector<std::vector<std::vector<int> > > precomputeCombinationVectorsForOneToN(int maxSize);

std::set<int64_t> generateSetOfNFirstTriangularNumbers(int n);

std::set<int64_t> generateSetOfNFirstPentagonalNumbers(int n);

std::set<int64_t> generateSetOfNFirstHexagonalNumbers(int n);

std::set<int64_t> generateSetOfPrimesUnderN(int limit);

std::set<int64_t> generatePrimeIntSetUsingSegmentedSieve(int limit);

std::set<std::string> generateStringSetOfPrimesUnderN(int limit);

std::set<std::string> genTriangularNumbersStringSetBetween(int lower, int upper);

std::set<std::string> genSquareNumbersStringSetOfBetween(int lower, int upper);

std::set<std::string> genPentagonalNumbersStringSetBetween(int lower, int upper);

std::set<std::string> genHexagonalNumbersStringSetBetween(int lower, int upper);

std::set<std::string> genHeptagonalNumbersStringSetBetween(int lower, int upper);

std::set<std::string> genOctagonalNumbersStringSetBetween(int lower, int upper);

#endif //LISTSGENERATION_H
