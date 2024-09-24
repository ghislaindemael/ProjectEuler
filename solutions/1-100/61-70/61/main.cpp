#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <climits>
#include <random>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils/listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/primeFunctions.h"
#include "utils/stringOperations.h"

int main() {
    constexpr int lower = 1000;
    constexpr int upper = 9999;
    std::vector sets = {
        genTriangularNumbersStringSetBetween(lower, upper),
        genSquareNumbersStringSetOfBetween(lower, upper),
        genPentagonalNumbersStringSetBetween(lower, upper),
        genHexagonalNumbersStringSetBetween(lower, upper),
        genHeptagonalNumbersStringSetBetween(lower, upper),
        genOctagonalNumbersStringSetBetween(lower, upper),
    };
    std::vector<int> nums{};
    std::vector<bool> used{};

startOfSearch:
    for (int num1 = 1000; num1 <= upper; num1++) {
        bool found1 = false;
        used = {false, false, false, false, false, false};
        for (int s = 0; s <= sets.size() - 1; s++) {
            if (!used[s] && sets[s].contains(std::to_string(num1))) {
                used[s] = true;
                found1 = true;
                //std::cout << "Num 1: " << num1 << " found in set at index: " << s << std::endl;
                break;
            }
        }
        if (found1) {
            int num2start = (num1 % 100) * 100;
            for (int num2 = num2start; num2 <= num2start + 99; num2++) {
                bool found2 = false;
                for (int s = 0; s <= sets.size() - 1; s++) {
                    if (!used[s] && sets[s].contains(std::to_string(num2))) {
                        used[s] = true;
                        found2 = true;
                        //std::cout << "Num 2: " << num2 << " found in set at index: " << s << std::endl;
                        break;
                    }
                }
                if (found2) {
                    int num3start = (num2 % 100) * 100;
                    for (int num3 = num3start; num3 <= num3start + 99; num3++) {
                        bool found3 = false;
                        for (int s = 0; s <= sets.size() - 1; s++) {
                            if (!used[s] && sets[s].contains(std::to_string(num3))) {
                                used[s] = true;
                                found3 = true;
                                //std::cout << "Num 3: " << num3 << " found in set at index: " << s << std::endl;
                                break;
                            }
                        }
                        if (found3) {
                            int num4start = (num3 % 100) * 100;
                            for (int num4 = num4start; num4 <= num4start + 99; num4++) {
                                bool found4 = false;
                                for (int s = 0; s <= sets.size() - 1; s++) {
                                    if (!used[s] && sets[s].contains(std::to_string(num4))) {
                                        used[s] = true;
                                        found4 = true;
                                        //std::cout << "Num 4: " << num4 << " found in set at index: " << s << std::endl;
                                        break;
                                    }
                                }
                                if (found4) {
                                    int num5start = (num4 % 100) * 100;
                                    for (int num5 = num5start; num5 <= num5start + 99; num5++) {
                                        bool found5 = false;
                                        for (int s = 0; s <= sets.size() - 1; s++) {
                                            if (!used[s] && sets[s].contains(std::to_string(num5))) {
                                                used[s] = true;
                                                found5 = true;
                                                //std::cout << "Num 5: " << num5 << " found in set at index: " << s << std::endl;
                                                break;
                                            }
                                        }
                                        if (found5) {
                                            int num6 = (num5 % 100) * 100 + (num1 / 100);
                                            bool found6 = false;
                                            for (int s = 0; s <= sets.size() - 1; s++) {
                                                if (!used[s] && sets[s].contains(std::to_string(num6))) {
                                                    used[s] = true;
                                                    found6 = true;
                                                    //std::cout << "Num 6: " << num6 << " found in set at index: " << s << std::endl;
                                                    break;
                                                }
                                            }
                                            if (found6) {
                                                nums = {num1, num2, num3, num4, num5, num6};
                                                goto endOfSearch;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

endOfSearch:
    if (nums.empty()) {
        std::cout << "No solution found, restarting with shuffled set vector." << std::endl;
        auto rng = std::default_random_engine{};
        std::ranges::shuffle(sets, rng);
        goto startOfSearch;
    }

    int sumOfNumbers = 0;
    std::cout << "6 cyclic numbers : ";
    for (auto& num: nums) {
        std::cout << num << " ";
        sumOfNumbers += num;
    }
    std::cout << std::endl;
    std::cout << "Sum of numbers: " << sumOfNumbers << std::endl;


    return EXIT_SUCCESS;
}
