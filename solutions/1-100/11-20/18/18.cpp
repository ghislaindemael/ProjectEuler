//
// Created by ghisl on 25/08/2024.
//

#include "18.h"

#include <fstream>
#include <sstream>
#include <vector>

void rotateTriangleInFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::vector<std::vector<int>> triangle;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        triangle.push_back(row);
    }

    inputFile.close();

    int maxSize = triangle.size();
    std::vector<std::vector<int>> rotatedTriangle(maxSize);

    for (int i = 0; i < maxSize; ++i) {
        for (int j = 0; j < maxSize - i; ++j) {
            rotatedTriangle[j].push_back(triangle[maxSize - i - 1][maxSize - i - j - 1]);
        }
    }

    for (auto& row : rotatedTriangle) {
        std::reverse(row.begin(), row.end());
    }

    std::ofstream outputFile(outputFilename);

    for (const auto& row : rotatedTriangle) {
        for (int num : row) {
            outputFile << num << " ";
        }
        outputFile << "\n";
    }

    outputFile.close();
}

std::vector<std::vector<Cell>> extractTriangleFromFile( const std::string& inputFilename) {
    std::ifstream inputFile(inputFilename);
    std::vector<std::vector<int>> numTriangle;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        numTriangle.push_back(row);
    }

    int size = numTriangle.size();
    std::vector<std::vector<Cell>> cellTriangle(size, std::vector<Cell>(size));


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(i + j < size) {
                cellTriangle[i][j].value = numTriangle[i][j];
            }
        }
    }

    return cellTriangle;

}
