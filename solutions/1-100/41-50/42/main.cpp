#include <iostream>

#include "helperFunctions/fileParsing.h"
#include "helperFunctions/listsGeneration.h"
#include "helperFunctions/stringOperations.h"

int main() {

    std::set<int> triangularNumbers = generateSetOfNFirstTriangularNumbers(33);

    std::string filename = "42.txt";
    std::vector<std::string> words = parseWordArrayFromFile(filename);
    int triangularWordsCount { 0 };

    for(auto& word : words) {
        if(triangularNumbers.contains(getSumOfAlphabeticalIndexes(word))) {
            triangularWordsCount++;
        }
    }

    std::cout << "Number of triangular numbers in file: " << triangularWordsCount << std::endl;


    return 0;
}
