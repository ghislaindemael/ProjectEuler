//
// Created by ghisl on 07/09/2024.
//

#include "fileParsing.h"


std::set<std::string> parsePrimeSetFromFile(const std::string &filename) {
    std::set<std::string> primes {};
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
            primes.insert(number);
        }
    }

    file.close();
    return primes;
}
