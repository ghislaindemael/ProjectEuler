#include <iostream>

#include "41.h"

int main() {

    int limit = 10000000;
    auto result = getLargestPandigitalPrimeUsingSegmentedSieve(limit);

    std::cout << "Largest pandigitial prime: " << result << std::endl;

    return 0;
}
