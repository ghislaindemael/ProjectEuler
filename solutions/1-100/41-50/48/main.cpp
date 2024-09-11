#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    int64_t endSum = 0;

    for(int64_t i = 1; i <= 1000; i++) {
        int64_t innerPower = 1;
        for(int j = 0; j < i; j++) {
            innerPower *= i;
            if (innerPower > 10000000000) {
                innerPower %= 10000000000;
            }
        }

        endSum += innerPower;
        if (endSum > 10000000000) {
            endSum %= 10000000000;
        }
    }

    std::cout << "Last 10 digits of self powers sum: " << endSum << std::endl;

    return 0;
}
