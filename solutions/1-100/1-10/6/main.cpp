#include <algorithm>
#include <iostream>
#include <vector>


int main() {

    int64_t sumOfSquares = 0;
    int64_t sum = 0;

    for(int i = 1; i<= 100; i++) {
        sumOfSquares += (i * i);
        sum += i;
    }

    int64_t squareOfSum = sum * sum;
    int64_t difference = abs(sumOfSquares - squareOfSum);

    std::cout << "Difference betwwen sum of squares and square of sum of 1 to 100 is " << difference << std::endl;

    return EXIT_SUCCESS;

}
