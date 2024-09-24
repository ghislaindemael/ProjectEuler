#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <climits>
#include <map>
#include <random>
#include <ranges>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils/listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/primeFunctions.h"
#include "utils/stringOperations.h"


int main(){

    std::map<std::vector<char>,std::pair<int,std::string>> map;

    int maxDigits = 12;
    for(int i = 1; ; i++) {
        bigint cube(i);
        cube *= i * i;
        std::string numstring = cube.toString();
        if(numstring.length() > maxDigits) {
            break;
        }
        std::vector<char> digits = getDigitsCharVector(numstring);
        if(map.contains(digits)) {
            map.at(digits).first++;
        } else {
            map[digits] = {1, numstring};
        }
    }

    for(auto&[fst, snd]: map | std::views::values) {
        if(fst == 5) {
            std::cout << "Smallest cube with 5 cubic permutations: " << snd << std::endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}
