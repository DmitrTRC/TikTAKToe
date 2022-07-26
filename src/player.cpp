
//
// Created by Dmitry Morozov on 2/6/22.
//

#include "player.hpp"
#include "Board.hpp"

#include <iostream>
#include <utility>

#include "Score.hpp"


Player::Player () {
    std::cout << "class Player constructor is running" << std::endl;
    score_ = Score ();
    Name_ = "Unknown";
}


std::string Player::getName () {
    return Name_;
}

void Player::addScore (ScoreType score) {
    switch (score) {
        case ScoreType::Win:
            score_.wins_++;
            break;
        case ScoreType::Lose:
            Score_--;
            break;
        case ScoreType::Draw:
            Score_ = Score_;
            break;
    }

}


void Player::setName (const std::string &name) {
    Name_ = name;
}

char Player::getMark () const {

    return mark_;
}

void Player::setMark (char mark) {
    mark_ = mark;

}

int HumanPlayer::InputNextMove () {
    int number{0};
    std::cout << "Enter your move number from 1 to 9 : ";
    std::cin >> number;
    return number;
}

int HumanPlayer::engageMove (const Board &board) {
    return InputNextMove ();

}

HumanPlayer::HumanPlayer (const std::string &name) {
    std::cout << "class HumanPlayer constructor is running" << std::endl;
    setName (name);
}


