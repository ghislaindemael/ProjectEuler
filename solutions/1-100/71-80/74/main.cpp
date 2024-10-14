#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <thread>

#include <boost/multiprecision/cpp_int.hpp>

#include "utils/numberOperations.h"
#include "utils/stringOperations.h"

int main() {
    std::set<int64_t> magicNumbers {145, 169, 363601, 1454, 871, 45361, 45362, 872};

    int limit = 1000000;
    int arraySize = 2200000;
    int count60Terms = 0;

    std::vector<int64_t> sumOfDigitFactorials(arraySize, 0);

    for (int64_t i = 0; i < arraySize; i++) {
        std::vector<int64_t> digits = getDigitsVector(i);
        int64_t sum = 0;
        for (const auto& d : digits) {
            sum += factorial(d);
        }
        sumOfDigitFactorials[i] = sum;
    }

    for (int64_t i = 69; i < limit; i++) {
        if (i % 100000 == 0) {
            std::cout << "Processing: " << i << std::endl;
        }

        int64_t num = i;
        int numOfTerms = 0;
        std::set<int64_t> seenNumbers { i };  // To detect cycles

        while (numOfTerms <= 61) {
            int64_t sumOfDigitFactorial = sumOfDigitFactorials[num];
            if (seenNumbers.contains(sumOfDigitFactorial)) {
                break;
            }
            seenNumbers.insert(sumOfDigitFactorial);
            numOfTerms++;
            num = sumOfDigitFactorial;
        }

        if (numOfTerms == 60) {
            count60Terms++;
        }
    }

    std::cout << "Count of 60-terms before cycle: " << count60Terms << std::endl;

    return 0;
}