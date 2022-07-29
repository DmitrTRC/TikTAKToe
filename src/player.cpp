
//
// Created by Dmitry Morozov on 2/6/22.
//#include "player.hpp"
//#include "Board.hpp"
//

//#include <utility>

#include "player.hpp"

#include <iostream>


Player::Player () {
    std::cout << "class Player constructor is running" << std::endl;
    Score_ = 0;
    Name_ = "Unknown";
}


std::string Player::getPassword(){
    return Password_;
}
void Player::setPassword(std::string password){
    Password_=password;
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


