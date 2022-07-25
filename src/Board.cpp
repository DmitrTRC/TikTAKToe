//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"

using std::string;

Board::Board () {

    available_positions_ = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Clear ();

}




bool Board::isValidPosition (int position) {
    return available_positions_.find (position) != available_positions_.end ();
}

const std::array<std::array<int, 3>, 8> &Board::getWinningCombinations () {
    return winning_combinations_;
}

//FIXME: Check scope resolution operator for std::string
//TODO: Change var names to be more descriptive ( str, str1 )
//TODO: Test code before submitting to git hub!!!
void Board::ShowPrompt(){
    const string vertical  = " ---|-----|--- ";
    const string horizontal = "    |     | ";


    std::cout << "    |     |   " << std::endl; //Better way to use std::endl.
    std::cout << " " << "1" << "  | " << "2" << "   | " << "3" << std::endl;
    std::cout << vertical << std::endl;
    std::cout << " " << "4" << "  |" << "5" << "    |" << "6" << std::endl;
    std::cout << horizontal << std::endl;
    std::cout << vertical << std::endl;
    std::cout << " " << "7" << "  | " << "8" << "   | " << "9" << std::endl;
    std::cout << horizontal << std::endl;


}
void Board::PrintBoard () { // Ok! Everything is correct

    const string vertical  = " ---|-----|--- ";
    const string horizontal = "    |     | ";


    std::cout << "    |     |   " << std::endl; //Better way to use std::endl.
    std::cout << " " << positions_[1] << "  | " << positions_[2] << "   | " << positions_[3] << std::endl;
    std::cout << vertical << std::endl;
    std::cout << " " << positions_[4] << "  |" << positions_[5] << "    |" << positions_[6] << std::endl;
    std::cout << horizontal << std::endl;
    std::cout << vertical << std::endl;
    std::cout << " " << positions_[7] << "  | " << positions_[8] << "   | " << positions_[9] << std::endl;
    std::cout << horizontal << std::endl;


}


void Board::Clear () { // Fill positions with empty characters
//
    for (int i = 1; i < positions_.size (); i++) {
        positions_[i] = ' ';
    }
//    positions_.fill (' ');
}

//TODO: Implement method

//TODO: Function must return true if the board is full, false otherwise.
//Use test board like this:
//positions_ = {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}; // Full board : True
//positions_ = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Empty board : False
//positions_ = {'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' '}; // Two positions : False
//positions_ = {' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}; // Two positions : True

bool Board::isFull () {
    for (const auto &i: positions_) {
        return std::any_of(positions_.begin(), positions_.end(), [](char c) { return c == ' '; });
    }
}

bool Board::setPosition (int position, char mark) {
    if (isValidPosition(position)) {
        positions_[position] = mark;
        available_positions_.erase(position);
        return true;
    }
    return false;
}

    bool Board::isWinner() {
        for (const auto &combination: winning_combinations_) {
            if (positions_[combination[0]] == positions_[combination[1]] &&
                positions_[combination[1]] == positions_[combination[2]] &&
                positions_[combination[0]] != ' ') {
                return true;
            }
        }
        return false;
    }
