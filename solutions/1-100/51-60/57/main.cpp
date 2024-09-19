#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/stringOperations.h"

struct BigFraction {
    bigint num = bigint(0);
    bigint denum = bigint(0);

    BigFraction(const bigint& numerator, const bigint& denominator) {
        num = numerator;
        denum = denominator;
    }

    void switchNumDenum() {
        bigint temp = num;
        num = denum;
        denum = temp;
    }
};


int main() {
    int longerNumFractions{0};
    BigFraction initial(1, 2);

    for (int i = 1; i < 1000; i++) {
        BigFraction next(initial.num + 2 * initial.denum, initial.denum);
        next.switchNumDenum();
        next.num += next.denum;

        if (next.num.getStringLength() > next.denum.getStringLength()) {
            std::cout << "Iter " << i + 1 << " is a special fraction" << std::endl;
            longerNumFractions++;
        }
        next.num -= next.denum;
        initial = next;
    }

    std::cout << "Number of fractions with longer numerator: " << longerNumFractions << std::endl;

    return EXIT_SUCCESS;
}
