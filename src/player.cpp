
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

char Player::getMark () {

    return mark_;
}

void Player::setMark (char mark) {
    mark_ = mark;

}

//TODO: Implement the method engageMove (const Board &board)
int HumanPlayer::engageMove (const Board &board) {
    int position;
    std::cout << "Enter position: ";
    std::cin >> position;
    while (!board.isValidPosition(position)) {
        std::cout << "Invalid position. Try again: ";
        std::cin >> position;
    }
    return position;
}

HumanPlayer::HumanPlayer (const std::string &name) {
    std::cout << "class HumanPlayer constructor is running" << std::endl;
    setName(name);
}


int AIPlayer::engageMove (const Board &board) {
    std::cout << "AIPlayer engageMove is running" << std::endl;
    int move = 5;
    return move;
}

