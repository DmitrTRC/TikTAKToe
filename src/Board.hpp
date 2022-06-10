//
// Created by Dmitry Morozov on 10/6/22.
//

#ifndef TICTAC_BOARD_HPP
#define TICTAC_BOARD_HPP

#include <array>
#include <set>


class Board {
public:
    Board ();

    void setPosition (int position, char mark);

    void PrintBoard ();

    void Clear ();

    bool isFull ();

    bool isFree (int position);

    static const int k_board_size = {9}; // Board size
private:
    std::array<char, k_board_size + 1> positions_; // +1 for indexing from 1 to 9
    std::set<int> available_positions_;

};


#endif //TICTAC_BOARD_HPP
