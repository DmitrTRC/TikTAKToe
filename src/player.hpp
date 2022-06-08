//
// Created by Dmitry Morozov on 2/6/22.
//

#ifndef TIKTAKTOE_PLAYER_HPP
#define TIKTAKTOE_PLAYER_HPP

#include <iostream>


//TODO: Think about the class Player and its methods and its properties
class Player { //Define as abstract class
public:
    Player ();

    virtual int engageMove () = 0;

    std::string getName ();

    void setName (std::string name);

private:
    std::string Name_;
    int Score_;
};

class HumanPlayer : public Player {
public:
//    HumanPlayer ();
//
//~HumanPlayer ();

    int engageMove () override;
};

class AIPlayer : public Player {
public:
//    AIPlayer ();
//
//    ~AIPlayer ();

    int engageMove () override;
};

#endif //TIKTAKTOE_PLAYER_HPP
