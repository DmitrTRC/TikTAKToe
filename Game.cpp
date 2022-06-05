//
// Created by Dmitry Morozov on 28/5/22.
//
#include <iostream>

#include "Game.hpp"
#include "Player.hpp"

//TODO: Fix the code below
Game::Game () {

    std::cout << "class Game constructor is running" << std::endl;

}

Game::~Game () {
    std::cout << "class Game destructor is running" << std::endl;

}

void Game::Start () {
    std::cout << "Game started" << std::endl;
    std::string name = InputUserName ();

    auto db = LoadDataBase ();
    Player player1 = FindPlayer (db, name);
    Player player2; // Constructor is not defined

// Repeating the game until the user quits
    while (is_playing ()) {
        bool player_type = GetOpponentType ();
        SetSecondPlayer (player_type);

        if (player_type) {
            player2.Name = "Computer";
        } else {
            player2.Name = InputUserName ();
        }

        Loop ();

        IsPlayAgain ();
// End of the Game
    }

}


std::string Game::InputUserName () {
    std::cout << "Enter User name running and returns a string Dmitry" << std::endl;
    return std::string ("Dmitry");
}

std::string Game::LoadDataBase(){
    std::cout << "DataBase" << std::endl;
    return std::string ("Database");
}

 void FindPlayer(){
     std::cout<<"find player";
 }
 char GetOpponentType(){
     std::cout<<"GetOpponentType";
 }     
 bool IsPlayAgain(){}
void Loop(){
    std::cout<<"Loop";
}
bool is_playing()
