//
// Created by Dmitry Morozov on 19/7/22.
//

#ifndef TICTAC_SCORE_HPP
#define TICTAC_SCORE_HPP

#include <iostream>


class Score {
public:
    friend std::ostream &operator<< (std::ostream &, const Score &);

private:

    std::string name_;
    int wins_;
    int loses_;
    int draws_;

};


#endif //TICTAC_SCORE_HPP
