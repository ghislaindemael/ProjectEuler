//
// Created by ghisl on 08/09/2024.
//

#include "41.h"

std::string getLargestPandigitalPrimeUsingSegmentedSieve(int limit) {

    std::string biggestPandigitalPrime;

    int sqrt_limit = static_cast<int>(sqrt(limit)) + 1;
    std::vector<int> small_primes = simple_sieve(sqrt_limit);

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
                std::string num = std::to_string(i);
                if(isPandigitalFromOneToSize(num)) {
                    biggestPandigitalPrime = num;
                }
            }
        }

        low += sqrt_limit;
        high += sqrt_limit;
    }

    return biggestPandigitalPrime;
}