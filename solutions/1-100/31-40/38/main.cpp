#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "helperFunctions/stringOperations.h"

int main() {

    std::string biggestPandigital;

    for(int i = 0; i < 10000; i++) {
        std::string productConcat;
        for(int n = 1; n < 10; n++) {
            productConcat += std::to_string(i*n);
            int length = productConcat.length();
            if(length > 9) {
                break;
            }
            if(length == 9 && isUniquelyPandigital(productConcat)) {
                if(productConcat > biggestPandigital) {
                    biggestPandigital = productConcat;
                }
            }
        }
    }

    std::cout << "Biggest pandigital concatenation: " << biggestPandigital << std::endl;

    return 0;
}
