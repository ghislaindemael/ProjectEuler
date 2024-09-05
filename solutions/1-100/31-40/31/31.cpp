//
// Created by ghisl on 05/09/2024.
//

#include "31.h"

int coinCombinations(std::vector<int>& coins, int index, int target) {
    if (target == 0) {
        return 1;
    }
    int combinations = 0;
    for (int i = index; i < coins.size(); i++) {
        if (target - coins[i] >= 0) {
            combinations += coinCombinations(coins, i, target - coins[i]);
        }
    }
    return combinations;
}