//
// Created by Dmitry Morozov on 12/8/22.
//
#include <iostream>

#ifndef TICTAC_MAIN_MENU_ENGINE_HPP
#define TICTAC_MAIN_MENU_ENGINE_HPP

//TODO: Menu system:
// - Add menu items
// 1. New game
// 2. Select 1-st player
// 2.a. Human
// 2.b. Computer
// 2.b.1. Easy
// 2.b.2. Medium
// 2.b.3. Hard ( MinMAx algorithm )
// 3. Select 2-nd player ( same as 1-st player )
// 4. Start game
// 5. Exit

class MenuEngine {
public:
    MenuEngine();
    int gamechoice;
    void menu();
private:
    void setgamechoice();
    int getgamechoice();

};


#endif //TICTAC_MAIN_MENU_ENGINE_HPP
