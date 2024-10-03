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
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

struct Fraction {
    mp::cpp_int numerator = 0;
    mp::cpp_int denominator = 1;
};

int main() {

    std::vector<int> eSequenceDigits {};
    for(int i = 1; i <= 33; i++) {
        eSequenceDigits.push_back(1);
        eSequenceDigits.push_back(2*i);
        eSequenceDigits.push_back(1);
    }
    std::ranges::reverse(eSequenceDigits);

    Fraction fraction {};

    for(auto& i : eSequenceDigits) {
        const mp::cpp_int newNum = fraction.denominator;
        const mp::cpp_int newDen = i * fraction.denominator + fraction.numerator;
        fraction.numerator = newNum;
        fraction.denominator = newDen;
    }
    fraction.numerator += 2 * fraction.denominator;

    std::cout << "Sum of digits: " << getSumOfDigits(fraction.numerator.convert_to<std::string>()) << std::endl;

    return 0;
}
