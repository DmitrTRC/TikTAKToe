
//
// Created by Dmitry Morozov on 2/6/22.
//

#include "player.hpp"

#include <iostream>


Player::Player () {
    std::cout << "class Player constructor is running" << std::endl;
    Score_ = 0;
    Name_ = "Unknown";
}

std::string Player::getName () {
    return Name_;
}

void Player::setName (std::string name) {
    Name_ = name;
}

int HumanPlayer::engageMove () {
    std::cout << "HumanPlayer engageMove is running" << std::endl;
    int move;
    std::cout << "Enter your move: ";
    std::cin >> move;
    return move;
}

//HumanPlayer::HumanPlayer () {
//    std::cout << "class HumanPlayer constructor is running" << std::endl;
//     setName( "Dmitry" );
//
//
//}

int AIPlayer::engageMove () {
    std::cout << "AIPlayer engageMove is running" << std::endl;
    int move = 5;
    return move;
}

void HumanPlayer::WhoFirst (){
    std::cout<<"HumanPlayer WhoFirst is running"<<std::endl;
}

void AIPlayer::WhoFirst (){
    std::cout<<"AIPlayerWhoFirst is running"<<std::endl;
}
