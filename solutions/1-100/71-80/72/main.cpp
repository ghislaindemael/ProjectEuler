#include <iostream>
#include <unordered_set>
#include <numeric> // For std::gcd
#include <utility> // For std::pair
#include <vector>
#include <thread>
#include <mutex>

#include "utils/fileParsing.h"

int64_t countReducedProperFractions(const int limit) {
    std::vector<int> phi(limit + 1, 0);
    int64_t count = 0;

    for (int i = 1; i <= limit; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= limit; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= limit; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
        count += phi[i];
    }

    return count;
}

int main() {
    constexpr int limit = 1000000;
    std::cout << "Number of unique fractions: " << countReducedProperFractions(limit) << std::endl;
    return 0;
}
