//
// Created by ghisl on 08/09/2024.
//

#ifndef PRIMEFUNCTIONS_H
#define PRIMEFUNCTIONS_H
#include <vector>

bool isPrime(int64_t n);
std::vector<int> simple_sieve(int limit);
void segmented_sieve(int limit);

#endif //PRIMEFUNCTIONS_H
