#include <iostream>

#include "43.h"
#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> primeDivisors {0, 2, 3, 5, 7, 11, 13, 17};
    int64_t sum = 0;

    genPermutationsAndAddToSumIfCheck(vec, primeDivisors, 0, 9, sum);

    std::cout << "Sum of pandigital numbers with property: " << sum << std::endl;

    return 0;
}
