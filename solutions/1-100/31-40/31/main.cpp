#include <iostream>
#include <vector>

#include "31.h"

int main() {
    std::vector<int> coins {1, 2, 5, 10, 20, 50, 100, 200};
    int amount = 200;

    std::cout << "Coin change combinations are: " << coinCombinations(coins, 0, amount) << std::endl;

    return 0;
}
