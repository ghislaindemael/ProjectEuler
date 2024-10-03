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
#include <boost/multiprecision/cpp_dec_float.hpp>


namespace mp = boost::multiprecision;
typedef mp::cpp_dec_float_100 precfloat;

int main() {
    int oddPeriodCount = 0;

    for (int i = 2; i <= 10000; i++) {
        if (i % 100 == 0) {
            std::cout << i << std::endl;
        }

        int sqrt_i = static_cast<int>(std::sqrt(i));
        if (sqrt_i * sqrt_i == i) {
            continue;
        }

        precfloat number = i;
        precfloat sqrt_number = mp::sqrt(number);
        std::vector<int> digits;

        bool foundPeriod = false;
        for (int j = 0; j < 101; j++) {
            precfloat whole_part = mp::floor(sqrt_number);
            digits.push_back(static_cast<int>(whole_part));
            precfloat inverted_remainder = 1 / mp::remainder(sqrt_number, whole_part);
            sqrt_number = inverted_remainder;

            if (digits.size() >= 5) {
                for (int len = 1; len <= 11; len++) {
                    for (int shift = 0; shift < 7; shift++) {
                        if (shift + 6 * len >= digits.size()) {
                            break;
                        }
                        int i1 = digits[shift + len];
                        int i2 = digits[shift + 2 * len];
                        int i3 = digits[shift + 3 * len];
                        int i4 = digits[shift + 4 * len];
                        int i5 = digits[shift + 5 * len];
                        if (digits[shift] == i1 &&
                            i1 == i2 &&
                            i2 == i3 &&
                            i3 == i4 &&
                            i4 == i5 &&
                            i5 == digits[shift + 6 * len]) {
                            if (len % 2 == 1) {
                                oddPeriodCount++;
                            }
                            foundPeriod = true;
                            break;
                        }
                    }
                    if (foundPeriod) {
                        break;
                    }
                }
            }

            if (foundPeriod) {
                break;
            }
        }
    }

    std::cout << "Odd Period Count: " << oddPeriodCount << std::endl;
    return 0;
}
