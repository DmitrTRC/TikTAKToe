//
// Created by Dmitry Morozov on 18/7/22.
//

#include <vector>

#include "Ai_Player.hpp"


//FIXME: Check logic with  EVEN and ODD Moves
int AI_Player::engageMove (const Board &board) {
    //Step 1: Check available positions to win by move
    //Step 2: Check available positions to block opponent from winning by move
    //Step 3: Check odd available positions
    //Step 4: Check available positions in place 5
    //Step 5: Check even  available positions

    int result_move = -1;

    auto *board_ptr = new Board (board);
    std::vector<int> available_positions = board.getAvailablePositions ();
    // available_positions = {1,2,4,7,9}
    for (int position: available_positions) {
        board_ptr->setPosition (position, getMark ());
        if (board_ptr->isWinner ()) {
            result_move = position;
            break;
        }
    }

    if (result_move == -1) {
        for (int position: available_positions) {
            board_ptr->setPosition (position, getOpponentMark ());
            if (board_ptr->isWinner ()) {
                result_move = position;
                break;
            }
        }
    }

//TODO: Make random selection
    if (result_move == -1) {
        for (int position: available_positions) {
            if (position == 1 || position == 3 || position == 7 || position == 9) {
                result_move = position;
                break;
            }
        }
    }

    if (result_move == -1) {
        if (board_ptr->isValidPosition (5)) {
            result_move = 5;
        }
    }

    if (result_move == -1) {
        for (int position: available_positions) {
            if (position == 2 || position == 4 || position == 6 || position == 8) {
                result_move = position;
                break;
            }
        }
    }


    return result_move;
}

AI_Player::AI_Player (const std::string &name) {

    setName (name);

}

char AI_Player::getOpponentMark () const {
    return (getMark () == 'X') ? 'O' : 'X';
}
