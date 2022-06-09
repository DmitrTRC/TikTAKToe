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
    virtual void WhoFirst() = 0;
    virtual void setName (std::string name);
    virtual void setPassword (std::string password);
    std::string getPassword ();
    
    

private:
    std::string Name_;
    int Score_;
    std::string Password_;
    int rating_;
};

class HumanPlayer : public Player {
public:
//    HumanPlayer ();
//
//~HumanPlayer ();

    int engageMove () override;
    void WhoFirst() override;
};

class AIPlayer : public Player {
public:
//    AIPlayer ();
//
//    ~AIPlayer ();

    int engageMove () override;
    void WhoFirst() override;
};

#endif //TIKTAKTOE_PLAYER_HPP
