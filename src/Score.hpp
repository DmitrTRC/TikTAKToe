//
// Created by Dmitry Morozov on 19/7/22.
//

#ifndef TICTAC_SCORE_HPP
#define TICTAC_SCORE_HPP

#include <iostream>
#include <map>


class Score {
public:
    friend std::ostream &operator<< (std::ostream &os, const Score &score) {
        os << "Name: " << score.name_ << "\t";
        os << "Wins: " << score.wins_ << "\t";
        os << "Loses: " << score.loses_ << "\t";
        os << "Draws: " << score.draws_ << std::endl;
        return os;

    };

private:

    std::string name_;
    int wins_;
    int loses_;
    int draws_;

};

std::ostream &operator<< (std::ostream &, const Score &);


class ScoreKeeper {
public:

    ScoreKeeper ();

    bool loadScoresFromFile ();

    bool saveScoresToFile ();

    void addScore (const Score &);

    void printScores (){
        std::for_each (scores_.begin(), scores_.end(), [](const std::pair<std::string, Score> &pair) {
            std::cout << pair.second << std::endl;
        });
    };


private:
    std::map<std::string, Score> scores_;

};


#endif //TICTAC_SCORE_HPP
