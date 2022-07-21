//
// Created by Dmitry Morozov on 19/7/22.
//

#ifndef TICTAC_RESULT_HPP
#define TICTAC_RESULT_HPP

#include <iostream>


class Score {
    std::string name;
    int wins;
    int loses;
    int draws;

};

class Result {
public:
    void ShowResult ();

    bool LoadDB ();

    bool SaveDB ();

    void ShowScoreTable ();


};


#endif //TICTAC_RESULT_HPP
