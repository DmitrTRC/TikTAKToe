//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"


Board::Board () {
    std::cout << "class Board constructor is running" << std::endl;

}

void Board::setPosition (int position, char mark) {
    std::cout << "SetPosition" << std::endl;
}

void Board::PrintBoard () {
    std::cout << "PrintBoard" << std::endl;
}

void Board::ClearBoard () {
    std::cout << "ClearBoard" << std::endl;
}

//FIX:  ( Replace True with true)
bool Board::isFull () {
    std::cout << "IsFull";
    return true;
}

//FIX:  ( Replace True with true)
bool Board::isFree (int position) {
    std::cout << "IsFree";
    return true;
}
