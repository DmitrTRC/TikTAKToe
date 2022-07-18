
//
// Created by Dmitry Morozov on 2/6/22.
//

#include "player.hpp"
#include "Board.hpp"

#include <iostream>
#include <utility>


Player::Player () {
    std::cout << "class Player constructor is running" << std::endl;
    Score_ = 0;
    Name_ = "Unknown";
}


std::string Player::getName () {
    return Name_;
}

void Player::addWin () {
    Score_++;
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


// Calculate the best move for the AI player.

