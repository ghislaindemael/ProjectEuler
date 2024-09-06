//
// Created by ghisl on 06/09/2024.
//

#include "35.h"

bool containsEvenDigits(const std::string& input) {
    for(char c : input) {
        if(c % 2 == 0) {
            return true;
        }
    }
    return false;
}

std::set<std::string> extractOddDigitPrimesFromFile(const std::string& filename) {
    std::set<std::string> primes { "2" };
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string number;

        while (std::getline(iss, number, ',')) {
            if(!containsEvenDigits(number)) {
                primes.insert(number);
            }
        }
    }

    file.close();
    return primes;
}
