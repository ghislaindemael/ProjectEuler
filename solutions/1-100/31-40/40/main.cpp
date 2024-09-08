#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {

    double nextIndexLog = 1.0;
    std::vector<int> digitsToFind;
    int counter = 0;

    for (int i = 1; i <= 1000000; i++) {
        counter += std::floor(std::log10(i)) + 1;

        if (std::log10(counter) + 1 >= nextIndexLog) {
            int counterCopy = counter;
            int removedDigits = 0;
            while (std::log10(counterCopy) + 1 > nextIndexLog) {
                counterCopy--;
                removedDigits++;
            }
            std::string num = std::to_string(i);
            digitsToFind.push_back(num.at(num.size() - 1 - removedDigits) - 48);
            nextIndexLog++;

            if (digitsToFind.size() == 7) {
                break;
            }
        }
    }

    int productOfDigits{1};

    std::cout << "Digits to find: ";
    for (auto &d: digitsToFind) {
        productOfDigits *= d;
        std::cout << d << ' ';
    }
    std::cout << std::endl;

    std::cout << "Product of digits: " << productOfDigits << std::endl;

    return 0;
}
