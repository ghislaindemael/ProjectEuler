#include <iostream>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include "solutions/1-100/11-20/18/18.h"

int main() {
    std::string inputFilename = "P67.txt";
    std::string outputFilename = "P67r.txt";
    rotateTriangleInFile(inputFilename, outputFilename);

    constexpr int triangleSize = 100;

    auto triangle = extractTriangleFromFile("P67r.txt");

    for(int i = 0; i < triangleSize; i++) {
        for(int j = 0; j < triangleSize; j++) {
            if(i == 0 && j == 0) {
                triangle[0][0].maxValue = triangle[0][0].value;
            } else if(i == 0 && j > 0) {
                triangle[i][j].maxValue = triangle[i][j].value + triangle[i][j-1].maxValue;
            } else if(j == 0 && i > 0) {
                triangle[i][j].maxValue = triangle[i][j].value + triangle[i-1][j].maxValue;
            } else if(i + j < triangleSize) {
                int biggestNeighbour = std::max(triangle[i-1][j].maxValue, triangle[i][j-1].maxValue);
                triangle[i][j].maxValue = triangle[i][j].value + biggestNeighbour;
            }
        }

    }

    int greatestNum = 0;

    for(int i = 0; i < triangleSize; i++) {
        greatestNum = std::max(greatestNum, triangle[i][triangleSize - 1 - i].maxValue);
    }

    std::cout << "Greatest sum at end of triangle: " << greatestNum << std::endl;


    return 0;
}
