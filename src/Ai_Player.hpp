//
// Created by Dmitry Morozov on 18/7/22.
//

#ifndef TICTAC_AI_PLAYER_HPP
#define TICTAC_AI_PLAYER_HPP

#include "Player.hpp"


class AI_Player : public Player {
public:
    explicit AI_Player (const std::string &name = "AI Player");

    int engageMove (const Board &) override;

private:
    char getOpponentMark () const;
};


#endif //TICTAC_AI_PLAYER_HPP
