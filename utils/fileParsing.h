//
// Created by ghisl on 07/09/2024.
//

#ifndef FILEPARSING_H
#define FILEPARSING_H
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::set<std::string> parsePrimeSetFromFile(const std::string& filename);
std::vector<std::string> parsePrimeVectorFromFile(const std::string& filename);
std::vector<int64_t> parsePrimeIntVectorFromFile(const std::string& filename);
std::vector<std::string> parseWordArrayFromFile(const std::string &filename);

#endif //FILEPARSING_H
