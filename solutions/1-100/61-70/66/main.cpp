#include <iostream>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using bigint = boost::multiprecision::cpp_int;

bigint solvePellsEquation(int D) {
    bigint m = 0;
    bigint d = 1;
    bigint a = static_cast<bigint>(std::sqrt(D));

    bigint num1 = 1;
    bigint num2 = a;

    bigint denom1 = 0;
    bigint denom2 = 1;

    bigint a0 = a;

    while (num2 * num2 - D * denom2 * denom2 != 1) {
        m = d * a - m;
        d = (D - m * m) / d;
        a = (a0 + m) / d;

        bigint numNext = a * num2 + num1;
        bigint denomNext = a * denom2 + denom1;

        num1 = num2;
        num2 = numNext;

        denom1 = denom2;
        denom2 = denomNext;
    }

    return num2;
}

int main() {
    bigint largestX = 0;
    int correspondingD = 0;

    std::vector<int64_t> squares(1001);
    for (int i = 0; i <= 1000; ++i) {
        squares[i] = static_cast<int64_t>(i) * i;
    }

    for (int D = 2; D <= 1000; ++D) {
        if (squares[static_cast<int>(std::sqrt(D))] == D) {
            continue;
        }

        bigint x = solvePellsEquation(D);

        if (x > largestX) {
            largestX = x;
            correspondingD = D;
        }
    }

    std::cout << "Largest X: " << largestX << " for D: " << correspondingD << std::endl;

    return 0;
}
