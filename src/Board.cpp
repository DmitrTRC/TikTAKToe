//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"

#include <iostream>


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

void Board::PrintBoard () {
    const std::string horizontal_line = "---+---+---";
    const std::string vertical_line = "|";

    std::cout << " " << positions_[7] << " " << vertical_line << " " << positions_[8] << " " << vertical_line << " "
              << positions_[9]
              << std::endl;
    std::cout << horizontal_line << std::endl;
    std::cout << " " << positions_[4] << " " << vertical_line << " " << positions_[5] << " " << vertical_line << " "
              << positions_[6]
              << std::endl;
    std::cout << horizontal_line << std::endl;
    std::cout << " " << positions_[1] << " " << vertical_line << " " << positions_[2] << " " << vertical_line << " "
              << positions_[3]
              << std::endl;

}


bool Board::isFull () {

    return available_positions_.empty ();
}

void Board::Clear () {
    positions_.fill (' ');
    positions_[0] = '#';
}

//TODO: Validate move ( position is free, position is valid )
bool Board::setPosition (int position, char mark) {
    if (isValidPosition (position)) {
        positions_[position] = mark;
        available_positions_.erase (position);
        return true;
    }
    return false;
}


