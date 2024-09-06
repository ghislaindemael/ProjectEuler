#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <vector>

int main() {

    int factorials[] {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int sumOfSpecialDigits { 0 };

    for(int i = 10; i < 1000000; i++) {
        int sumOfFactOfDigits { 0 };
        std::string num = std::to_string(i);
        for(char& c : num) {
            sumOfFactOfDigits += factorials[c - 48];
        }
        if(sumOfFactOfDigits == i) {
            sumOfSpecialDigits += i;
        }
    }

    std::cout << "Sum of special digits : " << sumOfSpecialDigits << std::endl;

    return 0;
}
