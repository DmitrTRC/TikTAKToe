//
// Created by Dmitry Morozov on 28/5/22.
//
#include <iostream>
#include <stdlib.h>
#include "Game.hpp"
#include "player.hpp"


Game::Game () {

    std::cout << "class Game constructor is running" << std::endl;
    srand (time (0));

}

Game::~Game () {
    std::cout << "class Game destructor is running" << std::endl;

}

void Game::Start () {
    std::cout << "Game started" << std::endl;

    HumanPlayer player1 (InputUserName (1));
    players_.push_back (&player1); // Put player1 address in vector

    HumanPlayer player2 (InputUserName (2));
    players_.push_back (&player2); // Put player2 address in vector

    current_player_ = getFirstPlayer ();

//    auto db = LoadDataBase ();

// Repeating the game until the user quits
    while (is_playing ()) {
//

        Loop ();

        IsPlayAgain ();
// End of the Game
    }
}


std::string Game::InputUserName (int player_number) {
    std::cout << "Enter User " << player_number << " name : ";
    std::string name;
    std::cin >> name;
    return name;
}

std::string Game::LoadDataBase () {
    std::cout << "DataBase" << std::endl;
    return "Database";
}

void Game::FindPlayer () {
    std::cout << "find player";
}

char Game::GetOpponentType () {
    std::cout << "GetOpponentType";
    return 'X';
}

bool Game::IsPlayAgain () {
    std::cout << "isPlayAgain";
    return true;
}

void Game::Loop () {
    std::cout << "Game Loop" << std::endl;
    int cur_move = players_[current_player_]->engageMove ();
    if (board_.isFree (cur_move)){
        //TODO: Set the move in the board
    } else {
        std::cout << "Invalid move" << std::endl;
    }
    if (isWinner()) {
        std::cout << "Player " << current_player_ << " wins" << std::endl;

    }
    setNextPlayer ();

}

bool Game::is_playing () {
    std::cout << "is_playing" << std::endl;
    return true;
}


int Game::getFirstPlayer () {
    return rand () % 2; // Native C function to generate random number
}



void Game::setNextPlayer () { //current_player ( 0 or 1 )
    current_player_ = 1 - current_player_;

}
