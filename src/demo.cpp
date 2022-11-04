//
// Created by Dmitry Morozov on 17/8/22.
//
#include <iostream>


int get_choice () {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int  sub_menu_select_player () {
    std::cout << "1. Human" << "\n";
    std::cout << "2. Computer" << "\n";
    return get_choice ();
}

int main () {

    int choice = 0;
    do {
        std::cout << "1. Play geme" << std::endl;
        std::cout << "2. Save Score " << std::endl;
        std::cout << "3. Select Player " << std::endl;
        std::cout << "4. Exit " << std::endl;
        choice = get_choice ();
        switch (choice) {
            case 1: {
                std::cout << "You have chosen to play game" << std::endl;
                break;
            }
            case 2: {
                std::cout << "You have chosen to save score" << std::endl;
                break;
            }
            case 3: {
                int player_choice = sub_menu_select_player ();
                std::cout << "You have chosen to select player" << player_choice <<  std::endl;
                break;
            }
            case 4: {
                std::cout << "You have chosen to exit" << std::endl;
                break;
            }
            default: {
                std::cout << "You have chosen wrong number" << std::endl;
                break;
            }
        };

    } while (choice != 4);


}