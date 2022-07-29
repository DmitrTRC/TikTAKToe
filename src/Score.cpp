//
// Created by Dmitry Morozov on 19/7/22.
//

#include "Score.hpp"
#include <fstream>


std::ostream &operator<< (std::ostream &os, const Score &score) {
    os << "Wins: " << score.wins_ << std::endl;
    os << "Loses: " << score.loses_ << std::endl;
    os << "Draws: " << score.draws_ << std::endl;
    return os;
}

Score::Score () = default;


Score::Score (int wins, int loses, int draws) {
    wins_ = wins;
    loses_ = loses;
    draws_ = draws;
}

std::tuple<int, int, int> Score::getScore () {
    return std::make_tuple (wins_, loses_, draws_);
}

void Score::setScore (ScoreType score) {
    switch (score) {
        case ScoreType::Win:
            wins_++;
            break;
        case ScoreType::Lose:
            loses_++;
            break;
        case ScoreType::Draw:
            draws_++;
            break;
        default:
            std::cout << "Score type is not supported" << std::endl;
            break;
    }

}

