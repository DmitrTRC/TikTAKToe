//
// Created by Dmitry Morozov on 19/7/22.
//

#ifndef TICTAC_SCORE_HPP
#define TICTAC_SCORE_HPP

#include <iostream>
#include <map>



enum class ScoreType {
    Win,
    Lose,
    Draw
};


class Score {


public:
    friend std::ostream &operator<< (std::ostream &, const Score &);

    Score ();

    void setScore (const std::string &name, ScoreType score);

    auto getScore ();

private:
    std::string name_;
    int wins_;
    int loses_;
    int draws_;


};


class ScoreKeeper {
public:

    ScoreKeeper ();

    bool loadScoresFromFile ();

    bool saveScoresToFile ();


    void printScores () {
        std::for_each (scores_.begin (), scores_.end (), [] (const std::pair<std::string, Score> &pair) {
            std::cout << pair.second << std::endl;
        });
    };



private:
    std::map< std::string, Score> scores_;
};


#endif //TICTAC_SCORE_HPP
