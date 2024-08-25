#include <vector>
#include <iostream>


int main() {

    std::vector<int> digits = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6
    };

    std::vector<int> mults10 = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6
    };

    int64_t numOfLetters = 0;

    for(int i = 1; i <= 999; i++) {

        int rem100 = i % 100;
        int div100 = i / 100;
        int tens = rem100 / 10;
        int units = i % 10;

        if(rem100 < 20) {
            numOfLetters += digits[i % 100];
        }

        if(tens >= 2) {
            numOfLetters += mults10[tens] + digits[units];
        }

        if(div100 > 0) {
            numOfLetters += digits[div100] + 7;
            if(rem100 != 0) {
                numOfLetters += 3;
            }
        }

    }

    //One thousand
    numOfLetters += 11;

    std::cout << "Num of letters for 1 to 1000: " << numOfLetters << std::endl;;

    return 0;
}
