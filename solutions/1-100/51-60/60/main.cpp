#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <climits>
#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils/listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/primeFunctions.h"
#include "utils/stringOperations.h"

#include "60.h"

int main() {
    std::set<std::string> primeNumbers = generateStringSetOfPrimesUnderN(10000);
    std::vector<std::string> setElements(primeNumbers.begin(), primeNumbers.end());
    int smallestSum = INT_MAX;
    generateCombinations(setElements, primeNumbers, 5, smallestSum);

    std::cout << "Smallest sum: " << smallestSum << std::endl;

    return EXIT_SUCCESS;
}
