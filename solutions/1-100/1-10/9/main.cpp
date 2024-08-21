#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {

    int triplet[] = {0, 0, 0};

    for(int i = 0; i <= 999; i++) {
        for(int j = i + 1; j <= 999; j++) {
            for(int k = j + 1; k <= 999; k++) {
                if(i*i + j*j == k*k) {
                    if(i + j + k == 1000) {
                        triplet[0] = i;
                        triplet[1] = j;
                        triplet[2] = k;
                        goto end;
                    }
                }
            }
        }
    }
    end:

    std::cout << "Special triplet : " << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << std::endl;
    int tripletProduct = triplet[0] * triplet[1] * triplet[2];
    std::cout << "Triplet product: " << tripletProduct << std::endl;

    return EXIT_SUCCESS;

}
