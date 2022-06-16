//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"


Board::Board () {
    std::cout << "class Board constructor is running" << std::endl;

}

//TODO: Implement method
void Board::setPosition (int position, char mark) {
    std::cout << "SetPosition" << std::endl;
    if (mark == 'x'){
         Board_[position] = mark;
          }
	else
	{ 
        Board_[position] = mark; 
    }
}

//TODO: Implement method
void Board::PrintBoard () {
    std::cout << "   |    | \n ";
    std::cout << "--|----|-- \n";
    std:: cout << "   |    | \n ";
    std:: cout << "--|----|-- \n";
    std::cout << "   |    | \n ";
}

//TODO: Implement method
void Board::ClearBoard () {
    std::cout << "ClearBoard" << std::endl;
    std::cout << string( 100, '\n' );
    std::cout << "   |    | \n ";
    std::cout << "--|----|-- \n";
    std:: cout << "   |    | \n ";
    std:: cout << "--|----|-- \n";
    std::cout << "   |    | \n ";
}


bool Board::isFull () {
    std::cout << "IsFull";
    return true;
}


bool Board::isFree (int position) {
    std::cout << "IsFree";
    return true;
}
