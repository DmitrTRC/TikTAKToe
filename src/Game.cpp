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

//Point 2. Main Game loop. Initialize the game.
void Game::Start () {
    std::cout << "Game started" << std::endl;

    //Point 3. Create two players. ( Ask for type of player and name of player)

    HumanPlayer player1 (InputUserName (1));
    players_.push_back (&player1); // Put player1 address in vector

    HumanPlayer player2 (InputUserName (2));
    players_.push_back (&player2);

    //Point 4. Set first player.
    current_player_ = getFirstPlayer ();

//    auto db = LoadDataBase ();

// Point 5. Start the game loop.

    while (is_playing ()) {
        Loop ();
        // Point 6 Check that the game is still running.
        IsPlayAgain ();

    }
    //Point 7. End the game.
}

int Game::InputNextMove () {
    int number{0};
    std::cout << "Input an integer number in range 1 to 9\n";

    while ((!(std::cin >> number)) || (number > 9 || number < 1)) {

        std::cin.clear ();
        std::cin.ignore (5000, '\n');

    }

    return static_cast<int>(number);
}

bool Game::isWinner () {
    bool isWinner = true;
    std::array<char, 10> positions = {'#', 'X', 'X', ' ', ' ',
                                      'X', ' ', 'X', 'O', 'X'};
    for (auto &combination: board_.getWinningCombinations ()) {
        for (auto &cell: combination) {
            if (positions[cell] != getCurrentPlayer ().getMark ()) {
                isWinner = false;
                break;
            }

        }
        if (isWinner) break;

    }

    return isWinner;
}

Player &Game::getCurrentPlayer () {
    return *players_[current_player_];
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

//Point 5.1. Main game logic loop.
void Game::Loop () {
    bool game_active = true;

    while (game_active) {

        std::cout << "Player " << getCurrentPlayer ().getName () << " turn" << std::endl;
        //TODO: DRAW BOARD
        int next_move = getCurrentPlayer ().engageMove (board_);
z
        if (!board_.setPosition(next_move, getCurrentPlayer ().getMark ())) {
            std::cout << "Invalid move" << std::endl;
            continue;
        }

        //Point 5.5. Check if the game is over.
        if (isWinner ()) {
            std::cout << "Player " << getCurrentPlayer ().getName () << " won!" << std::endl;
            getCurrentPlayer ().addWin (); // Add one win to the player score_
            game_active = false;
        } else if (board_.isFull ()) {
            std::cout << "Draw!" << std::endl;
            game_active = false;
        } else {
            setNextPlayer ();
        }
        }
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
