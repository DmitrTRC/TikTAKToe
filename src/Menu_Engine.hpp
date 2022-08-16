//
// Created by Dmitry Morozov on 12/8/22.
//

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

// Define short hand for function pointer
//typedef void (*Menu_Processing_Function_Ptr) ();
using Menu_Processing_Function_Ptr = void (*) ();

class Menu_Item {

public:
    Menu_Item (int number, const char *text, Menu_Processing_Function_Ptr p_processing_function);


    int number () const;

    const char *text () const;

    void execute () const;


private:

    unsigned int number_;
    const char *text_;
    Menu_Processing_Function_Ptr p_processing_function;
};

class Console_Menu {
public:


    Console_Menu (Menu_Item *, unsigned int);

    void Run (Menu_Item *p_menu, unsigned int item_quantity);


private:

};


#endif //TICTAC_MAIN_MENU_ENGINE_HPP
