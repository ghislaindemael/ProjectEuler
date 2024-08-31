#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {

    std::string inputFileName = "P22_names.txt";

    std::ifstream inputFile(inputFileName);
    std::vector<std::vector<int>> numTriangle;
    std::string line;
    std::getline(inputFile, line);
    line.push_back(',');

    std::vector<std::string> names;
    std::string currentName {};

    for(char c : line) {
        if(c == ',') {
            names.push_back(currentName);
            currentName = "";
        }
        if(isalnum(c)) {
            currentName += c;
        }
    }

    std::sort(names.begin(), names.end());

    int64_t sumOfScores = 0;

    for(int i = 0; i < names.size(); i++) {
        int sumOfChars = 0;
        for(char c : names[i]) {
            sumOfChars += int(c) - 64;
        }
        sumOfScores += (i + 1) * sumOfChars;
    }

    std::cout << "Sum of name scores: " << sumOfScores << std::endl;

    return 0;
}

