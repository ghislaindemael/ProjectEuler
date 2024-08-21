#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {

    std::ifstream inputFile("8.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::vector<int> digits;
    std::string line;

    while (std::getline(inputFile, line)) {
        for (char ch : line) {
            if (std::isdigit(ch)) {
                digits.push_back(ch - '0');
            }
        }
    }

    inputFile.close();

    int64_t greatestMult = 0;

    for (int i = 0; i <= digits.size() - 13; i++) {
        int64_t mult = 1;
        bool valid13 = true;
        for (int j = i; j < i + 13; j++) {
            if (digits[j] == 0) {
                valid13 = false;
                break;
            }
            mult *= digits[j];
        }
        if (valid13 && mult > greatestMult) {
            greatestMult = mult;
        }
    }

    std::cout << "Biggest 13-consecutive digits product: " << greatestMult << std::endl;

    return EXIT_SUCCESS;

}
