#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int factorial(int n) {
    int mult = 1;
    for (int i = 1; i <= n; i++) {
        mult *= i;
    }
    return mult;
}


int main() {
    std::vector<int> digits{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> solution {};
    int progression = 1000000;

    while (digits.size() > 0) {
        int factorialSize = factorial(digits.size() - 1);
        if (factorialSize > progression) {
        } else {
            int index = (progression - 1) / factorialSize;
            solution.push_back(digits[index]);
            digits.erase(digits.begin() + index);
            progression -= index * factorialSize;
        }
    }

    std::cout << "1000000th permutation of digits 0-9: ";
    for (int i: solution) {
        std::cout << i;
    }
    std::cout << std::endl;

    return 0;
}
