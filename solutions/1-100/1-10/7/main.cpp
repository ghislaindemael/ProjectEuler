#include <algorithm>
#include <iostream>
#include <vector>


int main() {

    int toCheck = 1;

    std::vector<int64_t> primes {};

    while (primes.size() < 10001) {
        toCheck++;

        bool isprime = true;
        for (int64_t prime : primes) {
            if(toCheck % prime == 0) {
                isprime = false;
            }
        }

        if(isprime) {
            primes.push_back(toCheck);
        }
    }

    std::cout << "10001th prime number " << primes.back() << std::endl;


    return EXIT_SUCCESS;

}
