
#ifndef TIKTAKTOE_GAME_HPP
#define TIKTAKTOE_GAME_HPP

#include <vector>
#include "Board.hpp"
#include "player.hpp"


//TODO: Add method int getFirstPlayer() to class Game. So that it can return index of first player.
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
    bool is_playing_; // flag to check if the game is still running
    std::vector<Player *> players_; // vector of players




    std::string InputUserName (); // function to get user name
    int current_player_; // index of current player
    Board board_; // game board


    Player &getCurrentPlayer ();

    void Loop ();
};


#endif //TIKTAKTOE_GAME_HPP
