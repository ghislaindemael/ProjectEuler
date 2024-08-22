#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int main() {

    std::ifstream inputFile("11.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::vector<int> digits;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            try {
                int number = std::stoi(token);
                digits.push_back(number);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number format: " << token << std::endl;
            }
        }
    }

    inputFile.close();

    std::vector<std::vector<int64_t>> numberGrid(20, std::vector<int64_t>(20));

    int index = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            numberGrid[i][j] = digits[index++];
        }
    }
    
    int64_t greatestProduct = 0;

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {

            int64_t product = 1;
            //Horizontal
            if(j <= 16) {
                product = 1;
                for(int k = j; k < j + 4; k++) {
                    product *= numberGrid[i][k];
                }
                if(product > greatestProduct) {
                    std::cout << "Greatest prod (" << product << ") at " << i << " " << j << " horizontally" << std::endl;
                    greatestProduct = product;
                }
            }

            //Vertical
            if(i <= 16) {
                product = 1;
                for(int k = i; k < i + 4; k++) {
                    product *= numberGrid[k][j];
                }
                if(product > greatestProduct) {
                    std::cout << "Greatest prod (" << product << ") at " << i << " " << j << " vertically" << std::endl;
                    greatestProduct = product;
                }
            }

            //Diagonal 2SE
            if(i <= 16 && j <= 16) {
                product = 1;
                for(int k = 0; k < 4; k++) {
                    product *= numberGrid[i + k][j + k];
                }
                if(product > greatestProduct) {
                    std::cout << "Greatest prod (" << product << ") at " << i << " " << j << "on diagonal 2SE" << std::endl;
                    greatestProduct = product;
                }
            }

            //Diagonal 2NE
            if(i >= 3 && j <= 16) {
                product = 1;
                for(int k = 0; k < 4; k++) {
                    product *= numberGrid[i - k][j + k];
                }
                if(product > greatestProduct) {
                    std::cout << "Greatest prod (" << product << ") at " << i << " " << j << " on diagonal 2NE" << std::endl;
                    greatestProduct = product;
                }
            }

        }
    }

    std::cout << "Greatest 4-number product: " << greatestProduct << std::endl;

    


    return EXIT_SUCCESS;

}
