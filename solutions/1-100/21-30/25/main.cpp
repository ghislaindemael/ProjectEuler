#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "25.h"

int main() {
    std::vector<int> fibo_1{1};
    std::vector<int> fibo_2{1};
    std::vector<int> fibo_next{0};
    int fiboSize = 1000;
    int fiboCount = 2;

    while (fibo_next.size() < fiboSize || fibo_2[0] == 0) {

        fiboCount++;
        addLeadingZeroIfNeeded(fibo_1);
        addLeadingZeroIfNeeded(fibo_2);
        int size = fibo_2.size();
        addLeadingZeroesUntilSize(fibo_1, size);
        addLeadingZeroesUntilSize(fibo_next, size);

        for (int i = size - 1; i >= 0; i--) {
            fibo_next[i] += fibo_1[i] + fibo_2[i];
            if (fibo_next[i] >= 10) {
                fibo_next[i - 1] += 1;
                fibo_next[i] -= 10;
            }
        }

        for(int i = 0; i < fibo_next.size(); i++) {
            fibo_1[i] = fibo_2[i];
            fibo_2[i] = fibo_next[i];
            fibo_next[i] = 0;
        }
    }

    std::cout << "First " << fiboSize << "-digit Fibonnaci number index: " << fiboCount << std::endl;

    return 0;
}
