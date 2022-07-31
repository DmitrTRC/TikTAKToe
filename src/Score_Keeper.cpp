//
// Created by Dmitry Morozov on 28/7/22.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Score_Keeper.hpp"


void ScoreKeeper::addScore (const std::string &name, ScoreType score) {
    scores_[name].setScore (score);

}

void ScoreKeeper::loadScoresFromFile () {
    try {
        std::ifstream file (DB_URL);
        std::string line;
        while (std::getline (file, line)) {
            std::string name;
            int wins, loses, draws;
            std::istringstream iss (line);
            iss >> name >> wins >> loses >> draws;
            scores_[name] = Score (wins, loses, draws);
        }
    } catch (std::exception &e) {
        std::cerr << e.what () << std::endl;

    }

}

ScoreKeeper::ScoreKeeper () {
    loadScoresFromFile ();

}

void ScoreKeeper::saveScoresToFile () {
    try {
        std::ofstream file (DB_URL);
        for (auto &[name, score]: scores_) {
            auto [wins, loses, draws] = score.getScore ();
            file << name << " " << wins << " " << loses << " " << draws << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what () << std::endl;
    }

}


std::vector<std::pair<std::string, int> > ScoreKeeper::getScoresVector () {
    std::vector<std::pair<std::string, int> > scores;
    for (auto &[name, score]: scores_) {
        scores.emplace_back (name, score.getAverageScore () * 100);
    }
    std::sort (scores.begin (), scores.end (),
               [] (const std::pair<std::string, double> &lhs, const std::pair<std::string, double> &rhs) {
                   return lhs.second > rhs.second;
               });
    return scores;


}


