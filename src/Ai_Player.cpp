//
// Created by Dmitry Morozov on 18/7/22.
//

#include "Ai_Player.hpp"


int AI_Player::engageMove (const Board &board) {
    int best_move{0};
    int best_score{0};
    for (int i{0}; i < 9; i++) {
        if (board.isValidPosition (i)) {
            Board board_copy{board};
            board_copy.setPosition (i, getMark ());
            int score{board_copy.getScore ()};
            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }

}

AI_Player::AI_Player (const std::string &name) {
    std::cout << "class AIPlayer constructor is running" << std::endl;
    setName (name);

}
