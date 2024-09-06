#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "35.h"

int main() {

    std::string filename = "primes1000000.txt";
    std::set<std::string> primes = extractOddDigitPrimesFromFile(filename);

    std::set<std::string> circularPrimes;

    for (auto& prime: primes) {
        std::string strnum = prime;

        bool isCircular = true;
        int length = strnum.length();
        for (int i = 1; i <= length; i++) {
            char last = strnum.back();
            strnum.pop_back();
            strnum.insert(0, std::to_string(last - 48));
            bool found = false;
            for (const auto &j: primes) {
                if (j == strnum) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                isCircular = false;
                break;
            }
        }
        if (isCircular) {
            circularPrimes.insert(prime);
        }
    }

    std::cout << "Number of circular primes below 1 million: " << circularPrimes.size() << std::endl;

    return 0;
}
