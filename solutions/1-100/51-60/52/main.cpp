#include <algorithm>
#include <functional>
#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"


int main() {

    int smallestSpecialNumber = 0;

    for(int i = 1000; i < 10000000; i++) {
        if(areNumbersPermutations(i, 2 * i)) {
            if(areNumbersPermutations(i, 3 * i)) {
                if(areNumbersPermutations(i, 4 * i)) {
                    if(areNumbersPermutations(i, 5 * i)) {
                        if(areNumbersPermutations(i, 6 * i)) {
                            smallestSpecialNumber = i;
                            goto endOfSearch;
                        }
                    }
                }
            }
        }
    }


endOfSearch:

    std::cout << "Smallest special number: " << smallestSpecialNumber << std::endl;

    return 0;
}
