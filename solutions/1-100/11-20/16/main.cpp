#include <vector>
#include <iostream>
#include <ranges>

//array of size 303 is ok

struct KeyPair {
    int oldNum = 0;
    int newNum = 0;
    KeyPair() = default;
};

void printValues(std::vector<KeyPair> &number, std::string indication) {
    std::cout << indication << ": " << std::endl;
    std::cout << "Old num: ";
    for (KeyPair k: number) {
        std::cout << k.oldNum;
    }
    std::cout << std::endl;
    std::cout << "New num: ";
    for (KeyPair k: number) {
        std::cout << k.newNum;
    }
    std::cout << std::endl;
}

void multiply(std::vector<KeyPair> &toMult, int mult) {

    //printValues(toMult, "Pre mult");

    for (int i = toMult.size() - 1; i > 0; i--) {
        toMult[i].newNum += toMult[i].oldNum * mult;
        if (toMult[i].newNum >= 10) {
            toMult[i - 1].newNum += toMult[i].newNum / 10;
            toMult[i].newNum = toMult[i].newNum % 10;
        }
    }

    for (KeyPair& k: toMult) {
        k.oldNum = k.newNum;
        k.newNum = 0;
    }

    //printValues(toMult, "Post mult & switch");
}


int main() {

    std::vector<KeyPair> number(303);
    number[302].oldNum = 1;

    int mult = 2;
    int power = 1000;

    for (int i = 0; i < power; i++) {
        multiply(number, mult);
    }

    std::cout << "2^1000: ";
    for (KeyPair k: number) {
        std::cout << k.oldNum;
    }
    std::cout << std::endl;

    int sumOfDigits = 0;
    for (KeyPair k: number) {
        sumOfDigits += k.oldNum;
    }
    std::cout << "Sum of digits: " << sumOfDigits << std::endl;



    return 0;
}
