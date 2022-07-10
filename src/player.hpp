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


    virtual int engageMove () = 0; // Define as pure virtual function - abstract class

    std::string getName ();

    //TODO: Add Property Mark_ and setter and getter for it. Than set 'X' if first player and 'O' if second player
    virtual void WhoFirst () = 0;

    virtual void setName (std::string name);

    char getMark ();


private:
    std::string Name_;
    int Score_;
    int rating_;
    char mark_;
};

class HumanPlayer : public Player {
public:
    HumanPlayer (std::string name);
//    HumanPlayer ();
//
//~HumanPlayer ();

    int engageMove () override;

    void WhoFirst () override;
};

class AIPlayer : public Player {
public:
//    AIPlayer ();
//
//    ~AIPlayer ();

    int engageMove () override;

    void WhoFirst () override;
};

#endif //TIKTAKTOE_PLAYER_HPP
