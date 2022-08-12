//
// Created by Dmitry Morozov on 28/5/22.
//
//TODO: Sort order of headers
#include <iostream>
#include <stdlib.h>

#include "Ai_Easy_Player.hpp"
#include "Ai_Player.hpp"
#include "Game.hpp"
#include "helper.hpp"
#include "Human_Player.hpp"
#include "Score.hpp"


Game::Game () {

//    std::cout << "class Game constructor is running" << std::endl;
    srand (time (nullptr));

}

Game::~Game () {
    //  std::cout << "class Game destructor is running" << std::endl;

}

//Point 2. Main Game loop. Initialize the game.
void Game::Start () {
    DrawLogo ();
    printTopScores ();

    //board_.DrawHelper ();

    //Point 3. Create two players. ( Ask for type of player and name of player)


    HumanPlayer player1 (InputUserName ());
    players_.push_back (&player1); // Put player1 address in vector

    //TODO: Need to ask for player type and name

//    HumanPlayer player2 (InputUserName ());
//    AI_EASY_Player player2 ("AI Player");
    AI_Player player2 ("AI Player");
    players_.push_back (&player2);

    //Point 4. Set first player.
    current_player_ = getFirstPlayer ();

    players_[current_player_]->setMark ('X');
    players_[(current_player_ + 1) % 2]->setMark ('O');


    do {
        Loop ();
        score_keeper_.saveScoresToFile ();
        board_.Clear (); // ????
    } while (IsPlayAgain ());

    printTopScores ();

    DrawGameOver ();

}


Player &Game::getCurrentPlayer () {
    return *players_[current_player_];
}

std::string Game::InputUserName () {
    std::cout << "Enter Player name : ";
    std::string name;
    std::cin >> name;
    return name;
}


bool Game::IsPlayAgain () {
    std::cout << "Do you want to play again? (y/n)";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        return true;
    } else {
        return false;
    }
}

//Point 5.1. Main game logic loop.
void Game::Loop () {
    bool game_active = true;

    while (game_active) {

        board_.PrintBoard ();

        std::cout << "Player " << getCurrentPlayer ().getName () << " turn : " << std::endl;
        std::cout << std::endl;

        int next_move = getCurrentPlayer ().engageMove (board_);

        if (!board_.setPosition (next_move, getCurrentPlayer ().getMark ())) {
            std::cout << "Invalid move" << std::endl;
            std::cout << std::endl;
            continue;
        }

        //Point 5.5. Check if the game is over.
        if (board_.isWinner ()) {
            DrawWinner (getCurrentPlayer ().getName ());
            board_.PrintBoard ();

            score_keeper_.addScore (getCurrentPlayer ().getName (), ScoreType::Win); // Add one win to the player score_
            setNextPlayer ();
            score_keeper_.addScore (getCurrentPlayer ().getName (),
                                    ScoreType::Lose); // Add one loss to the player score_
            game_active = false;
        } else if (board_.isFull ()) {
            DrawDraw ();
            score_keeper_.addScore (getCurrentPlayer ().getName (),
                                    ScoreType::Draw); // Add one draw to the player score_
            setNextPlayer ();
            score_keeper_.addScore (getCurrentPlayer ().getName (),
                                    ScoreType::Draw); // Add one draw to the player score_
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

void Game::printTopScores (int n) {
    auto scores = score_keeper_.getScoresVector ();
    std::cout << std::endl << "Top " << n << " Players scores ( Percentage of wins ) :" << std::endl;
    int counter{1};
    for (auto &[name, score]: scores) {
        std::cout << counter << ". " << name << ": " << score << std::endl;
        counter++;
        if (counter == n + 1) { // Starting from 1 up to n + 1
            break;
        }
    }
    std::cout << std::endl;
}
