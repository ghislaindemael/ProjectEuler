#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "23.h"

int main() {
    std::set<int> abundantNumbers{};

    for (int i = 1; i < 28123; i++) {
        if (sumOfDivisors(i) > i) {
            abundantNumbers.insert(i);
        }
    }

    int sumOfNonSumOfAbundant = 0;

    for(int i = 1; i <= 28123; i ++) {
        bool isSumOfAbundant = false;
        for(int a : abundantNumbers) {
            if(abundantNumbers.contains(i - a)) {
                isSumOfAbundant = true;
                break;
            }
        }
        if(!isSumOfAbundant) {
            sumOfNonSumOfAbundant += i;
        }
    }

    std::cout << "Sum of positive integers that aren't a sum of A.N.: " << sumOfNonSumOfAbundant << std::endl;


    return 0;
}
