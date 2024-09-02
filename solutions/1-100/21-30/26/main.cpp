#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <mpfr.h>


std::vector<int> convertToDigitVector(mpfr_t input) {
    std::vector<int> digits{};
    mpfr_t scaled_input, temp;
    mpfr_init2(scaled_input, 8192);
    mpfr_init2(temp, 8192);

    mpfr_mul_ui(scaled_input, input, 10, MPFR_RNDN);

    for (int i = 0; i < 2000; i++) {
        mpfr_floor(temp, scaled_input);
        int firstDigit = mpfr_get_si(temp, MPFR_RNDN);
        digits.push_back(firstDigit);
        mpfr_sub_ui(scaled_input, scaled_input, firstDigit, MPFR_RNDN);
        mpfr_mul_ui(scaled_input, scaled_input, 10, MPFR_RNDN);
    }
    mpfr_clear(scaled_input);
    mpfr_clear(temp);
    return digits;
}

int main() {

    std::pair<int, int> longestCycle{1, 1};

    mpfr_t one, divisor, result;
    mpfr_init2(one, 8192);
    mpfr_init2(divisor, 8192);
    mpfr_init2(result, 8192);

    mpfr_set_d(one, 1.0, MPFR_RNDD);

    for (int num = 2; num < 1000; num++) {
        double dNum = num * 1.0;
        mpfr_set_d(divisor, dNum, MPFR_RNDD);
        mpfr_div(result, one, divisor, MPFR_RNDD);

        std::vector<int> divDigits = convertToDigitVector(result);

        bool tooMuchConsecutiveDigits = false;
        int consecutiveCount = 1;
        for (size_t i = 1; i < divDigits.size(); i++) {
            if (divDigits[i] == divDigits[i - 1]) {
                consecutiveCount++;
                if (consecutiveCount == 5) {
                    tooMuchConsecutiveDigits = true;
                    break;
                }
            } else {
                consecutiveCount = 1;
            }
        }

        if (tooMuchConsecutiveDigits) {
            continue;
        }

        std::map<int, int> cycleLengths;
        for (int cyclen = 5; cyclen < 1000; cyclen++) {
            for (int offset = 0; offset <= 5; offset++) {
                int numOfValidJumps = 0;
                for (int i = 0; i < cyclen + 1; i++) {
                    if (offset + i + cyclen < divDigits.size()) {
                        if (divDigits[offset + i] == divDigits[offset + i + cyclen]) {
                            numOfValidJumps++;
                        }
                    }
                    if (numOfValidJumps == cyclen) {
                        if (cycleLengths.contains(cyclen)) {
                            cycleLengths[cyclen]++;
                            if (cycleLengths[cyclen] == 2) {
                                if (cyclen > longestCycle.first) {
                                    //std::cout << "New longest cycle: Len: " << cyclen << " for: " << num << std::endl;
                                    longestCycle.first = cyclen;
                                    longestCycle.second = num;
                                }
                                goto endOfSearch;
                            }
                        } else {
                            cycleLengths[cyclen] = 1;
                        }
                    }
                }
            }
        }
    endOfSearch:
        std::cout << "";
    }

    std::cout << "Longest cycle: " << longestCycle.first << " for 1/" << longestCycle.second << std::endl;

    mpfr_clear(one);
    mpfr_clear(divisor);
    mpfr_clear(result);

    return 0;
}
