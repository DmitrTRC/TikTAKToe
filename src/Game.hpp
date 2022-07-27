
#ifndef TIKTAKTOE_GAME_HPP
#define TIKTAKTOE_GAME_HPP

#include <vector>
#include "Board.hpp"
#include "Player.hpp"


class Game {
public:
    Game (); // default constructor
    ~Game ();

    static bool IsPlayAgain ();

    static bool is_playing ();

    static int getFirstPlayer ();

    void setNextPlayer ();

    void Start (); // Game entry point

private:
    bool is_playing_{}; // flag to check if the game is still running
    std::vector<Player *> players_; // vector of players
    ScoreKeeper score_keeper_; // score keeper
    Board board_; // game board
    int current_player_{}; //

    // index of current player
    std::string InputUserName (); // function to get user name

    Player &getCurrentPlayer ();

    void Loop ();
};


#endif //TIKTAKTOE_GAME_HPP
