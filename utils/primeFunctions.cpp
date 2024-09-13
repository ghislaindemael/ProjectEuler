//
// Created by ghisl on 08/09/2024.
//

#include "primeFunctions.h"

std::vector<int> simple_sieve(int limit) {
    std::vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}


void segmented_sieve(int limit) {

    //TODO: Initialize value to track

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
                //TODO: Use the prime
            }
        }

        low += sqrt_limit;
        high += sqrt_limit;
    }

    //TODO: Return value
}