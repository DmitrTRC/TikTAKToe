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
void Board::ClearBoard () { // Fill positions with empty characters
//    
    for (int i=0;i<positions_.size();i++){
        positions_[i]=' ';
    }
}

//TODO: Implement method
bool Board::isFull () {
    int count=0;
    for (int i=0;i<board.size();i++){
        //FIXME:
        //  board : is not a member of class Board . The size of the board is in the k_board_size constant
        // You have to iterate over the positions_ array remembering to start from 1 and up to k_board_size included
        if (board[i]!=' ')
        count+=1;
    }
    if (count!=0){
    return false;
        
    }
    else {
        return true;
    }
   }
}

//TODO: Implement method
bool Board::isFree (int position) {
    //FIXME: We do not need iterate over the all positions_ array. Just check the position that we want to check
    for (int i=0;i<positions_.size();i++){
        // FIXME: Check variable names!
        if (positions[position_]==' ')
        return true;
        else
            return false;
    }
}
