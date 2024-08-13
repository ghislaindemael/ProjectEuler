#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#include "4.h"

int main() {

    int largestPalindrome = 1;

    for(int i = 999; i >= 100; i--) {
        for(int j = 999; j >= 100; j--) {
            int mult = i*j;
            if(mult < largestPalindrome) {
                break;
            }
            if(isPalindrome(mult)) {
                if(mult > largestPalindrome) {
                    largestPalindrome = mult;
                    break;
                }
            }
        }
    }

    std::cout << "Largest palindrome: " << largestPalindrome << std::endl;
    return EXIT_SUCCESS;

}
