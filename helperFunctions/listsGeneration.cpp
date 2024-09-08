//
// Created by ghisl on 08/09/2024.
//

#include "listsGeneration.h"

std::set<int> generateSetOfNFirstTriangularNumbers(int limit) {
    std::set<int> triangularNumbers;
    for(int n = 1; n <= limit; n++) {
        triangularNumbers.insert((n*n + n) / 2);
    }
    return triangularNumbers;
}
