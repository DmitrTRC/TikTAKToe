//
// Created by Dmitry Morozov on 27/7/22.
//

#include "Human_Player.hpp"


int HumanPlayer::InputNextMove () {
    int number{0};
    std::cout << "Enter your move number from 1 to 9 : ";
    std::cin >> number;
    return number;
}

int HumanPlayer::engageMove (const Board &board) {
    return InputNextMove ();

}

HumanPlayer::HumanPlayer()= default;
HumanPlayer::HumanPlayer (const std::string &name) {
    std::cout << "class HumanPlayer constructor with parameter is running" << std::endl;
    setName (name);
}
