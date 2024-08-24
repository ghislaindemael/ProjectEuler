#include <vector>
#include <iostream>

struct Cell {
    int x = 0;
    int y = 0;
    int64_t pathsTo = 0;
    Cell() = default;
    Cell(int inX, int inY, bool border) {
        x = inX;
        y = inY;
        pathsTo = border ? 1 : 0;
    }
};


int main() {

    int size = 20;
    size++;

    std::vector<std::vector<Cell>> grid(size, std::vector<Cell>(size));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            grid[i][j] = Cell(i, j, i == 0 || j == 0);
        }
    }

    for(int i = 1; i < size; i++) {
        for(int j = 1; j < size; j++) {
            grid[i][j].pathsTo = grid[i][j-1].pathsTo + grid[i-1][j].pathsTo;
        }
    }

    std::cout << "Paths to bottom corner: " << grid[size - 1][size - 1].pathsTo << std::endl;

    return 0;
}
