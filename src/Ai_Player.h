//
// Created by Arina on 25.07.2022.
//

#ifndef TICTAC_AI_PLAYER_H
#define TICTAC_AI_PLAYER_H

#endif //TICTAC_AI_PLAYER_H


#include "player.hpp"


class AI_Player : public Player {
public:
    AI_Player (const std::string &name = "AI Player");

    int engageMove (const Board &) override;
};

