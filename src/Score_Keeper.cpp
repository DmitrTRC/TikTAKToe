//
// Created by Dmitry Morozov on 28/7/22.
//

#include <fstream>
#include <sstream>
#include <algorithm>


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
//    std::ifstream file (DB_URL);
//    if (!file.is_open ()) {
//        std::cout << "DB File is not open" << std::endl;
//        return;
//    }
//
//    std::string name;
//    int wins;
//    int loses;
//    int draws;
//
//    while (file >> name >> wins >> loses >> draws) {
//        scores_[name] = Score (wins, loses, draws);
//    }
//    file.close ();
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

//    std::ofstream file (DB_URL);
//    if (!file.is_open ()) {
//        std::cout << "DB File is not open" << std::endl;
//        return;
//    }
//    for (auto &pair: scores_) {
//        std::tuple<int, int, int> score = pair.second.getScore ();
//        file << pair.first << " " << std::get<0> (score) << " " << std::get<1> (score) << " " << std::get<2> (score)
//             << std::endl;
//    }
//    file.close ();

}

void ScoreKeeper::sortScores () {
    std::sort (scores_.begin (), scores_.end ());

}


