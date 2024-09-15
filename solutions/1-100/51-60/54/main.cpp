#include <algorithm>
#include <functional>
#include <iostream>

#include "54.h"
#include "libraries/bigint.h"
#include "utils/fileParsing.h"
#include "utils//listsGeneration.h"
#include "utils/numberOperations.h"
#include "utils/stringOperations.h"



int main() {
    //std::ifstream file("54.txt");
    std::ifstream file("54.txt");
    int playerOneWins = 0;
    Hand p1Hand(5);
    Hand p2Hand(5);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string card;

        int cardCount = 0;

        while (std::getline(iss, card, ' ')) {
            if (cardCount < 5) {
                p1Hand[cardCount] = Card(card);
            } else if (cardCount < 10) {
                p2Hand[cardCount - 5] = Card(card);
            } else {
                break;
            }
            cardCount++;
        }

        // Process the cards
        if (calculateWinner(p1Hand, p2Hand) == 1) {
            //std::cout << "Player 1 wins round :" << line << std::endl;
            playerOneWins++;
        }
    }

    file.close();

    std::cout << "Player 1 won " << playerOneWins << " rounds." << std::endl;

    return 0;
}
