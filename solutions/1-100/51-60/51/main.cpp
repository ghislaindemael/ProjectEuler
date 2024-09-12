#include <algorithm>
#include <functional>
#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"


int main() {
    const std::string fileName = "primes1000000.txt";
    const std::set<std::string> primesSet = parsePrimeSetFromFile(fileName);
    const std::vector<std::string> primesVector = parsePrimeVectorFromFile(fileName);
    const std::vector digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    std::string smallestSpecial8Prime;
    std::vector<std::vector<std::vector<int> > > combinations = precomputeCombinationVectorsForOneToN(6);

    for (const auto &prime: primesVector) {
        for (const auto &positions: combinations[prime.size() - 1]) {
            std::vector<std::string> results;
            for (char digit: digits) {
                std::string newPrime = prime;
                for (int pos: positions) {
                    newPrime[pos] = digit;
                }
                if (primesSet.contains(newPrime)) {
                    results.push_back(newPrime);
                }
            }

            if (results.size() >= 8) {
                smallestSpecial8Prime = results[0];
                goto endOfSearch;
            }
        }
    }

endOfSearch:

    std::cout << "First \"special-8\" prime: " << smallestSpecial8Prime << std::endl;

    return 0;
}
