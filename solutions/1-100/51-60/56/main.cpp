#include <algorithm>
#include <functional>
#include <iostream>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/stringOperations.h"


int main() {

    int highestDigitSum = 0;

    for(int a = 1; a < 100; a++) {
        std::cout << a << std::endl;
        bigint biga = bigint(a);
        for(int b = 1; b < 100; b++) {
            bigint bigb = bigint(b);
            bigint power = bigint::_big_pow(biga, bigb);
            if(int s = getSumOfDigits(power.toString()); s > highestDigitSum) {
                highestDigitSum = s;
            }

        }
    }

    std::cout << "Biggest digit sum: " << highestDigitSum << std::endl;

    return 0;
}
