//
// Created by ghisl on 15/09/2024.
//

#include "54.h"

Score getStraightFlushScore(const Hand &hand) {
    Score score{};
    char suit = hand[0].suit;
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
        if (card.suit != suit) {
            return score;
        }
    }
    //std::cout << "All suits the same." << std::endl;
    std::ranges::sort(ranks);
    if (ranks[4] == ranks[3] + 1 && ranks[4] == ranks[2] + 2 && ranks[4] == ranks[1] + 3 && ranks[4] == ranks[0] + 4) {
        score.score = 1000 + ranks[4];
    }
    return score;
}

Score getFourAKindScore(const Hand &hand) {
    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    if (ranks[0] == ranks[1] && ranks[0] == ranks[2] && ranks[0] == ranks[3]) {
        score.score = 900 + ranks[0];
    }
    if (ranks[1] == ranks[2] && ranks[1] == ranks[3] && ranks[1] == ranks[4]) {
        score.score = 900 + ranks[1];
    }
    return score;
}

Score getFullHouseScore(const Hand &hand) {
    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    if (ranks[0] == ranks[1] && ranks[0] == ranks[2] && ranks[3] == ranks[4]) {
        score.score = 700 + 10 * ranks[0] + ranks[3];
    }
    if (ranks[0] == ranks[1] && ranks[2] == ranks[3] && ranks[2] == ranks[4]) {
        score.score = 700 + 10 * ranks[2] + ranks[0];
    }
    return score;
}

Score getFlushScore(const Hand &hand) {
    Score score{};
    char suit = hand[0].suit;
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
        if (card.suit != suit) {
            return score;
        }
    }
    std::ranges::sort(ranks);
    score.score = 600 + ranks[4];
    score.extraCards = {ranks[0], ranks[1], ranks[2], ranks[3]};
    return score;
}

Score getStraightScore(const Hand &hand) {
    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    if (ranks[4] == ranks[3] + 1 && ranks[4] == ranks[2] + 2 && ranks[4] == ranks[1] + 3 && ranks[4] == ranks[0] + 4) {
        score.score = 500 + ranks[4];
    }
    return score;
}

Score getThreeAKindScore(const Hand &hand) {
    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    if (ranks[0] == ranks[1] && ranks[0] == ranks[2]) {
        score.score = 400 + ranks[0];
        score.extraCards.push_back(ranks[3]);
        score.extraCards.push_back(ranks[4]);
    }
    if (ranks[1] == ranks[2] && ranks[1] == ranks[3]) {
        score.score = 400 + ranks[1];
        score.extraCards.push_back(ranks[0]);
        score.extraCards.push_back(ranks[4]);
    }
    if (ranks[2] == ranks[3] && ranks[2] == ranks[4]) {
        score.score = 400 + ranks[2];
        score.extraCards.push_back(ranks[0]);
        score.extraCards.push_back(ranks[1]);
    }
    return score;
}

Score getTwoPairsScore(const Hand &hand) {
    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    if (ranks[0] == ranks[1] && ranks[2] == ranks[3]) {
        score.score = 200 + 10 * ranks[2] + ranks[0];
        score.extraCards.push_back(ranks[4]);
    }
    if (ranks[0] == ranks[1] && ranks[3] == ranks[4]) {
        score.score = 200 + 10 * ranks[3] + ranks[0];
        score.extraCards.push_back(ranks[2]);
    }
    if (ranks[1] == ranks[2] && ranks[3] == ranks[4]) {
        score.score = 200 + 10 * ranks[3] + ranks[1];
        score.extraCards.push_back(ranks[0]);
    }
    return score;
}

Score getPairScore(const Hand &hand) {
    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    for (size_t i = 0; i < ranks.size() - 1; ++i) {
        if (ranks[i] == ranks[i + 1]) {
            score.score = 100 + ranks[i];
            break;
        }
    }

    for (const auto &rank : ranks) {
        if (rank != score.score - 100) {
            score.extraCards.push_back(rank);
        }
    }
    return score;
}

void printHand(const Hand &hand) {
    std::cout << "Hand: ";
    for (auto &card: hand) {
        std::cout << card.rank << card.suit << " ";
    }
    std::cout << std::endl;
}

Score evaluateHand(const Hand &hand) {

    if (Score straightFlushCore = getStraightFlushScore(hand); straightFlushCore.score > 0) {
        //std::cout << "Got a straight flush." << std::endl;
        return straightFlushCore;
    }

    if (Score fourAKindScore = getFourAKindScore(hand); fourAKindScore.score > 0) {
        //std::cout << "Got a four of a kind." << std::endl;
        return fourAKindScore;
    }

    if (Score fullHouseScore = getFullHouseScore(hand); fullHouseScore.score > 0) {
        //std::cout << "Got full house" << std::endl;
        return fullHouseScore;
    }

    if (Score flushScore = getFlushScore(hand); flushScore.score > 0) {
        //std::cout << "Got flush" << std::endl;
        return flushScore;
    }

    if(Score straightScore = getStraightScore(hand); straightScore.score > 0) {
        //std::cout << "Got straight" << std::endl;
        return straightScore;
    }

    if(Score threeAKindScore = getThreeAKindScore(hand); threeAKindScore.score > 0) {
        //std::cout << "Got 3 a kind << std::endl;
        return threeAKindScore;
    }

    if(Score twoPairScore = getTwoPairsScore(hand); twoPairScore.score > 0) {
        //std::cout << "Got 2 pairs << std::endl;
        return twoPairScore;
    }

    if(Score pairScore = getPairScore(hand); pairScore.score > 0) {
        //std::cout << "Got pair" << std::endl;
        return pairScore;
    }

    Score score{};
    std::vector<int> ranks;
    for (auto &card: hand) {
        ranks.push_back(card.rank);
    }
    std::ranges::sort(ranks);
    score.score = ranks[4];
    score.extraCards = {ranks[0], ranks[1], ranks[2], ranks[3]};
    return score;

}

int calculateWinner(const Hand &p1Hand, const Hand &p2Hand) {
    Score playerOneScore = evaluateHand(p1Hand);
    Score playerTwoScore = evaluateHand(p2Hand);
    if (playerOneScore.score > playerTwoScore.score) {
        return 1;
    }
    if (playerTwoScore.score > playerOneScore.score) {
        return 2;
    }
    //std::cout << "Tie on score : " << playerOneScore.score <<". Comparing extra cards." << std::endl;
    while(!playerOneScore.extraCards.empty()) {
        if(playerOneScore.extraCards.back() > playerTwoScore.extraCards.back()) {
            return 1;
        }
        if (playerTwoScore.extraCards.back() > playerOneScore.extraCards.back()) {
            return 2;
        }
        playerOneScore.extraCards.pop_back();
        playerTwoScore.extraCards.pop_back();
    }
    return 0;
}
