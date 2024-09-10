//
// Created by ghisl on 10/09/2024.
//

#include "43.h"

void genPermutationsAndAddToSumIfCheck(std::vector<int>& dig, std::vector<int>& div, int start, int end, int64_t& sum) {
    if (start == end) {
        bool validCombination = true;
        for(int i = 1; i < 8; i++) {
            if((dig[i] * 100 + dig[i+1] * 10 + dig[i+2]) % div[i] != 0) {
                validCombination = false;
                break;
            }
        }

        if(validCombination) {
            std::string concatenatedNumber;
            for (int num : dig) {
                concatenatedNumber += std::to_string(num);
            }
            sum += std::stoll(concatenatedNumber);
        }

        return;
    }

    for (int i = start; i <= end; ++i) {
        std::swap(dig[start], dig[i]);
        genPermutationsAndAddToSumIfCheck(dig, div, start + 1, end, sum);
        std::swap(dig[start], dig[i]); // backtrack
    }
}