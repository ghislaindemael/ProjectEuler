#include <algorithm>
#include <functional>
#include <iostream>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/stringOperations.h"


int main() {

    int64_t largeChoices = 0;
    const auto oneMillion = bigint("1000000");

    for(bigint n = 1; n <= bigint(100); ++n) {
        for(bigint r = 1; r <= n; ++r) {
            bigint diff = n - r;
            bigint result = bigint::_big_fact(n) / (bigint::_big_fact(r) * bigint::_big_fact(diff));
            if(result > oneMillion) {
                largeChoices++;
            }
        }
    }

    std::cout << "N° of combinations greater than 1 million: " << largeChoices << std::endl;

    return 0;
}
