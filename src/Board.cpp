//
// Created by Dmitry Morozov on 10/6/22.
//

#include "Board.hpp"

#include <iostream>


Board::Board () {
    Clear ();
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



bool Board::isFree (int position) {
    return position == ' ';
}

bool Board::isFull () {
    return std::any_of (positions_.begin (), positions_.end (), [] (char c) { return c == ' '; });
}

void Board::Clear () {
    positions_.fill (' ');
}
