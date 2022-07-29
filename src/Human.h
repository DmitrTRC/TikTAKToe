//
// Created by Arina on 25.07.2022.
//

#ifndef TICTAC_HUMAN_H
#define TICTAC_HUMAN_H

#endif //TICTAC_HUMAN_H
#include <iostream>
#include "Board.hpp"
#include "player.hpp"
class HumanPlayer : public Player {
public:
    HumanPlayer (const std::string &name = "Unknown");

    int engageMove (const Board &) override;

private:
    static int InputNextMove ();

};


