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

    const std::array<std::array<int, 3>, 8> &getWinningCombinations ();

    bool setPosition (int position, char mark);

    void PrintBoard ();

    void Clear ();

    bool isFull ();

    bool isValidPosition (int position);

    static const int k_board_size = {9}; // Board size

private:

    std::array<char, k_board_size + 1> positions_{}; // +1 for indexing from 1 to 9
    std::set<int> available_positions_;
    const std::array<std::array<int, 3>, 8> winning_combinations_ = {{{1, 2, 3},
                                                                      {4, 5, 6},
                                                                      {7, 8, 9},
                                                                      {1, 4, 7},
                                                                      {2, 5, 8},
                                                                      {3, 6, 9},
                                                                      {1, 5, 9},
                                                                      {3, 5, 7}}};

};


#endif //TICTAC_BOARD_HPP
