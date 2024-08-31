//
// Created by ghisl on 31/08/2024.
//

#include "21.h"

int sumOfDivisors(int num) {
    int sum = 0;

    for(int i = 1; i <= num / 2; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }

    return sum;

}