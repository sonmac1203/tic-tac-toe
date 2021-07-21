#include <iostream>
#include "TicTacToe.hpp"

class Player{
private:
    char letter;

public:
    Player(int status){
        if (status == 1){ // human
            this->letter = 'X';
        }
        else if (status == -1){ // computer
            this->letter = 'O';
        }
    }

    char getLetter(){
        return this->letter;
    }
};

class Human_Player : public Player{
public:
    Human_Player(int status) : Player(status) {}
};