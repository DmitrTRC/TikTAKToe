//
// Created by Dmitry Morozov on 10/6/22.
//

#ifndef TICTAC_BOARD_HPP
#define TICTAC_BOARD_HPP

#include <array>


class Board {
public:
    Board ();

    void setPosition (int position, char mark);
    void PrintBoard ();
    void ClearBoard ();
    bool isFull ();
    bool isFree (int position);

    static const int k_board_size = {9}; // Board size
private:
    std::array<char, k_board_size + 1> positions_; // +1 for indexing from 1 to 9

};


#endif //TICTAC_BOARD_HPP
