#include <iostream>
#include <vector>


void printValues(std::vector<std::pair<int, int>> &number, std::string indication) {
    std::cout << indication << ": " << std::endl;
    std::cout << "Old num: ";
    for (auto& p: number) {
        std::cout << p.first;
    }
    std::cout << std::endl;
    std::cout << "New num: ";
    for (auto& p: number) {
        std::cout << p.second;
    }
    std::cout << std::endl;
}

void multiply(std::vector<std::pair<int, int>> &toMult, int mult) {

    for (int i = toMult.size() - 1; i > 0; i--) {
        toMult[i].second += toMult[i].first * mult;
        if (toMult[i].second >= 10) {
            toMult[i - 1].second += toMult[i].second / 10;
            toMult[i].second = toMult[i].second % 10;
        }
    }

    for (auto& p: toMult) {
        p.first = p.second;
        p.second = 0;
    }

    if (toMult.back().first == 0) {
        toMult.pop_back();
    }


}

int main() {

    std::vector<std::pair<int, int>> number(161);
    number[160].first = 1;

    for(int i = 1; i <= 100; i++) {
        multiply(number, i);
    }

    printValues(number, "Post mult");

    int sumOfDigits = 0;
    for (auto& pair : number) {
        sumOfDigits += pair.first;
    }
    std::cout << "Sum of digits: " << sumOfDigits << std::endl;


    return 0;
}

