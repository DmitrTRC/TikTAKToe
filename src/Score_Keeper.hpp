//
// Created by Dmitry Morozov on 28/7/22.
//

#ifndef TICTAC_FEATURE_SCORE_SCORE_KEEPER_HPP
#define TICTAC_FEATURE_SCORE_SCORE_KEEPER_HPP

#include <iostream>

#include "Score.hpp"

class ScoreKeeper {
public:

    ScoreKeeper ();

    void loadScoresFromFile ();

    void saveScoresToFile ();

    void addScore (const std::string &name, ScoreType score);


    void printScores () {
        std::for_each (scores_.begin (), scores_.end (), [] (const std::pair<std::string, Score> &pair) {
            std::cout << pair.second << std::endl;
        });
    };



private:
    std::map< std::string, Score> scores_;
    const std::string DB_URL = "scores.db";
};


#endif //TICTAC_FEATURE_SCORE_SCORE_KEEPER_HPP
