#include <iostream>
#include <vector>

#include "21.h"


int main() {


    int limit = 10000;
    std::vector<int> sums {};

    for(int i = 0; i < limit; i++) {
        sums.push_back( sumOfDivisors(i));
    }

    int sumOfAmicable = 0;

    for(int i = 0; i < limit; i++) {
        if(sums[i] < limit) {
            if( i != sums[i] && sums[sums[i]] == i) {
                sumOfAmicable += i;
            }
        }

    }

    std::cout << "Sums of amicable number under " << limit << ": " << sumOfAmicable << std::endl;

    return 0;
}

