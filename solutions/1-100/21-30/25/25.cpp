//
// Created by ghisl on 01/09/2024.
//

#include "25.h"

void addLeadingZeroIfNeeded(std::vector<int> &vector) {
    if (vector[0] != 0) {
        vector.insert(vector.begin(), 0);
    }
}

void addLeadingZeroesUntilSize(std::vector<int> &vector, int size) {
    while (vector.size() < size) {
        vector.insert(vector.begin(), 0);
    }
}