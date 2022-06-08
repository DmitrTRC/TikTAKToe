
#ifndef TIKTAKTOE_GAME_HPP
#define TIKTAKTOE_GAME_HPP

#include <vector>
#include "player.hpp"

class Game {
public:
    Game (); // default constructor
    ~Game ();

    //Todo: Fix! Ты не правильно пишешь реализацию методов в классе Game! Используй scope resolution operator ::
    void SetSecondPlayer();
    void FindPlayer();
    char GetOpponentType();
    bool IsPlayAgain();
     bool is_playing();
    


    void Start (); // Game entry point
private:
    bool is_playing_; // flag to check if the game is still running
//    std::vector<(Player *)> players_; // vector of players
    std::string LoadDataBase();
    std::string InputUserName (); // function to get user name

};


#endif //TIKTAKTOE_GAME_HPP
