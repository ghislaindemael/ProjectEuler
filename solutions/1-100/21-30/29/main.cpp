#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include "libraries/bigint.h"

int main() {

    std::set<std::string> numbers {};

    int limit = 100;

    for(int a = 2; a <= limit; a++) {
        for(int b = 2; b <= limit; b++) {
            bigint biga = bigint(a);
            bigint bigb = bigint(b);
            std::string result = bigint::_big_pow(biga, bigb).toString();

            if(!numbers.contains(result)) {
                numbers.insert(result);
            }
        }
    }

    std::cout << "Number of terms in list for upper limit " << limit << ": " << numbers.size() << std::endl;

    return 0;
}
