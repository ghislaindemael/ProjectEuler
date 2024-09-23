#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>

#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/primeFunctions.h"
#include "utils/stringOperations.h"


int main() {

    std::vector<uint8_t> ciphertext {};
    std::ifstream file("P59.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return {};
    }

    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    std::string number;
    while (std::getline(iss, number, ',')) {
        ciphertext.push_back(static_cast<uint8_t>(std::stoi(number)));
    }
    file.close();

    std::vector<std::string> wordsToCheck = {" the ", " be ", " to ", " of ", " and "};

    for(char i = 'a'; i <= 'z'; i++) {
        for(char j = 'a'; j <= 'z'; j++) {
            for(char k = 'a'; k <= 'z'; k++) {
                bool valid = true;
                char key[]{i, j, k};
                std::string decipherAttempt;
                for(int l = 0; l < ciphertext.size(); l++) {
                    uint8_t decrypted = ciphertext[l] ^ key[l % 3];
                    if(decrypted >= 32 && decrypted <= 122) {
                        decipherAttempt += decrypted;
                    } else {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    for (const auto& word : wordsToCheck) {
                        if (decipherAttempt.find(word) != std::string::npos) {
                            std::cout << decipherAttempt << std::endl;
                            break;
                        }
                    }

                }
            }
        }
    }

    return EXIT_SUCCESS;
}
