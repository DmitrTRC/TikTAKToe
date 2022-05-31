//
// Created by Dmitry Morozov on 28/5/22.
//

#ifndef TIKTAKTOE_GAME_HPP
#define TIKTAKTOE_GAME_HPP


class Game {
public:
    Game (); // default constructor
    ~Game (); // destructor
    void displayBoard(); //displays our board 
    void getMove(char player); //asks the user for his move
    

    void Start (); // Game entry point
private:
    const int MaxMoves=9;
    int *Array; // array of cells
    bool checkForWins(char player) //check wins
    bool checkForDraw() //check request limits


};


#endif //TIKTAKTOE_GAME_HPP
