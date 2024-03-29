//
// Created by Dmitry Morozov on 4/8/22.
//

#include <vector>
#include "Ai_Easy_Player.hpp"
#include <chrono>
#include <thread>


AI_EASY_Player::AI_EASY_Player (const std::string &name) {
    setName (name);

}

int AI_EASY_Player::engageMove (const Board &board) {
    // Return random number from available positions
    //TODO: implement AI logic : iterate through available positions and return if it has a winning move or randome move

    std::cout << "Thinking ..." << std::endl;

    // Sleep for 1 second
    std::this_thread::sleep_for (std::chrono::seconds (1));

    return board.getAvailablePositions ().at (rand () % board.getAvailablePositions ().size ());
}
