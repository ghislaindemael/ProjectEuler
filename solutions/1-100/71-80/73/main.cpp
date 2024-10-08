#include <iostream>
#include <unordered_set>
#include <numeric>
#include <utility>
#include <vector>
#include <thread>


int main() {
    int countOfFractions = 0;
    constexpr double oneThird = 0.333333334;
    constexpr double oneHalf = 0.5;

    for (int i = 2; i <= 12000; i++) {
        for (int j = std::ceil(i * 1.0 / 3); j < std::ceil(i * 1.0 / 2); j++) {
            double frac = j * 1.0 / i;
            if (std::gcd(i, j) == 1 && frac > oneThird && frac < oneHalf) {
                //std::cout << j << " " << i << " " << frac << std::endl;
                countOfFractions++;
            }
        }
    }

    std::cout << "Num of fractions between 1/3 and 1/2: " << countOfFractions << std::endl;

    return 0;
}
