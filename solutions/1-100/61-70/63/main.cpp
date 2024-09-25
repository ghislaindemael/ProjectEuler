#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <climits>
#include <map>
#include <random>
#include <ranges>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils/listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/primeFunctions.h"
#include "utils/stringOperations.h"
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

int main() {

    int countLengthIsPower = 0;

    for (int base = 1; base <= 9; base++) {
        boost::multiprecision::cpp_int num = base;
        const mp::cpp_int num2 = base;
        for (int power = 1; power <= 25; power++) {
            num = num2;
            for (int i = 1; i < power; i++) {
                num *= num2;
            }
            if (num.str().length() == power) {
                std::cout << base << " " << power << " " << num << std::endl;
                countLengthIsPower++;
            }
        }
    }

    std::cout << "Count of length = power : " << countLengthIsPower << std::endl;


    return EXIT_SUCCESS;
}
