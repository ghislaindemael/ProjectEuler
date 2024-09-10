#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    int64_t largest = 40755;
    int limit = 69000;
    auto triangular = generateSetOfNFirstTriangularNumbers(limit);
    auto pentagonal = generateSetOfNFirstPentagonalNumbers(limit);
    auto hexagonal  = generateSetOfNFirstHexagonalNumbers(limit);

    for(auto& number : triangular) {
        if(pentagonal.contains(number) && hexagonal.contains(number)) {
            std::cout << number << " is triple special" << std::endl;
            if(number > largest) {
                largest = number;
                break;
            }
        }
    }

    std::cout << "Next triangular-pentagonal-hexagonal number: " << largest << std::endl;
}
