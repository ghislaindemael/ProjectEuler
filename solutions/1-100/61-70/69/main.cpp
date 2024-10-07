#include <iostream>
#include <vector>
#include <utility>

constexpr int MAX = 1000000;

int main() {
    std::vector<int> phi(MAX + 1);

    for (int i = 0; i <= MAX; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= MAX; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    std::pair<int, double> largestNandRatio {0, 0};

    for (int i = 2; i <= MAX; ++i) {
        if (double ratio = static_cast<double>(i) / phi[i]; ratio > largestNandRatio.second) {
            largestNandRatio = std::make_pair(i, ratio);
        }
    }

    std::cout << "Largest double: " << largestNandRatio.second << " for n: " << largestNandRatio.first << std::endl;

    return 0;
}
