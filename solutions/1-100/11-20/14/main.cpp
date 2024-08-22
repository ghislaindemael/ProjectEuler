#include <algorithm>
#include <vector>
#include <iostream>

int64_t collatz(int64_t num, std::vector<int64_t>& memo) {

    if (memo[num] != 0) {
        return memo[num];
    }

    int64_t steps = 0;
    int64_t originalNum = num;
    while (num != 1) {
        steps++;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num < originalNum && memo[num] != 0) {
            steps += memo[num] - 1;
            break;
        }
    }

    memo[originalNum] = steps;
    return steps;
}

int main() {
    std::pair<int64_t, int64_t> greatest {0, 0};
    std::vector<int64_t> memo(1000000, 0);

    for (int64_t i = 1; i < 1000000; i++) {
        int64_t chainLen = collatz(i, memo);
        if (chainLen > greatest.second) {
            greatest.second = chainLen;
            greatest.first = i;
        }
    }

    std::cout << "Greatest chain is length " << greatest.second << " using " << greatest.first << std::endl;

    return 0;
}
