#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    std::set<int64_t> primes = generateSetOfPrimesUnderN(5000);

    std::pair<int64_t, int64_t> indexAndValid {0, 0};

    for (int i = 2; i < 1000000; i++) {
        int64_t copy = i;
        std::set<int64_t> factors {};
        for(auto prime : primes) {
            while (copy % prime == 0) {
                copy /= prime;
                factors.insert(prime);
            }
            if(copy == 1) {
                break;
            }
        }
        if(factors.size() == 4) {
            if(indexAndValid.first == 0) {
                indexAndValid.first = i;
            }
            indexAndValid.second++;
            if(indexAndValid.second == 4) {
                break;
            }
        } else {
            indexAndValid = { 0, 0 };
        }
    }

    std::cout << "First index with 4 consecutive special numbers : " << indexAndValid.first << std::endl;


    return 0;
}
