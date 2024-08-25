//
// Created by ghisl on 25/08/2024.
//

#ifndef INC_18_H
#define INC_18_H
#include <string>
#include <vector>

struct Cell {
    int x = 0;
    int y = 0;
    int value = 0;
    int maxValue = 0;
    bool fixed = false;
    Cell() = default;
    Cell(int inX, int inY, int inValue) {
        x = inX;
        y = inY;
        value = inValue;
    }
};

void rotateTriangleInFile(const std::string& inputFilename, const std::string& outputFilename);
std::vector<std::vector<Cell>> extractTriangleFromFile( const std::string& inputFilename);

#endif //INC_18_H
