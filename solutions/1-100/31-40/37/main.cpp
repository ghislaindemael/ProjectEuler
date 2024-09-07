#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "helperFunctions/fileParsing.h"

int main() {

    std::string filename = "primes1000000.txt";
    std::set<std::string> primes = parsePrimeSetFromFile(filename);

    std::set<std::string> doubleTruncatablePrimes {};

    for(auto& prime : primes) {
        bool truncatable = true;
        std::string fromLeft = prime;
        std::string fromRight = prime;
        while (fromLeft.length() > 1) {
            fromRight.pop_back();
            fromLeft.erase(0, 1);
            if(!primes.contains(fromLeft) || !primes.contains(fromRight)) {
                truncatable = false;
                break;
            }
        }
        if(truncatable) {
            if(prime.length() > 1) {
                doubleTruncatablePrimes.insert(prime);
            }
        }
    }

    int sumOfTruncatablePrimes { 0 };

    for(auto& p : doubleTruncatablePrimes) {
        sumOfTruncatablePrimes += std::stoi(p);
    }

    std::cout << "Sum of eleven double-truncatable primes: " << sumOfTruncatablePrimes << std::endl;

    return 0;
}
