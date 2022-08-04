//
// Created by Dmitry Morozov on 4/8/22.
//

#ifndef TICTAC_FEATURE_AIMOVE_AI_EASY_PLAYER_HPP
#define TICTAC_FEATURE_AIMOVE_AI_EASY_PLAYER_HPP

#include "Player.hpp"


class AI_EASY_Player : public Player {
public:
    explicit AI_EASY_Player (const std::string &name = "AI Player");

    int engageMove (const Board &) override;
};


#endif //TICTAC_FEATURE_AIMOVE_AI_EASY_PLAYER_HPP
