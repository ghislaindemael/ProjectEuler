#include <iostream>
#include <vector>
#include <utility>

#include "utils/stringOperations.h"

constexpr int MAX = 10000000;

int main() {
    std::vector<long int> phi(MAX + 1);

    for (int i = 0; i <= MAX; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= MAX; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    std::pair<int, double> smallestNnRatio {0, 10000.0};

    for (int i = 2; i <= MAX; ++i) {
        if(areStringsPermutations(std::to_string(i), std::to_string(phi[i]))) {
            if (double ratio = static_cast<double>(i) / phi[i]; ratio < smallestNnRatio.second) {
                std::cout << i << " " << phi[i] << " " << ratio << std::endl;
                smallestNnRatio = std::make_pair(i, ratio);
            }
        }
    }

    std::cout << "Smallest double: " << smallestNnRatio.second << " for n: " << smallestNnRatio.first << std::endl;

    return 0;
}
