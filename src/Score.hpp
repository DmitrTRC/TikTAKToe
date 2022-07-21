//
// Created by Dmitry Morozov on 19/7/22.
//

#ifndef TICTAC_SCORE_HPP
#define TICTAC_SCORE_HPP

#include <iostream>
#include <map>


class Score {
public:
    friend std::ostream &operator<< (std::ostream &, const Score &);

private:

    std::string name_;
    int wins_;
    int loses_;
    int draws_;

};

class ScoreKeeper {
public:
    ScoreKeeper ();

    void addScore (const Score &);

    void printScores ();

private:
    std::map<std::string, Score> scores_;

};


#endif //TICTAC_SCORE_HPP
