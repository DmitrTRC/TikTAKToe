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

    Score (int , int , int );
    Score ();

    void setScore ( ScoreType score);

    std::tuple <int, int, int> getScore ();

private:

    int wins_{};
    int loses_{};
    int draws_{};


};


#endif //TICTAC_SCORE_HPP
