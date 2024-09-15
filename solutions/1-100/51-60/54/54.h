//
// Created by ghisl on 15/09/2024.
//

#ifndef INC_54_H
#define INC_54_H
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Score {
    int score = 0;
    std::vector<int> extraCards = {};

    Score() = default;
};

struct Card {
    int rank = 0;
    char suit = 'X';

    Card() = default;

    explicit Card(const std::string& input) {
        switch (input[0]) {
            case 'T':
                rank = 10;
                break;
            case 'J':
                rank = 11;
                break;
            case 'Q':
                rank = 12;
                break;
            case 'K':
                rank = 13;
                break;
            case 'A':
                rank = 14;
                break;
            default:
                rank = input[0] - 48;
        }
        suit = input[1];
    }
};

typedef std::vector<Card> Hand;

Score getStraightFlushScore(const Hand& hand);

Score getFourAKindScore(const Hand& hand);

Score getFullHouseScore(const Hand& hand);

Score getFlushScore(const Hand& hand);

Score getStraightScore(const Hand& hand);

Score getThreeAKindScore(const Hand& hand);

Score getTwoPairsScore(const Hand& hand);

Score getPairScore(const Hand& hand);

Score evaluateHand(const Hand& hand);

int calculateWinner(const Hand& p1Hand, const Hand& p2Hand);

#endif //INC_54_H
