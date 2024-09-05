#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <valarray>

int main() {
    int sumOfFifthPowerDigitNumbers{0};
    int power = 5;

    for (int i = 2; i < 1000000; i++) {
        int num = i;
        int sumOfDigits {0};
        while (num > 0) {
            sumOfDigits += std::pow(num % 10, power);
            num /= 10;
        }
        if(sumOfDigits == i) {
            std::cout << i << " is a fifth power digit sum" << std::endl;
            sumOfFifthPowerDigitNumbers += i;
        }
    }

    std::cout << "Sum of fifth power digit sum number: " << sumOfFifthPowerDigitNumbers << std::endl;

    return 0;
}
