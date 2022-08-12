//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"

#include <vector>


Board::Board () {
    Clear ();
}

bool Board::isValidPosition (int position) {
    return available_positions_.find (position) != available_positions_.end ();
}

const std::array<std::array<int, 3>, 8> &Board::getWinningCombinations () {
    return winning_combinations_;
}

//TODO: Modify this function to show help information about the board.
void Board::PrintBoard () {
    std::cout << std::endl;
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

    std::cout << std::endl;
}


bool Board::isFull () {

    return available_positions_.empty ();
}

void Board::Clear () {
    positions_.fill (' ');
    positions_[0] = '#';
    resetAvailablePositions ();
}

bool Board::setPosition (int position, char mark) {
    if (isValidPosition (position)) {
        positions_[position] = mark;
        available_positions_.erase (position);
        return true;
    }
    return false;
}

bool Board::isWinner () {
    for (const auto &combination: winning_combinations_) {
        if (positions_[combination[0]] == positions_[combination[1]] &&
            positions_[combination[1]] == positions_[combination[2]] &&
            positions_[combination[0]] != ' ') {
            return true;
        }
    }
    return false;
}

void Board::resetAvailablePositions () {
    available_positions_ = {1, 2, 3, 4, 5, 6, 7, 8, 9};

}

std::vector<int> Board::getAvailablePositions () const {

    return {available_positions_.begin (), available_positions_.end ()};
}
