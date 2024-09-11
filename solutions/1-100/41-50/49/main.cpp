#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    std::set<int64_t> primes = generateSetOfPrimesUnderN(10000);
    std::string sequenceToFind;

    for (int i = 1; i < 5000; i++) {
        for (auto &prime: primes) {
            int64_t nextNum = prime + i;
            if (primes.contains(nextNum) && areNumbersPermutations(prime, nextNum)) {
                int64_t secondNum = prime + 2 * i;
                if (primes.contains(secondNum) && areNumbersPermutations(secondNum, nextNum)) {
                    if (i != 3330 || prime != 1487) {
                        sequenceToFind = std::to_string(prime) + std::to_string(nextNum) +
                                         std::to_string(secondNum);
                        goto endOfSearch;
                    }
                }
            }
        }
    }

    endOfSearch:
    std::cout << "Sequence to find: " << sequenceToFind << std::endl;


    return 0;
}
