
//
// Created by Dmitry Morozov on 2/6/22.
//

#include "Player.hpp"
#include "Board.hpp"

#include <iostream>
#include <utility>



Player::Player () : score_ (0, 0, 0) {
//    std::cout << "class Player constructor is running" << std::endl;
    Name_ = "Unknown";
}


std::string Player::getName () {
    return Name_;
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



