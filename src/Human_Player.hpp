//
// Created by Dmitry Morozov on 27/7/22.
//

#ifndef TICTAC_FEATURE_SCORE_HUMAN_PLAYER_HPP
#define TICTAC_FEATURE_SCORE_HUMAN_PLAYER_HPP

#include "Player.hpp"


class HumanPlayer : public Player {
public:
    HumanPlayer ();
    HumanPlayer (const std::string &);

    int engageMove (const Board &) override;

private:
    int InputNextMove ();

};


#endif //TICTAC_FEATURE_SCORE_HUMAN_PLAYER_HPP
