//
// Created by Dmitry Morozov on 12/8/22.
//

#include "Menu_Engine.hpp"
#include <Player.hpp>
#include <Game.hpp>
#include <Ai_Easy_Player.hpp>
#include <Ai_Player.hpp>
#include <Human_Player.hpp>
void MenuEngine::setgamechoice(){
    int number;
    std::cout<<"input your choice ";
    std::cin>>number;
    gamechoice=number;

}
int MenuEngine::getgamechoice() {
    return gamechoice;
}
MenuEngine::MenuEngine() {
    std::cout<<"1. New game"<<"\n";
    std::cout<<"2. Select 1-st player"<<"\n";
    std::cout<<"3. Select 2-nd player ( same as 1-st player )"<<"\n";
    std::cout<<"4. Start game"<<"\n";
    std::cout<<"5. Exit"<<"\n";
}


void MenuEngine::menu() {
    setgamechoice();
    switch(gamechoice){
        case 1:{
            Game gamenew;
            break;
        }
        case 2:{
            std::cout<<"1. Human"<<"\n";
            std::cout<<"2. Computer"<<"\n";
            setgamechoice();
            switch (gamechoice){
                case 1:{
                    HumanPlayer player;
                    break;
                }
                case 2:{
                    std::cout<<"1.easy"<<"\n";
                    std::cout<<"2.medium"<<"\n";
                    std::cout<<"hard"<<"\n";
                    setgamechoice();
                    switch (gamechoice){
                        case 1:{
                            AI_EASY_Player Ai_es_player;
                            break;
                        }
                        case 2:{
                            AI_Player Aiplayer;
                            break;
                        }
                        case 3:{
                            std::cout<<"MnMAx";
                            break;
                        }
                    }
                    default:{
                        std::cout<<"Choose correct number\n";
                        setgamechoice();
                        break;
                    }

                }
            }
            break;
        }
        case 3:{
            std::cout<<"1. Human"<<"\n";
            std::cout<<"2. Computer"<<"\n";
            setgamechoice();
            switch (gamechoice){
                case 1:{
                    HumanPlayer player;
                    break;
                }
                case 2:{
                    std::cout<<"1.easy"<<"\n";
                    std::cout<<"2.medium"<<"\n";
                    std::cout<<"hard"<<"\n";
                    setgamechoice();
                    switch (gamechoice){
                        case 1:{
                            AI_EASY_Player Ai_es_player;
                            break;
                        }
                        case 2:{
                            AI_Player Aiplayer;
                            break;
                        }
                        case 3:{
                            std::cout<<"MnMAx";
                            break;
                        }
                        default:{
                            std::cout<<"Choose correct number\n";
                            setgamechoice();
                            break;
                        }

                    }
                }
            }
            break;
        }
        case 4: {
            Game game;
            game.Start();
            break;
        }
        case 5:{
            std::cout<<"exit";
            break;
        }
        default:{
            std::cout<<"Choose correct number\n";
            setgamechoice();
            break;
        }
    }


}

