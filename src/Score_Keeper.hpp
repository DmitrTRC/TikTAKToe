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

    std::vector<std::pair<std::string, int> > getScoresVector () ;

private:
    std::map<std::string, Score> scores_;
    const std::string DB_URL = "scores.db";

};


#endif //TICTAC_FEATURE_SCORE_SCORE_KEEPER_HPP
