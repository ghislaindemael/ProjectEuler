#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>


int main() {

    int toCheck = 20;
    int smallestMultipleOf1To20;

    while (true) {
        startLoop:
        toCheck++;
        for(int i = 1; i <= 20; i++) {
            if(toCheck % i != 0) {
                goto startLoop;
            }
        }
        std::cout << toCheck << std::endl;
        break;

    }

    return EXIT_SUCCESS;

}
