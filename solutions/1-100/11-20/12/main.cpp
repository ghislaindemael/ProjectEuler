#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>

int64_t countDivisors(int64_t n) {
    int64_t count = 0;
    int64_t sqrtN = static_cast<int64_t>(std::sqrt(n));

    for (int64_t i = 1; i <= sqrtN; ++i) {
        if (n % i == 0) {
            count += (i == n / i) ? 1 : 2;
        }
    }

    return count;
}

int main() {

    int64_t triangularNum = 0;
    int64_t naturalNum = 0;

    while (true) {
        naturalNum++;
        triangularNum += naturalNum;

        int64_t divisorCount = countDivisors(triangularNum);

        //std::cout << triangularNum << " has " << divisorCount << " divisors." << std::endl;
        if (divisorCount >= 500) {
            break;
        }
    }

    std::cout << "First T.N. with > 500 divisors: " << triangularNum << std::endl;

    return EXIT_SUCCESS;

}
