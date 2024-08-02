#include <iostream>

int main() {

    int int1 { 1 };
    int int2 { 2 };
    int nextNum { 0 };
    int sumOfEvens { 2 };

    while(nextNum < 4000000) {
        nextNum = int1 + int2;
        int1 = int2;
        int2 = nextNum;
        if(nextNum % 2 == 0) {
            sumOfEvens += nextNum;
        }
    }

    std::cout << "Sum of even numbers: " << sumOfEvens << std::endl;

    return 0;
}
