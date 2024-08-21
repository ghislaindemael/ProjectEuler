#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

int main() {

    int64_t toCheck = 1;

    std::vector<int64_t> primes {};

    while (true) {
        start:
        toCheck++;

        if(toCheck > 2000000) {
            break;
        }

        if(toCheck % 100000 == 0) {
            std::cout << toCheck << std::endl;
        }

        for (int64_t prime : primes) {
            if(toCheck % prime == 0) {
                goto start;
            }
        }

        primes.push_back(toCheck);
    }

    int64_t sum = 0;
    for(int64_t prime : primes) {
        sum += prime;
    }

    std::cout << "Sum of primes below 2 million: " << sum << std::endl;

    return EXIT_SUCCESS;

}
