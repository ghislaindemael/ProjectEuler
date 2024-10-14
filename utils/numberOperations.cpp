#include "numberOperations.h"

#include <iostream>
#include <set>
#include <vector>
#include <cmath>


std::vector<int64_t> getDigitsVector(int64_t num) {
    std::vector<int64_t> digits;
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    return digits;
}

int64_t factorial(int64_t n) {
    int factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;

}
