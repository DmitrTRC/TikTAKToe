//
// Created by Dmitry Morozov on 12/8/22.
//

#include <iostream>

#include "Menu_Engine.hpp"


void Console_Menu::Run (Menu_Item *p_menu, unsigned int item_quantity) {
    // Display the menu
    for (unsigned int i = 0; i < item_quantity; ++i) {
        std::cout << p_menu[i].number
                  << ". "
                  << p_menu[i].text
                  << "\n";
    }
    std::cout << "Enter selection: ";
    unsigned int selection;
    std::cin >> selection;
    for (unsigned int i = 0; i < item_quantity; ++i) {
        if (selection == p_menu[i].number) {
            // Execute the processing function for the selection.
            (p_menu[i].p_processing_function) ();
            break;
        }
    }
    if (i >= item_quantity) {
        std::cout << "invalid selection\n";
    }
}

Menu_Item::Menu_Item (int number, const char *text, Menu_Processing_Function_Ptr p_processing_function) {

}

