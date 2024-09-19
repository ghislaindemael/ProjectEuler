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

std::set<int64_t> parsePrimeIntSetFromFile(const std::string &filename) {
    std::set<int64_t> primes {};
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
            primes.insert(stoll(number));
        }
    }

    file.close();
    return primes;
}

std::vector<std::string> parsePrimeVectorFromFile(const std::string &filename) {
    std::vector<std::string> primes {};
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
            primes.push_back(number);
        }
    }

    file.close();
    return primes;
}

std::vector<int64_t> parsePrimeIntVectorFromFile(const std::string &filename) {
    std::vector<int64_t> primes {};
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
            primes.push_back(stoll(number));
        }
    }

    file.close();
    return primes;
}

std::vector<std::string> parseWordArrayFromFile(const std::string &filename) {
    std::vector<std::string> words {};
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (std::getline(iss, word, ',')) {
            word.erase(0, 1);
            word.pop_back();
            words.push_back(word);
        }
    }

    file.close();
    return words;
}
