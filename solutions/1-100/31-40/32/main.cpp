#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include "32.h"

int main() {

    std::set<int> pandigitalResults {};

    for(int i = 1; i < 100000; i++) {
        for(int j = 1; j * i < 10000; j++) {
            std::string stri = std::to_string(i);
            std::string strj = std::to_string(j);
            if(!haveCommonDigits(stri, strj)) {
                int result = i * j;
                std::string strresult = std::to_string(result);
                if(containsOnlyOnceAllDigits(strresult.append(stri.append(strj)))) {
                    std::cout << i << " * " << j << " = " << result << std::endl;
                    pandigitalResults.insert(result);
                }
            }
        }
    }


    int sumOfNumbers { 0 };
    for(int i : pandigitalResults) {
        sumOfNumbers += i;
    }

    std::cout << "Sum of pandigital products: " << sumOfNumbers << std::endl;

    return 0;
}
