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
    positions_[position] = mark;
}


void Board::PrintBoard () { // Ok! Everything is correct
    //TODO: Refactor this way to make it more readable
    //FIXME: You can not return int from void function!
    //FIXME: Still has " \n" at the end of strings! (Replace to endl )

    std::cout << "    |     |   " << std::endl; //Better way to use std::endl.
    std::cout << positions_[1] << "  | " << positions_[2] << "   | " << positions_[3] << " \n";
    std::cout << " ---|-----|--- " << std::endl;
    std::cout << " " << positions_[4] << "  |" << positions_[5] << "    |" << positions_[6] << " \n";
    std::cout << "    |     |  " << std::endl;
    std::cout << " ---|-----|---  " << std::endl;
    std::cout << " " << positions_[7] << "  | " << positions_[8] << "   | " << positions_[9] << " \n";
    std::cout << "    |     |" << std::endl;


}


void Board::ClearBoard () { // Fill positions with empty characters
//    
    for (int i = 0; i < positions_.size (); i++) {
        positions_[i] = ' ';
    }
//    positions_.fill (' ');
}

//TODO: Implement method

bool Board::isFull () {
    for (const auto &i: positions_) {

        if (i != ' ') { //FIXME: Check the logic!
            return false;
        }
    }

    return true;


//    return std::any_of (positions_.begin (), positions_.end (), [] (char c) { return c == ' '; });
}



//Correct!
bool Board::isFree (int position) {
    return positions_[position] == ' ';
}
