//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"


Board::Board () {
    std::cout << "class Board constructor is running" << std::endl;

}

//FIXME: Implement class Board
void Board::setPosition (int position, char mark) {
    std::cout << "SetPosition" << std::endl;
        positions_[position] = mark;
}

//TODO: Draw the board with the current state of the game
//FIXME: positions_ : Member of class Board!
void Board::PrintBoard (positions_) { // Look at method declaration!  void Board::PrintBoard ()
    cout << "    |     | \n "; //Better way to use std::endl.
    cout << positions_[1] << "  | " <<positions_[2] << "   | " << positions_[3] << " \n";
    cout << " ---|-----|--- \n";
    cout << " " << positions_[4] << "  |" << positions_[5] << "    |" << positions_[6] << " \n";
    cout << "    |     | \n ";
    cout << "---|-----|---  \n";
    cout << " " << positions_[7] << "  | " << positions_[8] << "   | " << positions_[9] << " \n";
    cout << "    |     | \n ";
}

//TODO: Implement method
//FIXME: The same issue : positions_ : Member of class Board
void Board::ClearBoard (positions_) { // Fill positions with empty characters
//    
    for (int i=0;i<positions_.size();i++){
        positions_[i]=' ';
    }
}

//TODO: Implement method
bool Board::isFull () {
    std::cout << "IsFull";
    return true;
}

//TODO: Implement method
bool Board::isFree (int position) {
    std::cout << "IsFree";
    return true;
}
