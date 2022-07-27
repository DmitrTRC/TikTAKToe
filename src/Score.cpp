//
// Created by Dmitry Morozov on 19/7/22.
//

#include "Score.hpp"



std::ostream &operator<< (std::ostream &os, const Score &score) {
    os << "Name: " << score.name_ << std::endl;
    os << "Wins: " << score.wins_ << std::endl;
    os << "Loses: " << score.loses_ << std::endl;
    os << "Draws: " << score.draws_ << std::endl;
    return os;
}

Score::Score () {
    name_ = "Unknown";
    wins_ = 0;
    loses_ = 0;
    draws_ = 0;

}

auto Score::getScore () {
    return std::make_tuple (name_, wins_, loses_, draws_);
}

void Score::setScore (const std::string &name, ScoreType score) {
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
    }

}