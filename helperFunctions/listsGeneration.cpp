//
// Created by ghisl on 08/09/2024.
//

#include "listsGeneration.h"

std::set<int64_t> generateSetOfNFirstTriangularNumbers(int limit) {
    std::set<int64_t> triangularNumbers;
    for(int64_t n = 1; n <= limit; n++) {
        triangularNumbers.insert((n*n + n) / 2);
    }
    return triangularNumbers;
}

std::set<int64_t> generateSetOfNFirstPentagonalNumbers(int limit) {
    std::set<int64_t> pentagonalNumbers;
    for(int64_t n = 1; n <= limit; n++) {
        pentagonalNumbers.insert((3*n*n - n) / 2);
    }
    return pentagonalNumbers;
}

std::set<int64_t> generateSetOfNFirstHexagonalNumbers(int limit) {
    std::set<int64_t> hexagonalNumbers;
    for(int64_t n = 1; n <= limit; n++) {
        hexagonalNumbers.insert(2*n*n - n);
    }
    return hexagonalNumbers;
}
