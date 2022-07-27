//
// Created by Dmitry Morozov on 19/7/22.
//

#include "Score.hpp"
#include <fstream>


std::ostream &operator<< (std::ostream &os, const Score &score) {
    os << "Name: " << score.name_ << std::endl;
    os << "Wins: " << score.wins_ << std::endl;
    os << "Loses: " << score.loses_ << std::endl;
    os << "Draws: " << score.draws_ << std::endl;
    return os;
}

Score::Score () = default;


Score::Score (int wins, int loses, int draws) {
    wins_ = wins;
    loses_ = loses;
    draws_ = draws;
}

auto Score::getScore () {
    return std::make_tuple (wins_, loses_, draws_);
}

void Score::setScore (ScoreType score) {
    switch (score) {
        case ScoreType::Win:
            wins_++;
            break;
        case ScoreType::Lose:
            loses_++;
            break;
        case ScoreType::Draw:
            draws_++;
            break;
    }

}

void ScoreKeeper::addScore (const std::string &name, ScoreType score) {
    scores_[name].setScore (score);

}

void ScoreKeeper::loadScoresFromFile () {
    std::ifstream file (DB_URL);
    if (!file.is_open ()) {
        std::cout << "DB File is not open" << std::endl;
        return;
    }
    std::string name;
    int wins;
    int loses;
    int draws;

    while (file >> name >> wins >> loses >> draws) {
        scores_[name] = Score (wins, loses, draws);
    }
    file.close ();
}

ScoreKeeper::ScoreKeeper () {
    loadScoresFromFile ();

}

void ScoreKeeper::saveScoresToFile () {
    std::ofstream file (DB_URL);
    if (!file.is_open ()) {
        std::cout << "DB File is not open" << std::endl;
        return;
    }
    for (auto &pair: scores_) {
        auto score = pair.second.getScore ();
        file << pair.first << " " << std::get<0> (score) << " " << std::get<1> (score) << " " << std::get<2> (score)
             << std::endl;
    }
    file.close ();

}
