#include <iostream>
#include <vector>
#include <utility>

#include "utils/stringOperations.h"
#include <boost/multiprecision/cpp_bin_float.hpp>

namespace mp = boost::multiprecision;


int main() {

    const mp::cpp_bin_float_50 threeSevenths = 3.0 / 7.0;
    std::pair<std::pair<int, int>, mp::cpp_bin_float_50> greatestFraction {{0, 1}, -1.0};

    for(int i = 2; i <= 1000000; i++) {
        int startJ = static_cast<int>(std::ceil(static_cast<double>(greatestFraction.second * i)));
        if (startJ < 1) startJ = 1;

        for(int j = startJ; j < i; j++) {
            if(std::gcd(i, j) == 1) {
                mp::cpp_bin_float_50 frac = static_cast<mp::cpp_bin_float_50>(j) / i;
                if(frac < threeSevenths) {
                    if(frac > greatestFraction.second) {
                        greatestFraction = {{j, i}, frac};
                    }
                } else {
                    break;
                }
            }
        }
    }


    std::cout << "Greatest frac lower than 3/7: " <<
        greatestFraction.first.first << "/" << greatestFraction.first.second << std::endl;

    return 0;
}
