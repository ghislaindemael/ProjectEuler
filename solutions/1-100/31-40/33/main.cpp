#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <vector>

int main() {

    std::vector<std::pair<int, int>> nonTrivialFractions {};

    for(int num = 10; num < 100; num ++) {
        for(int denom = num + 1; denom < 100; denom++) {
            double fraction = num * 1.0 / denom;
            //Impossible to cancel first-first or second-second, necessarily first-second pairs

            int firstOfFirst = num / 10;
            int secondOfFirst = num % 10;
            int firstOfSecond = denom / 10;
            int secondOfSecond = denom % 10;

            if(!(firstOfFirst == secondOfFirst || firstOfSecond == secondOfSecond || secondOfFirst == secondOfSecond)) {
                if(fraction == 1.0 * firstOfFirst / secondOfSecond && secondOfFirst == firstOfSecond ) {
                    std::cout << num << "/" << denom << " = " << firstOfFirst << "/" << secondOfSecond << std::endl;
                    nonTrivialFractions.emplace_back(num, denom);
                }
                if(fraction == 1.0 * secondOfFirst / firstOfSecond && firstOfFirst == secondOfSecond) {
                    std::cout << num << "/" << denom << " = " << secondOfFirst << "/" << firstOfSecond << std::endl;
                    nonTrivialFractions.emplace_back(num, denom);
                }
            }
        }
    }

    int num_product { 1 };
    int denom_product { 1 };
    for(auto& pair : nonTrivialFractions) {
        num_product *= pair.first;
        denom_product *= pair.second;
    }

    for(int i = 2; i < sqrt(denom_product); i++) {
        while(num_product % i == 0 && denom_product % i == 0) {
            num_product /= i;
            denom_product /= i;
        }
    }

    std::cout << "Final simplied fraction: " << num_product << "/" << denom_product << std::endl;

    return 0;
}
