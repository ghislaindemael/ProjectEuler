#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/primeFunctions.h"
#include "utils/stringOperations.h"


int main() {

    int primeSum = 0;
    int sum = 1;
    int size = 1;
    double ratio = 1.0;

    while (ratio > 0.1) {
        size += 2;
        sum += 4;
        int64_t sizesqrd = size * size;
        primeSum += isPrime(sizesqrd - size + 1);
        primeSum += isPrime(sizesqrd - 2 * size + 2);
        primeSum += isPrime(sizesqrd - 3 * size + 3);

        ratio = primeSum * 1.0 / sum;
        //std::cout << size << ": " << primeSum << "/" << sum << " = " << ratio << std::endl;
    }

    std::cout << "First size where ratio < 10%: " << size << std::endl;

    return EXIT_SUCCESS;
}
