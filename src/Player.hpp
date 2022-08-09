//
// Created by Dmitry Morozov on 2/6/22.
//

#ifndef TIKTAKTOE_PLAYER_HPP
#define TIKTAKTOE_PLAYER_HPP

#include <iostream>
#include "Board.hpp"
#include "Score.hpp"


//TODO: Separaate the class Player into three classes: Player, HumanPlayer and AIPlayer.
class Player { //Define as abstract class
public:
    Player ();


    virtual int engageMove (const Board &) = 0; // Define as pure virtual function - abstract class

    std::string getName ();

    void setName (const std::string & = "Unknown");

    [[nodiscard]] char getMark () const;

    void setMark (char mark);


private:
    std::string Name_;
    Score score_;
    char mark_;
};



#endif //TIKTAKTOE_PLAYER_HPP
