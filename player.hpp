//
// Created by Dmitry Morozov on 2/6/22.
//

#ifndef TIKTAKTOE_PLAYER_HPP
#define TIKTAKTOE_PLAYER_HPP


//TODO: Think about the class Player and its methods and its properties
class Player {
public:
    Player ();

private:
    std::string Name_;
    int Score_;
};

class HumanPlayer : public Player {
public:
    HumanPlayer ();

    ~HumanPlayer ();
};

class AIPlayer : public Player {
public:
    AIPlayer ();

    ~AIPlayer ();
};

#endif //TIKTAKTOE_PLAYER_HPP
