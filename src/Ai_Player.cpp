//
// Created by Dmitry Morozov on 18/7/22.
//

#include <vector>

#include "Ai_Player.hpp"


//Step 1: Check available positions to win by move
//Step 2: Check available positions to block opponent from winning by move
//Step 3: Check available positions in place 5
//Step 4: Check available positions to win by diagonal
//Step 5: Check positions [2,4,6,8] to win by diagonal
int AI_Player::engageMove (const Board &board) {
    //Step 1: Check available positions to win by move
    //Step 2: Check available positions to block opponent from winning by move
    //Step 3: Check available positions in place 5
    //Step 4: Check available positions to win by diagonal
    //Step 5: Check positions [2,4,6,8] to win by diagonal
    int result_move = -1;
    auto *board_ptr = new Board (board);
    std::vector<int> available_positions = board.getAvailablePositions ();

    for (int position : available_positions) {
        board_ptr->setPosition (position, getMark ());
        if (board_ptr->isWinner ()) {
            result_move = position;
            break;
        }
    }

    if (result_move == -1) {
        for (int position : available_positions) {
            board_ptr->setPosition (position, getOpponentMark ());
            if (board_ptr->isWinner ()) {
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
