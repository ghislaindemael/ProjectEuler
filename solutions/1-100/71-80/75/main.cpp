#include <iostream>
#include <ranges>
#include <set>
#include <utility>
#include <vector>
#include <thread>


#include "utils/numberOperations.h"
#include "utils/stringOperations.h"

int main() {

    int64_t maxLength = 1500000;
    int64_t maxLenSquare = maxLength * maxLength;
    int64_t maxI = maxLength / (3.41421356237);
    std::unordered_map<int64_t, int> map;

    std::set<int64_t> squaresSet;
    std::vector<int64_t> squares(maxLength);
    for(int64_t i = 0; i < maxLength; ++i) {
        int64_t square = i * i;
        squares[i] = square;
        squaresSet.insert(square);
    }

    std::cout << "Finished initialization" << std::endl;

    for (int64_t i = 2; i < maxI; ++i) {
        if(i % 1000 == 0) {
            std::cout << i << std::endl;
        }
        int64_t sqi = squares[i];
        int64_t maxJ = std::min((maxLength - i) / 2, static_cast<int64_t>(std::sqrt(maxLenSquare - sqi)));
        for (int64_t j = i; j < maxJ; ++j) {

            int64_t sumSq = sqi + squares[j];
            if (sumSq > maxLenSquare / 2) break;

            if(squaresSet.contains(sumSq)) {
                int64_t sum = i + j + static_cast<int64_t>(sqrt(sumSq));
                if (sum >= maxLength) {
                    break;
                }

                map[sum]++;
            }

        }
    }

    int countSingleSolutions = 0;
    for (const auto& pair : map) {
        //std::cout << pair.first << " " << pair.second << std::endl;
        if(pair.second == 1) {
            //std::cout << pair.first << " " << pair.second << std::endl;
            countSingleSolutions++;
        }
    }

    std::cout << "Lengths with only one solution: " << countSingleSolutions << std::endl;

    return 0;
}