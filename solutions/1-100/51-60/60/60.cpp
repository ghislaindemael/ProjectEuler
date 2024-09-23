//
// Created by ghisl on 23/09/2024.
//

#include "60.h"

void processValidCombination(const std::vector<std::string>& combination, int& smallestSum) {
    int sumOfPrimes = 0;
    for (const auto& i: combination) {
        sumOfPrimes += std::stoi(i);
    }
    if (sumOfPrimes < smallestSum) {
        std::cout << "New smallest sum: " << sumOfPrimes << std::endl;
        smallestSum = sumOfPrimes;
    }
}

bool checkConcatenations(const std::vector<std::string>& combination, const std::set<std::string>& primes) {

    if (combination.size() < 2) {
        return true;
    }

    const std::string& lastAdded = combination.back();

    for (size_t i = 0; i < combination.size() - 1; ++i) {
        std::string concat1 = combination[i] + lastAdded;
        std::string concat2 = lastAdded + combination[i];

        if (concat1.length() >= 5) {
            if (!isPrime(std::stoll(concat1)) || !isPrime(std::stoll(concat2))) {
                return false;
            }
        } else {
            if (!primes.contains(concat1) || !primes.contains(concat2)) {
                return false;
            }
        }
    }
    return true;
}

void generateCombinations(const std::vector<std::string>& elements, const std::set<std::string>& primes, int k, int& smallestSum) {
    std::stack<std::pair<std::vector<std::string>, int>> stack;
    stack.push({{}, 0});

    while (!stack.empty()) {
        auto [combination, start] = stack.top();
        stack.pop();

        if (combination.size() == k) {
            processValidCombination(combination, smallestSum);
            continue;
        }

        for (int i = start; i < elements.size(); ++i) {
            combination.push_back(elements[i]);

            if (checkConcatenations(combination, primes)) {
                stack.emplace(combination, i + 1);
            }

            combination.pop_back();
        }
    }
}
