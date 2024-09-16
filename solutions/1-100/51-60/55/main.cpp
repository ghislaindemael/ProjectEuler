#include <algorithm>
#include <functional>
#include <iostream>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/stringOperations.h"


int main() {

    int lychrels { 0 };

    for(int64_t n = 1; n < 10000; n++) {

        std::string num = std::to_string(n);
        for (int i = 0; i < 50; i++) {
            std::string reversed = std::to_string(n);
            std::ranges::reverse(reversed);
            std::string sum = std::to_string(std::stoll(num) + std::stoll(reversed));
            if (isStringPalindrome(sum)) {
                //std::cout << num << " + " << reversed << " = " << sum << std::endl;
                std::cout << n << " + " << i << " iterations: " << sum << std::endl;
                lychrels++;
                break;
            }
            num = sum;
        }
        //std::cout << "More than 50 iterations for " << n << std::endl;
    }

    std::cout << "Number of pseudo-Lychrel numbers (< 50 iterations): " << lychrels << std::endl;


    return 0;
}
