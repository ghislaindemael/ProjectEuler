#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    std::set<int64_t> numberPrimes = generateSetOfNFirstPrimes(5000);

    int firstInvalidNumber = 0;

    for (int i = 35; i < 10000; i += 2) {
        if (!numberPrimes.contains(i)) {
            bool valid = false;
            for (auto &prime: numberPrimes) {
                int64_t diff = i - prime;
                if (diff % 2 == 0) {
                    diff /= 2;
                    int64_t sr = sqrt(diff);
                    if (sr * sr == diff) {
                        valid = true;
                        break;
                    }
                }
            }
            if (!valid) {
                firstInvalidNumber = i;
                break;
            }
        }
    }

    std::cout << "First exception to conjecture: " << firstInvalidNumber << std::endl;

    return 0;
}
