#ifndef TICTACTOE_PLAYER
#define TICTACTOE_PLAYER

#define pass (void)0
#include <iostream>
#include "TicTacToe.hpp"
#include <vector>

using namespace std;


class Player{
protected:
    char letter;
    TicTacToe newBoard = TicTacToe();

public:
    Player(char letter){
        this->letter = letter;
    }

    char getLetter(){
        return this->letter;
    }

    void getMove(int board[][3]){
        pass;
    }
};

class Human_Player : public Player{
public:
    Human_Player(char letter) : Player(letter) {}

    void getMove(){
        int position;
        vector<int> avail_move;
        cout << "Human (" <<this->letter<<")'s turn, please enter position (0-9): ";
        cin >> position;


    }
};

#endif