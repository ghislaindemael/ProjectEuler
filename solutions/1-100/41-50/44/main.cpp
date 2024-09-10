#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {
    int smallestDiff = 100000000;

    auto pentagonalNumbers = generateSetOfNFirstPentagonalNumbers(10000);

    for (auto &a: pentagonalNumbers) {
        for (auto &b: pentagonalNumbers) {
            if (a != b) {
                int sum = a + b;
                int difference = a - b;
                if (pentagonalNumbers.contains(sum) && pentagonalNumbers.contains(difference)) {
                    std::cout << "a: " << a << " b: " << b << std::endl;
                    if (std::abs(difference) < smallestDiff) {
                        smallestDiff = std::abs(difference);
                    }
                }
            }
        }
    }

    std::cout << "Smallest difference: " << smallestDiff << std::endl;
}
