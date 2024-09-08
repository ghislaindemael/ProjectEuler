#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {

    std::pair<int, int> mostSolutions { 0, 0 };

    for(int p = 10; p <= 1000; p++) {

        int numberOfTriplets { 0 };

        for(int a = 1; a < p / 2 + 1; a++) {
            for(int b = 1; b < p / 2 + 1; b++) {
                for(int c = 1; c < p / 2 + 1; c++) {
                    if(a*a + b*b == c*c && a + b + c == p) {
                        numberOfTriplets++;
                    }
                }
            }
        }

        if(numberOfTriplets > mostSolutions.first) {
            mostSolutions.first = numberOfTriplets;
            mostSolutions.second = p;
        }

    }

    std::cout << "Most solutions: " << mostSolutions.first << ", for number " << mostSolutions.second << std::endl;

    return 0;
}
