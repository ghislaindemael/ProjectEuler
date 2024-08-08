#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main() {

    int64_t toFactor = 600851475143;
    int64_t limit = ceil(sqrt(toFactor));

    std::vector<int64_t> primes {};
    std::vector<int64_t> factors {};

    for(int64_t i { 2 }; i < limit; i++) {
        bool isprime = true;
        for (int64_t prime : primes) {
            if(i % prime == 0) {
                isprime = false;
            }
        }
        if(isprime) {
            primes.push_back(i);
            while(toFactor % i == 0) {
                factors.push_back(i);
                toFactor /= i;
                if(toFactor == 1) {
                    i = limit;
                }
            }
        }

    }

    std::cout << "Factors of 600851475143: " << std::endl;
    for(const int64_t f : factors) {
        std::cout << f << ", ";
    }


    return 0;
}
