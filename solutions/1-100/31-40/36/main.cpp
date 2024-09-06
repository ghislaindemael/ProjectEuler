#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "36.h"


int main() {

    int sumOfDoubleBasePalindromes { 0 };

    for(int i = 1; i < 1000000; i++) {
        if(isPalindrome(std::to_string(i))) {
            std::string binstring = std::bitset<24>(i).to_string();
            if(isPalindrome(binstring)) {
                //std::cout << i << " and " << binstring << " are palindromes." << std::endl;
                sumOfDoubleBasePalindromes += i;
            }
        }
    }

    std::cout << "Sum of double-base palindromes: " << sumOfDoubleBasePalindromes << std::endl;

    return 0;
}
