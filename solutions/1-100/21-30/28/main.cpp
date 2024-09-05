#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main() {

    /* No need to bruteforce it, we notice for each size s, we have:
     * s², s² - (i-1), s² - 2*(i-1), s² - 3*(i-1), or 4i² -6i + 6, for all s > 1 */

    int size = 1001;
    int64_t sum {1};

    for(int i = 3; i <= size; i += 2) {
        sum += 4*i*i - 6*i + 6;
    }

    std::cout << "Sum for a " << size << "x" << size << " grid: " << sum << std::endl;

    return 0;
}
