//
// Created by Dmitry Morozov on 2/6/22.
//

#ifndef TIKTAKTOE_PLAYER_HPP
#define TIKTAKTOE_PLAYER_HPP

#include <iostream>
#include "Board.hpp"


//TODO: Separaate the class Player into three classes: Player, HumanPlayer and AIPlayer.
class Player { //Define as abstract class
public:
    Player ();


    virtual int engageMove (const Board &) = 0;// Define as pure virtual function - abstract class
    virtual void setPassword(std::string password);
    std::string getPassword();
    std::string getName ();

    void setName (const std::string & = "Unknown");

    char getMark () const;

    void setMark (char mark);

    void addWin ();

private:
    std::string Name_;
    int Score_;
    char mark_;
    std::string Password_;
};


#endif //TIKTAKTOE_PLAYER_HPP