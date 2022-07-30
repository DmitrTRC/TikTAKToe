//
// Created by Dmitry Morozov on 27/4/22.
//

#ifndef TIKTAKTOE_HELPER_HPP
#define TIKTAKTOE_HELPER_HPP

#include <iostream>


void ClearScreen () {
    const int ROWS_TO_CLEAR = 50;
    for (int i = 0; i < ROWS_TO_CLEAR; i++) {
        std::cout << std::endl;
    }
}

void DrawLogo () {
    const std::string LOGO = " ___________ __    __   ___      ___________  __      __   ___      ___________ ______   _______  \n"
                             "(\"     _   \")\" \\  |/\"| /  \")    (\"     _   \")/\"\"\\    |/\"| /  \")    (\"     _   \")    \" \\ /\"     \"| \n"
                              " )__/  \\\\__/||  | (: |/   /      )__/  \\\\__//    \\   (: |/   /      )__/  \\\\__// ____  (: ______) \n"
                             "    \\\\_ /   |:  | |    __/          \\\\_ /  /' /\\  \\  |    __/          \\\\_ / /  /    ) :)/    |   \n"
                             "    |.  |   |.  | (// _  \\          |.  | //  __'  \\ (// _  \\          |.  |(: (____/ //// ___)_  \n"
                             "    \\:  |   /\\  |\\|: | \\  \\         \\:  |/   /  \\\\  \\|: | \\  \\         \\:  | \\        /(:      \"| \n"
                             "     \\__|  (__\\_|_|__|  \\__)         \\__(___/    \\___|__|  \\__)         \\__|  \\\"_____/  \\_______) \n"
                             "                                                                                                  ";
    std::cout << LOGO << std::endl;
}

#endif //TIKTAKTOE_HELPER_HPP

