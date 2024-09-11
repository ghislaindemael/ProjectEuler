#include <algorithm>
#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    auto primes = parsePrimeSetFromFile("primes1000000.txt");
    std::set<int> primesSet;
    std::vector<int> primesArray;
    for(auto& prime : primes) {
        int number = std::stoi(prime);
        primesArray.push_back(number);
        primesSet.insert(number);
    }
    std::sort(primesArray.begin(), primesArray.end());

    bool consecutiveFound = false;

    for(int consecutive = 1000; consecutive > 500; consecutive--) {
        for(int i = 0; i <= primesArray.size() - consecutive; i++) {
            int sum = 0;
            bool allConsec = true;
            for(int j = 0; j < consecutive; j++) {
                sum += primesArray[i + j];
                if(sum > 1000000) {
                    allConsec = false;
                    break;
                }
            }
            if(allConsec && primesSet.contains(sum)) {
                consecutiveFound = true;
                std::cout << sum << " is sum of " << consecutive << " consecutive primes." << std::endl;
            }
        }

        if(consecutiveFound) {
            break;
        }

    }

    return 0;
}
