#include <vector>
#include <iostream>

#include "18.h"



int main() {
    std::string inputFilename = "18.txt";
    std::string outputFilename = "18r.txt";
    rotateTriangleInFile(inputFilename, outputFilename);

    auto triangle = extractTriangleFromFile("18r.txt");

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            int val = triangle[i][j].value;
            if(val > 0) {
                std::cout << val << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            if(i == 0 && j == 0) {
                triangle[0][0].maxValue = triangle[0][0].value;
            } else if(i == 0 && j > 0) {
                triangle[i][j].maxValue = triangle[i][j].value + triangle[i][j-1].maxValue;
            } else if(j == 0 && i > 0) {
                triangle[i][j].maxValue = triangle[i][j].value + triangle[i-1][j].maxValue;
            } else if(i + j < 15) {
                int biggestNeighbour = std::max(triangle[i-1][j].maxValue, triangle[i][j-1].maxValue);
                triangle[i][j].maxValue = triangle[i][j].value + biggestNeighbour;
            }
        }

    }

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            int mval = triangle[i][j].maxValue;
            if(mval > 0) {
                std::cout << mval << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int greatestNum = 0;

    for(int i = 0; i < 15; i++) {
        if(triangle[i][15 - 1 - i].maxValue > greatestNum) {
            greatestNum = triangle[i][15 - 1 - i].maxValue;
        }
    }

    std::cout << "Greatest sum at end of triangle: " << greatestNum << std::endl;


    return 0;
}

