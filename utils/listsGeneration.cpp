//
// Created by ghisl on 08/09/2024.
//

#include "listsGeneration.h"

#include <iostream>
#include <ostream>
#include <string>

#include "primeFunctions.h"


std::vector<std::vector<int>> generateCombinations(int n, int k) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> current;
    std::function<void(int, int)> generatePositionCombinations = [&](int start, int k) {
        if (current.size() == k) {
            combinations.push_back(current);
            return;
        }
        for (int i = start; i < n; ++i) {
            current.push_back(i);
            generatePositionCombinations(i + 1, k);
            current.pop_back();
        }
    };
    generatePositionCombinations(0, k);
    return combinations;
}

std::vector<std::vector<std::vector<int>>> precomputeCombinationVectorsForOneToN(int maxSize) {
    std::vector<std::vector<std::vector<int>>> combinations(maxSize);
    for (int n = 1; n <= maxSize; ++n) {
        for (int k = 1; k <= n; ++k) {
            std::vector<std::vector<int>> currentCombinations = generateCombinations(n, k);
            combinations[n - 1].insert(combinations[n - 1].end(), currentCombinations.begin(), currentCombinations.end());
        }
    }
    return combinations;
}

std::set<int64_t> generateSetOfNFirstTriangularNumbers(int limit) {
    std::set<int64_t> triangularNumbers;
    for(int64_t n = 1; n <= limit; n++) {
        triangularNumbers.insert((n*n + n) / 2);
    }
    return triangularNumbers;
}

std::set<int64_t> generateSetOfNFirstPentagonalNumbers(int limit) {
    std::set<int64_t> pentagonalNumbers;
    for(int64_t n = 1; n <= limit; n++) {
        pentagonalNumbers.insert((3*n*n - n) / 2);
    }
    return pentagonalNumbers;
}

std::set<int64_t> generateSetOfNFirstHexagonalNumbers(int limit) {
    std::set<int64_t> hexagonalNumbers;
    for(int64_t n = 1; n <= limit; n++) {
        hexagonalNumbers.insert(2*n*n - n);
    }
    return hexagonalNumbers;
}

std::set<int64_t> generateSetOfPrimesUnderN(int limit) {
    std::set<int64_t> primes;
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p <= sqrt(limit); ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.insert(p);
        }
    }

    return primes;
}

std::set<int64_t> generatePrimeIntSetUsingSegmentedSieve(int limit) {

    std::set<int64_t> primes {};

    int sqrt_limit = static_cast<int>(sqrt(limit)) + 1;
    std::vector<int> small_primes = simple_sieve(sqrt_limit);
    for(const int i : small_primes) {
        primes.insert(i);
    }

    int low = sqrt_limit;
    int high = 2 * sqrt_limit;
    while (low < limit) {
        if (high > limit) {
            high = limit;
        }

        std::vector<bool> sieve(high - low, true);
        for (int prime : small_primes) {
            int start = std::max(prime * prime, (low + prime - 1) / prime * prime);
            if (start < low) {
                start += prime;
            }
            for (int j = start; j < high; j += prime) {
                sieve[j - low] = false;
            }
        }

        for (int i = low; i < high; ++i) {
            if (sieve[i - low]) {
                primes.insert(i);
            }
        }

        low += sqrt_limit;
        high += sqrt_limit;
    }

    return primes;
}

std::set<std::string> generateStringSetOfPrimesUnderN(int limit) {
    std::set<std::string> primes;
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.insert(std::to_string(p));
        }
    }

    return primes;

}


