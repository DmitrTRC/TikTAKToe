//
// Created by Dmitry Morozov on 28/5/22.
//
#include <iostream>
#include <stdlib.h>
#include "Game.hpp"
#include "player.hpp"

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
//
    auto db = LoadDataBase ();




//    Player player1 = FindPlayer (db, name);
//    Player player2; // Constructor is not defined
//
//// Repeating the game until the user quits
//    while (is_playing ()) {
//        bool player_type = GetOpponentType ();
//        SetSecondPlayer (player_type);
//
//        if (player_type) {
//            player2.Name = "Computer";
//        } else {
//            player2.Name = InputUserName ();
//        }

        Loop ();

        IsPlayAgain ();
// End of the Game
    }




std::string Game::InputUserName () {
    std::cout << "Enter User name running and returns a string Dmitry" << std::endl;
    return "Dmitry";
}

std::string Game::LoadDataBase(){
    std::cout << "DataBase" << std::endl;
    return "Database";
}

 void Game:: FindPlayer(){
     std::cout<<"find player";
 }
 char Game::GetOpponentType(){
     std::cout<<"GetOpponentType";
     return 'X';
 }     
 bool Game::IsPlayAgain(){
     std::cout<<"isPlayAgain";
     return true;
 }
void Game::Loop(){
    std::cout<<"Loop" << std::endl;
}
bool Game::is_playing(){
    std::cout<<"is_playing" << std::endl;
    return true;
}
int Game::GetFirstPlayer(){
    srand(time(0));
    return rand()%2;
}
