#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main() {
    std::set<int> primes;
    std::ifstream file("primes1000000.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string number;

        while (std::getline(iss, number, ',')) {
            primes.insert(std::stoi(number));
        }
    }

    file.close();

    int biggestabn[]{0, 0, 0};

    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            for (int n = 0; n <= 500; n++) {
                if (!primes.contains((n * n) + (a * n) + b)) {
                    if (n > biggestabn[2]) {
                        std::cout << "Biggest n: " << n << std::endl;
                        std::cout << "a: " << a << " b: " << b << " n: " << n << std::endl;
                        biggestabn[2] = n;
                        biggestabn[0] = a;
                        biggestabn[1] = b;
                    }
                    break;
                }
            }
        }
    }

    std::cout << "Biggest sequence is " << biggestabn[2] << " primes, for a: " << biggestabn[0] << ", b: "
            << biggestabn[1] << std::endl;

    return 0;
}
