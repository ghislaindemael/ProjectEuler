#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

int main() {

    std::ifstream inputFile("13.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::string line;
    int64_t sum = 0;

    while (std::getline(inputFile, line)) {
        std::string firstDigits = line.substr(0, 11);
        try {
            sum += std::stoll(firstDigits);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number format: " << firstDigits << std::endl;
        }
    }

    inputFile.close();

    std::cout << "First 10 digits of sum: " << std::to_string(sum).substr(0, 10) << std::endl;


}
