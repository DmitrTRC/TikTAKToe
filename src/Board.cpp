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
//FIXME: cout : is the member of the std namespace. Use std::cout instead or using std::cout
void Board::PrintBoard () { // Ok! Everything is correct
    std::cout << "    |     | \n "; //Better way to use std::endl.
    std::cout << positions_[1] << "  | " <<positions_[2] << "   | " << positions_[3] << " \n";
    std::cout << " ---|-----|--- \n";
    std::cout << " " << positions_[4] << "  |" << positions_[5] << "    |" << positions_[6] << " \n";
    std::cout << "    |     | \n ";
    std::cout << "---|-----|---  \n";
    std::cout << " " << positions_[7] << "  | " << positions_[8] << "   | " << positions_[9] << " \n";
    std::cout << "    |     | \n ";
}

//TODO: Implement method
//FIXME: The same issue : positions_ : Member of class Board
void Board::ClearBoard () { // Fill positions with empty characters
//    
    for (int i=0;i<positions_.size();i++){
        positions_[i]=' ';
    }
}

//TODO: Implement method
bool Board::isFull(){
    for (auto &i:positions_)
    if (i!=' ')return false;
    return true;
}

//TODO: Implement method
bool Board::isFree (int position) {
    //FIXME: We do not need iterate over the all positions_ array. Just check the position that we want to check
if (positions_[position]==' ')
    return true;
    else
    return false;
}
