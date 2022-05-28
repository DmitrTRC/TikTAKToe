//
// Created by Dmitry Morozov on 28/5/22.
//

#ifndef TIKTAKTOE_GAME_HPP
#define TIKTAKTOE_GAME_HPP


class Game {
public:
    Game (); // default constructor
    ~Game (); // destructor

    void Start (); // Game entry point
private:
    int *Array; // array of cells


};


#endif //TIKTAKTOE_GAME_HPP
